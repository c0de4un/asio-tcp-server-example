# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

if ( NOT DEFINED HEX_CMAKE_VERSION )
    set( HEX_CMAKE_VERSION 3.22.1 )
endif ( NOT DEFINED HEX_CMAKE_VERSION )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( APP_PROJECT_NAME "helloAsio" )
set( APP_VERSION 1.0.0 )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# DIRS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( LIBS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
