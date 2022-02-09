TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = epicsSystemdExample
# epicsSystemdExample.dbd will be created and installed
DBD += epicsSystemdExample.dbd

# epicsSystemdExample.dbd will be made up from these files:
epicsSystemdExample_DBD += base.dbd

# Include dbd files from all support applications:
epicsSystemdExample_DBD += epicsSystemd.dbd

# Add all the support libraries needed by this IOC
epicsSystemdExample_LIBS += epicsSystemd

# epicsSystemdExample_registerRecordDeviceDriver.cpp derives from epicsSystemdExample.dbd
epicsSystemdExample_SRCS += epicsSystemdExample_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
epicsSystemdExample_SRCS_DEFAULT += epicsSystemdExampleMain.cpp
epicsSystemdExample_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#epicsSystemdExample_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
epicsSystemdExample_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

