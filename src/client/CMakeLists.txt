# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( CLIENT_VERSION 1.0.0 )

project( "Client" VERSION ${CLIENT_VERSION} LANGUAGES C CXX )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# ASSERTIONS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

if ( DEFINED PLATFORM )
    message( STATUS "${PROJECT_NAME} - target platform is ${PLATFORM}" )
else ( DEFINED PLATFORM )
    message( FATAL_ERROR "${PROJECT_NAME} - <PLATFORM> is not defined" )
endif ( DEFINED PLATFORM )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# MODULES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Platform
add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM}" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
