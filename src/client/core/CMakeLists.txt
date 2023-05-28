# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

project( "Client.Core" VERSION ${CLIENT_VERSION} LANGUAGES C CXX )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( CLIENT_CORE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" )
set( CLIENT_CORE_INCLUDE_DIR "${CLIENT_CORE_DIR}/public" )
set( CLIENT_CORE_PUBLIC_DIR "${CLIENT_CORE_DIR}/public/app/client/core/" )
set( CLIENT_CORE_PRIVATE_DIR "${CLIENT_CORE_DIR}/private/app/client/core/" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( CLIENT_CORE_HEADERS
    "${CLIENT_CORE_PUBLIC_DIR}IServerConnection.hxx"
    "${CLIENT_CORE_PUBLIC_DIR}ServerConnection.hpp"
    "${CLIENT_CORE_PUBLIC_DIR}Client.hpp"
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( CLIENT_CORE_SOURCES
    "${CLIENT_CORE_PRIVATE_DIR}ServerConnection.cpp"
    "${CLIENT_CORE_PRIVATE_DIR}Client.cpp"
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Add STATIC Library Object
add_library( client_core ${CLIENT_CORE_SOURCES} )

# Configure Library Object
set_target_properties( client_core PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
    INTERFACE_INCLUDE_DIRECTORIES ${CLIENT_CORE_INCLUDE_DIR}
)

# Include Application.Client.Core Headers for includes navigation
target_include_directories( client_core PRIVATE ${CLIENT_CORE_INCLUDE_DIR} )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
