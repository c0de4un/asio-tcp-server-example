# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

include( "cmake/constants.cmake" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# CMake Version
cmake_minimum_required( VERSION ${HEX_CMAKE_VERSION} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

project( ${APP_PROJECT_NAME} VERSION ${APP_VERSION} LANGUAGES C CXX )

# Enable Position Independent Code
set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )
set( CMAKE_POSITION_INDEPENDENT_CODE ON )

# C++ Version
set ( CMAKE_CXX_STANDARD ${HEX_CXX_VERSION} )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_AUTOUIC ON )
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTORCC ON )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONFIGS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

include( "${CMAKE_CURRENT_SOURCE_DIR}/cmake/platform.cmake" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# FIND LIBRARIES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

include( "${CMAKE_CURRENT_SOURCE_DIR}/cmake/find_libs.cmake" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# MODULES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Application

# Application.Server
add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/src/server" )

# Application.Client
add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/src/client" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
