#pragma once

#include <variant>

#include "assets_fwd.hpp"

namespace assets {

    class Ok {};

    enum class EPreloadEntriesError {
        UNKNOWN
    };

    enum class EReloadEntriesError {
        UNKNOWN
    };

    enum class EUnloadEntriesError {
        UNKNOWN
    };

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class Manager {
    public:
        // valitation
        bool is_valid_asset(const Id& id);
        bool is_valid_asset(const Path& path);

        // conversion
        Path as_asset_path(const Id& id) const;
        Id as_asset_id(const Path& path) const;

        // entries loading/unloading
        std::variant<Ok, EPreloadEntriesError> preload_entries(const Id& asset);
        std::variant<Ok, EPreloadEntriesError> preload_entries(const Path& asset);

        std::variant<Ok, EReloadEntriesError> reload_entries(const Id& asset);
        std::variant<Ok, EReloadEntriesError> reload_entries(const Path& asset);

        std::variant<Ok, EUnloadEntriesError> unload_entries(const Id& asset);
        std::variant<Ok, EUnloadEntriesError> unload_entries(const Path& asset);
        void unload_unused_entries();

        // entries access
        template <typename ENTRY>
        std::variant<Entry<ENTRY>, EGetEntryError> entry(const Id& asset);
        template <typename ENTRY>
        std::variant<Entry<ENTRY>, EGetEntryError> entry(const Path& asset);

    }; // class Manager

} // namespace assets