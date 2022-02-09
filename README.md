epics-systemd
=============

Systemd-related facilities for EPICS IOCs.

Currently, epics-systemd allows you to send notification to the systemd service
manager. What this means, is that if you distribute your IOC as a systemd
service, simply set `Type=notify` in your `ioc.service` file and add the
`epicsSystemd.dbd` DBD and `epicsSystemd` LIB to your App. This will
automatically notify systemd of when your IOC is properly booted and ready to
engage communication with.

Note that if the service is not launched through systemd, this effectively does
nothing.

This is useful if you have other programs which need to wait for the IOC to be
ready. For example, in an integration test, we might want to boot a machine
with the given IOC, and try to get / set PVs to see if it is working properly.

With epics-systemd, we can simply order another testing systemd service after
the ioc:

```ini
[Unit]
Wants=ioc.service
After=ioc.service

[Service]
# Will immediately do some caget / caput or other
ExecStart=/path/to/my/testing.script
Type=oneshot
```
