#!../../bin/linux-x86_64/epicsSystemdExample

< envPaths

## Register all support components
dbLoadDatabase("../../dbd/epicsSystemdExample.dbd",0,0)
epicsSystemdExample_registerRecordDeviceDriver(pdbbase) 

## Load record instances
#dbLoadRecords("../../db/epicsSystemdExample.db")

iocInit()

# Notify systemd that we are ready
systemdNotifyReady()
