CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
PROJECT( LoginService )

# Variables
#=========================
SET( LOGINSERVICE_VERSION_MAJOR 0 )
SET( LOGINSERVICE_VERSION_MINOR 1 )
SET( LOGINSERVICE_VERSION_BUILD 0 )
SET( LOGINSERVICE_VERSION "${LOGINSERVICE_VERSION_MAJOR}.${LOGINSERVICE_VERSION_MINOR}.${LOGINSERVICE_VERSION_BUILD}" )

# Options
#=========================
OPTION( BUILD_TESTS "Build the LOGINSERVICE test library." OFF )
OPTION( BUILD_EXAMPLES "Build the LOGINSERVICE example projects." OFF )

# Find/Build Dependencies
#=========================
INCLUDE( build/cmake/GetDependencies.cmake )

# Configure Build
#=========================
CONFIGURE_FILE(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
 )

# Execute Subdirectories
#=========================
ADD_SUBDIRECTORY( src )

IF( BUILD_TESTS )
 ADD_SUBDIRECTORY( tests )
ENDIF( BUILD_TESTS )

IF( BUILD_EXAMPLES )
  ADD_SUBDIRECTORY( example )
ENDIF( BUILD_EXAMPLES )