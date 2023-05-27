# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# ASSERTIONS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

if ( NOT DEFINED SERVER_VERSION )
    message( FATAL_ERROR "Server.Windows - parent CMakeLists not included" )
endif ( NOT DEFINED SERVER_VERSION )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

project( "Server.Windows" VERSION ${SERVER_VERSION} LANGUAGES C CXX )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( SERVER_WIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}" )
set( SERVER_WIN_INCLUDE_DIR "${SERVER_WIN_DIR}/public" )
set( SERVER_WIN_PUBLIC_DIR "${SERVER_WIN_DIR}/public/app/server/windows/" )
set( SERVER_WIN_PRIVATE_DIR "${SERVER_WIN_DIR}/private/app/server/windows/" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( SERVER_WIN_HEADERS
    "${SERVER_WIN_PUBLIC_DIR}main.hpp"
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( SERVER_WIN_SOURCES
    "${SERVER_WIN_PRIVATE_DIR}main.cpp"
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# DEPENDENCIES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Application.Core

# Application.Server.Core

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Add Executable Object
add_executable( server ${SERVER_WIN_HEADERS} ${SERVER_WIN_SOURCES} )

# Configure Executable
set_target_properties( server PROPERTIES
    OUTPUT_NAME "server v${SERVER_VERSION}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

# Include Application.Server.Windows Headers for include-navigation
target_include_directories( server PRIVATE ${SERVER_WIN_INCLUDE_DIR} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# LINK
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Application.Core

# Application.Server.Core
target_link_libraries( server server_core )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
