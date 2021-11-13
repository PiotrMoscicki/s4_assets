#include <catch2/catch_test_macros.hpp>

#include <assets/assets.hpp>

#include <assets/ifilesystem.hpp>
#include <assets/iserializer.hpp>

#include <iostream>

namespace assets_test {

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class Filesystem : public fs::IFilesystem {

    }; // class Filesystem

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class Serializer : public sr::ISerializer {

    }; // class Serializer

    //*********************************************************************************************
    std::shared_ptr<assets::Manager> create_test_manager() {
        auto filesystem = static_pointer_cast<fs::IFilesystem>(std::make_shared<Filesystem>());
        auto serializer = static_pointer_cast<sr::ISerializer>(std::make_shared<Serializer>());
        auto manager = std::make_shared<assets::Manager>(std::move(filesystem)
            , std::move(serializer));
        return manager;
    }

    class Asset {

    };

    class EntityPrefabAsset : public Asset {

    };

} // namespace assets_test

using namespace assets_test;

const uuids::uuid VALID_ID
        = uuids::uuid::from_string("47183823-2574-4bfd-b411-99ed177d3e43").value();
const uuids::uuid INVALID_ID
        = uuids::uuid::from_string("b79f7a09-8947-4a50-bd80-15c69d5f17c6").value();
const std::string VALID_PATH = "/game/prefabs/prefab_1";
const std::string INVALID_PATH = "/game/prefabs/prefab_2";

//*************************************************************************************************
TEST_CASE( "Ref, Id, Path conversions", "[assets]" ) {
    assets::Ref<EntityPrefabAsset> ref;
    assets::Id<EntityPrefabAsset> id;
    assets::Path<EntityPrefabAsset> path;

    REQUIRE( ref.is_id() == true );
    REQUIRE( ref.is_path() == false );
    REQUIRE( ref.id().is_nil() == true );
    id = ref.id();
    REQUIRE( id.id().is_nil() == true );

    ref = assets::Path<EntityPrefabAsset>(VALID_PATH);
    REQUIRE( ref.is_id() == false );
    REQUIRE( ref.is_path() == true );
    REQUIRE( ref.path() == VALID_PATH );
    path = ref.path();
    REQUIRE( path.path() == VALID_PATH );

    ref = assets::Id<EntityPrefabAsset>(VALID_ID);
    REQUIRE( ref.is_id() == true );
    REQUIRE( ref.is_path() == false );
    REQUIRE( ref.id() == VALID_ID );
    id = ref.id();
    REQUIRE( id.id() == VALID_ID );

    path = INVALID_PATH;
    ref = path;
    REQUIRE( ref.is_id() == false );
    REQUIRE( ref.is_path() == true );
    REQUIRE( ref.path() == INVALID_PATH );

    id = INVALID_ID;
    ref = id;
    REQUIRE( ref.is_id() == true );
    REQUIRE( ref.is_path() == false );
    REQUIRE( ref.id() == INVALID_ID );
}

//*************************************************************************************************
TEST_CASE( "Is valid asset", "[Manager]" ) {
    std::shared_ptr<assets::Manager> man = create_test_manager();
    man->discover_assets();
    assets::Ref<EntityPrefabAsset> valid_ref = assets::Path<EntityPrefabAsset>(VALID_PATH);
    assets::Ref<EntityPrefabAsset> invalid_ref = assets::Id<EntityPrefabAsset>(INVALID_ID);
    assets::Id<EntityPrefabAsset> valid_id = VALID_ID;
    assets::Id<EntityPrefabAsset> invalid_id = INVALID_ID;
    assets::Path<EntityPrefabAsset> valid_path = VALID_PATH;
    assets::Path<EntityPrefabAsset> invalid_path = INVALID_PATH;

    REQUIRE( man->is_valid(valid_id) == true );
    REQUIRE( man->is_valid(invalid_id) == false );
    // REQUIRE( man.root().name() == "/" );
}