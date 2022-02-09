#include "epicsSystemd.h"

#include <string.h>

#include <systemd/sd-daemon.h>

#include <epicsExport.h>
#include <errlog.h>
#include <initHooks.h>
#include <iocsh.h>

// Definitions

void epicsSystemdNotify(char const* state)
{
	int ret = sd_notify(/* unset_environment = */ 0, state);
	if (ret < 0) {
		char const* errMessage = strerror(-ret);
		errlogSevPrintf(errlogMinor, "could not send systemd notification: %s\n", errMessage);
	}
}

static void epicsSystemdNotifyFunc(iocshArgBuf const* args)
{
	epicsSystemdNotify(args[0].sval);
}

void epicsSystemdNotifyReady(void)
{
	errlogPrintf("epics-systemd: notifying ready\n");
	epicsSystemdNotify("READY=1");
}

static void epicsSystemdNotifyReadyFunc(iocshArgBuf const* _args)
{
	epicsSystemdNotifyReady();
}

void epicsSystemdNotifyReloading(void)
{
	epicsSystemdNotify("RELOADING=1");
}

static void epicsSystemdNotifyReloadingFunc(iocshArgBuf const* _args)
{
	epicsSystemdNotifyReloading();
}

void epicsSystemdNotifyStopping(void)
{
	epicsSystemdNotify("STOPPING=1");
}

static void epicsSystemdNotifyStoppingFunc(iocshArgBuf const* _args)
{
	epicsSystemdNotifyStopping();
}

// EPICS registration stuff

static void hookHandler(initHookState const state)
{
	switch (state) {
		case initHookAfterIocRunning:
			epicsSystemdNotifyReady();
			break;
		default:
			break;
	}
}

static iocshArg const epicsSystemdNotifyArg0 = {"state", iocshArgString};
static iocshArg const* const epicsSystemdNotifyArgs[] = {&epicsSystemdNotifyArg0};
static iocshFuncDef const epicsSystemdNotifyDef = {
  "systemdNotify",
  1,
  epicsSystemdNotifyArgs,
  "Notify the systemd service manager about service status changes.\n\n"
  "See sd_notify(3) for usage information.\n",
};

static iocshFuncDef const epicsSystemdNotifyReadyDef = {
  "systemdNotifyReady",
  0,
  NULL,
  "Tells the systemd service manager that service startup is finished.\n\n"
  "This should be used with a Type=notify systemd service.\n",
};

static iocshFuncDef const epicsSystemdNotifyReloadingDef = {
  "systemdNotifyReloading",
  0,
  NULL,
  "Tells the systemd service manager that service is reloading its configuration.\n\n"
  "This should call systemdNotifyReady once it completed reloading its configuration.\n",
};

static iocshFuncDef const epicsSystemdNotifyStoppingDef = {
  "systemdNotifyStopping",
  0,
  NULL,
  "Tells the systemd service manager that service is beginning its shutdown.\n",
};

static void epicsSystemdRegistrar(void)
{
	iocshRegister(&epicsSystemdNotifyDef, epicsSystemdNotifyFunc);
	iocshRegister(&epicsSystemdNotifyReadyDef, epicsSystemdNotifyReadyFunc);
	iocshRegister(&epicsSystemdNotifyReloadingDef, epicsSystemdNotifyReloadingFunc);
	iocshRegister(&epicsSystemdNotifyStoppingDef, epicsSystemdNotifyStoppingFunc);
	initHookRegister(&hookHandler);
}

epicsExportRegistrar(epicsSystemdRegistrar);
