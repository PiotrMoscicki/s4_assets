#pragma once

#include <variant>
#include <string>
#include <uuid.h>

#include "assets_fwd.hpp"

namespace assets {

    enum class EIdentifierType {
        PATH,
        UUID
    }

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class Node {
    public:
        Node() = default;
        Node(std::string path);
        Node(uuids::uuid uuid);
        virtual ~Node() = default;

        EIdentifierType identifier_type() const { return m_identifier_type; }
        const std::string& path_identifier() const { return m_path_identifier; }
        const uuids::uuid& uuid_identifier() const { return m_uuid_identifier; }

    protected:
        void set_identifier(std::string path);
        void set_identifier(uuids::uuid uuid);

    private:
        EIdentifierType m_identifier_type = EIdentifierType::PATH;
        std::string m_path_identifier;
        uuids::uuid m_uuid_identifier;

    }; // class Node

} // namespace assets