#pragma once

#include <variant>
#include <memory>
#include <map>

#include "assets_fwd.hpp"

#include "ifilesystem.hpp"
#include "iserializer.hpp"

namespace assets {

    class Ok {};

    enum class EConversionError {
        UNKNOWN
    };

    enum class ERelativePathConversionError {
        UNKNOWN
    };

    enum class ELoadAssetError {
        UNKNOWN
    };

    enum class EReloadAssetError {
        UNKNOWN
    };

    enum class EUnloadAssetError {
        UNKNOWN
    };

    enum class EGetAssetError {
        UNKNOWN
    };

    class Asset {

    };

    class Meta {

    };

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class Manager {
    public:
        Manager(std::shared_ptr<fs::IFilesystem> filesystem
            , std::shared_ptr<sr::ISerializer> serializer);

        // validation
        bool is_valid(const RefBase& ref) const;

        // conversion
        template <typename T>
        std::variant<Path<T>, EConversionError> as_path(const Id<T>& id) const;
        template <typename T>
        std::variant<Id<T>, EConversionError> as_id(const Path<T>& path) const;

        template <typename T>
        std::variant<Path<T>, ERelativePathConversionError> as_path(const RefBase& parent
            , const RelPath<T>& ref_path) const;
        template <typename T>
        std::variant<Id<T>, ERelativePathConversionError> as_id(const RefBase& parent
            , const RelPath<T>& ref_path) const;

        // assets discovering/loading/unloading
        void discover_assets();
        std::variant<Ok, ELoadAssetError> load(const RefBase& ref);
        std::variant<Ok, EReloadAssetError> reload(const RefBase& ref);
        std::variant<Ok, EUnloadAssetError> unload(const RefBase& ref);
        void unload_unused();

        // entries access
        template <typename T>
        std::variant<std::shared_ptr<T>, EGetAssetError> get(const Ref<T>& ref) const;

    protected:
        bool is_valid(const uuids::uuid& id) const;
        bool is_valid(const std::string& path) const;
        void discover_assets(const fs::Path& path);
        void load_meta(const fs::Path& asset);

        std::shared_ptr<fs::IFilesystem> m_filesystem;
        std::shared_ptr<sr::ISerializer> m_serializer;

        std::map<uuids::uuid, Meta> m_id_to_meta;
        std::map<std::string, Meta> m_path_to_meta
        std::map<uuids::uuid, std::shared_ptr<Asset>> m_id_to_asset;
        std::map<std::string, std::shared_ptr<Asset>> m_path_to_asset;

    }; // class Manager

} // namespace assets