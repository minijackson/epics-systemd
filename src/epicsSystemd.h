#pragma once

/*
 * Notify the systemd service manager about service status changes.
 *
 * See `sd_notify(3)` for usage information.
 */
void epicsSystemdNotify(char const* state);

/*
 * Tells the systemd service manager that service startup is finished.
 *
 * This should be used with a `Type=notify` systemd service.
 */
void epicsSystemdNotifyReady(void);

/*
 * Tells the systemd service manager that service is reloading its
 * configuration.
 *
 * This should call systemdNotifyReady once it completed reloading its
 * configuration.
 */
void epicsSystemdNotifyReloading(void);

/*
 * Tells the systemd service manager that service is beginning its shutdown.
 */
void epicsSystemdNotifyStopping(void);
