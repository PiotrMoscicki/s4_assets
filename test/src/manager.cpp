#include <catch2/catch_test_macros.hpp>

#include <assets/assets.hpp>

namespace assets_test {

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class Filesystem {

    }; // class Filesystem

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class Serializer {

    }; // class Serializer

    //*********************************************************************************************
    assets::Manager create_test_manager() {
        auto filesystem = std::amke_shared();
    }

} // namespace assets_test

using namespace assets;
using namespace assets_test;

//*************************************************************************************************
TEST_CASE( "Is valid asset", "[Manager]" ) {
    Filesystem filesystem;
    Serialozer serializer;
    AssetsManagerBuilder manBuilder;
    manBuilder.set_filesystem(&filesystem);
    manBuilder.set_serializer(&serializer);
    AssetsManager man = manBuilder.construct;
    
    REQUIRE( man.root().name() == "/" );
}