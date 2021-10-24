#include <catch2/catch_test_macros.hpp>

#include <uuid.h>

//*************************************************************************************************
TEST_CASE( "Math test", "[Asset]" ) {
    REQUIRE( 1 + 2 == 3 );
}

//*************************************************************************************************
TEST_CASE( "Uuid library test", "[Asset]" ) {
    uuids::uuid empty;
    REQUIRE( empty.is_nil() == true );
}