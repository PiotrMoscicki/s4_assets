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

        // valitation
        
        bool is_valid_asset(const RefBase& ref);

        // conversion
        template <typename T>
        std::variant<Path<T>, EConversionError> as_asset_path(const Id<T>& id) const;
        template <typename T>
        std::variant<Id<T>, EConversionError> as_asset_id(const Path<T>& path) const;

        // entries loading/unloading
        std::variant<Ok, EPreloadEntriesError> load_asset(const RefBase& ref);
        std::variant<Ok, EReloadEntriesError> reload_asset(const RefBase& ref);
        std::variant<Ok, EUnloadEntriesError> unload_asset(const RefBase& ref);
        void unload_unused_assets();

        // entries access
        template <typename T>
        std::variant<std::shared_ptr<T>, EGetAssetError> get(const Ref<T>& ref);

    protected:
        std::shared_ptr<fs::IFilesystem> m_filesystem;
        std::shared_ptr<sr::ISerializer> m_serializer;

    }; // class Manager

} // namespace assets