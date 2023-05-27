# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Boost
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( BOOST_DIR "${LIBS_DIR}boost" )

set( BOOST_INCLUDE_DIR "${BOOST_DIR}/include" )
if ( EXISTS "${BOOST_INCLUDE_DIR}/boost/asio.hpp" )
    message( STATUS "${PROJECT_NAME} - Boost includes found at ${BOOST_INCLUDE_DIR}" )
else ( EXISTS "${BOOST_INCLUDE_DIR}/boost/asio.hpp" )
    message( FATAL_ERROR "${PROJECT_NAME} - Boost includes not found at ${BOOST_INCLUDE_DIR}" )
endif ( EXISTS "${BOOST_INCLUDE_DIR}/boost/asio.hpp" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
