#pragma once

#include <optional>

#include "manager.hpp"

namespace assets {

    class Ok {};

    enum class ERenameError {
        UNKNOWN
    };

    enum class EMoveError {
        UNKNOWN
    };

    enum class ERemoveError {
        UNKNOWN
    };

    enum class ECreateDirError {
        UNKNOWN
    };

    enum class ECreateAssetError {
        UNKNOWN
    };

    enum class EGetEntryError {
        UNKNOWN
    };

    enum class ESetEntryError {
        UNKNOWN
    };

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class EditorManager : public Manager {
    public:
        // valitation
        bool is_valid_node(const Node& node);
        bool is_valid_dir(const Dir& dir);

        // basic accessors 
        Node root() const;
        Node parent(const Node& node) const;
        std::string name(const Node& node) const;
        size_t children_count(const Node& node) const;
        Node child(const Node& node, size_t index) const;

        // conversion
        std::optional<Dir> as_dir(const Node& node) const;
        std::optional<Path> as_asset_path(const Node& node) const;
        std::optional<Id> as_asset_id(const Node& node) const;

        // operations on nodes
        std::variant<Ok, ERenameError> rename(Node& node, std::string name);
        std::variant<Ok, EMoveError> move(Node& node, const Node& dst);
        std::variant<Ok, ERemoveError> remove(Node& node);

        // dir operations
        std::variant<Dir, ECreateDirError> create_dir(const Dir& dir, std::string name);

        // asset operations
        std::variant<Id, ECreateAssetError> create_asset(const Dir dir, std::string name);

        // entries modifications
        template <typename ENTRY>
        std::variant<Ok, ESetEntryError> set_entry(const Id& asset, ENTRY entry);
        template <typename ENTRY>
        std::variant<Ok, ESetEntryError> set_entry(const Path& asset, ENTRY entry);

    }; // class Manager

} // namespace assets