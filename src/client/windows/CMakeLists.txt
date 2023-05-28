# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# ASSERTIONS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

if ( NOT DEFINED CLIENT_VERSION )
    message( FATAL_ERROR "Client.Windows - parent CMakeLists not included" )
endif ( NOT DEFINED CLIENT_VERSION )

if ( NOT DEFINED BOOST_INCLUDE_DIR )
    message( FATAL_ERROR "Client.Windows - <BOOST_INCLUDE_DIR> if not defined" )
endif ( NOT DEFINED BOOST_INCLUDE_DIR )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

project( "Client.Windows" VERSION ${CLIENT_VERSION} LANGUAGES C CXX )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( CLIENT_WIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}" )
set( CLIENT_WIN_INCLUDE_DIR "${CLIENT_WIN_DIR}/public" )
set( CLIENT_WIN_PUBLIC_DIR "${CLIENT_WIN_DIR}/public/app/client/windows/" )
set( CLIENT_WIN_PRIVATE_DIR "${CLIENT_WIN_DIR}/private/app/client/windows/" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( CLIENT_WIN_HEADERS
    "${CLIENT_WIN_PUBLIC_DIR}asio.hpp"
    "${CLIENT_WIN_PUBLIC_DIR}main.hpp"
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( CLIENT_WIN_SOURCES
    "${CLIENT_WIN_PRIVATE_DIR}main.cpp"
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# DEPENDENCIES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Application.Core

# Application.Client.Core

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Add Executable Object
add_executable( client ${CLIENT_WIN_HEADERS} ${CLIENT_WIN_SOURCES} )

# Configure Executable
set_target_properties( client PROPERTIES
    OUTPUT_NAME "client v${CLIENT_VERSION}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

# Enable exceptions
message( STATUS "${PROJECT_NAME} - C++ Compiler is ${CMAKE_CXX_COMPILER_ID}" )
if ( CMAKE_CXX_COMPILER_ID STREQUAL "Clang" )
    target_compile_options( client PUBLIC -fexceptions )
endif ( CMAKE_CXX_COMPILER_ID STREQUAL "Clang" )

# Include Application.Client.Windows Headers for include-navigation
target_include_directories( client PRIVATE ${CLIENT_WIN_INCLUDE_DIR} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# LINK
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Boost.ASIO
target_include_directories( client PRIVATE ${BOOST_INCLUDE_DIR} )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
