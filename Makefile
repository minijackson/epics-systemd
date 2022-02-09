# Makefile at top of application tree
TOP = .
include $(TOP)/configure/CONFIG

# Directories to build, any order
DIRS += configure
DIRS += src
DIRS += epicsSystemdExampleApp
DIRS += iocBoot

# The build order is controlled by these dependency rules:

src_DEPEND_DIRS += configure
epicsSystemdExampleApp_DEPEND_DIRS += src
iocBoot_DEPEND_DIRS += epicsSystemdExampleApp

# Add any additional dependency rules here:

include $(TOP)/configure/RULES_TOP
