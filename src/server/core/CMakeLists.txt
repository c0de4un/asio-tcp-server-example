# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

project( "Server.Core" VERSION ${SERVER_VERSION} LANGUAGES C CXX )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( SERVER_CORE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" )
set( SERVER_CORE_INCLUDE_DIR "${SERVER_CORE_DIR}/public" )
set( SERVER_CORE_PUBLIC_DIR "${SERVER_CORE_DIR}/public/app/server/core/" )
set( SERVER_CORE_PRIVATE_DIR "${SERVER_CORE_DIR}/private/app/server/core/" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


set( SERVER_CORE_HEADERS
    "${SERVER_CORE_PUBLIC_DIR}Server.hpp"
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( SERVER_CORE_SOURCES
    "${SERVER_CORE_PRIVATE_DIR}Server.cpp"
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# DEPENDENCIES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Application.Core

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Add STATIC Library Object
add_library( server_core ${SERVER_CORE_SOURCES} )

# Configure Library Object
set_target_properties( server_core PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
    INTERFACE_INCLUDE_DIRECTORIES ${SERVER_CORE_INCLUDE_DIR}
)

# Include Application.Server.Core Headers for includes navigation
target_include_directories( server_core PRIVATE ${SERVER_CORE_INCLUDE_DIR} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# LINK
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Application.Core

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
