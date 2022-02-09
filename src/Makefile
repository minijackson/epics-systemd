TOP = ..
include $(TOP)/configure/CONFIG

LIBRARY = epicsSystemd

INC += epicsSystemd.h

epicsSystemd_SRCS += epicsSystemd.c

epicsSystemd_CFLAGS += `pkg-config --cflags libsystemd`
epicsSystemd_LDFLAGS += `pkg-config --libs libsystemd`

DBD += epicsSystemd.dbd

include $(TOP)/configure/RULES
