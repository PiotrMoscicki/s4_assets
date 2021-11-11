#pragma once

#include <variant>
#include <memory>

#include "assets_fwd.hpp"

#include "ifilesystem.hpp"
#include "iserializer.hpp"

namespace assets {

    class Ok {};

    enum class EConversionError {
        UNKNOWN
    };

    enum class EPreloadEntriesError {
        UNKNOWN
    };

    enum class EReloadEntriesError {
        UNKNOWN
    };

    enum class EUnloadEntriesError {
        UNKNOWN
    };

    enum class EGetAssetError {
        UNKNOWN
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
        bool is_valid(const IdBase& id) const;
        bool is_valid(const PathBase& path) const;

        // conversion
        template <typename T>
        std::variant<Path<T>, EConversionError> as_path(const Id<T>& id) const;
        template <typename T>
        std::variant<Id<T>, EConversionError> as_id(const Path<T>& path) const;

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

        std::shared_ptr<fs::IFilesystem> m_filesystem;
        std::shared_ptr<sr::ISerializer> m_serializer;

        std::map<uuids::uuid, std::shared_ptr<Asset>> m_ids;
        std::map<std::string, std::shared_ptr<Asset>> m_paths;

    }; // class Manager

} // namespace assets