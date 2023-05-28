# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( SERVER_VERSION 1.0.0 )

project( "Server" VERSION ${SERVER_VERSION} LANGUAGES C CXX )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# ASSERTIONS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

if ( DEFINED PLATFORM )
    message( STATUS "${PROJECT_NAME} - target platform is ${PLATFORM}" )
else ( DEFINED PLATFORM )
    message( FATAL_ERROR "${PROJECT_NAME} - <PLATFORM> is not defined" )
endif ( DEFINED PLATFORM )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# DEPENDENCIES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Application.Core

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# MODULES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Core
add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/core" )

# Platform
add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM}" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
