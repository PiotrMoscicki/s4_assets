#include "node.hpp"

using namespace assets;

//*************************************************************************************************
Node::Node(std::string path) 
    : m_identifier_type(EIdentifierType::PATH),
    , m_path_identifier(std::move(path))
{
}

//*************************************************************************************************
Node::Node(uuids::uuid uuid) 
    : m_identifier_type(EIdentifierType::UUID),
    , m_uuid_identifier(std::move(uuid))
{
}

//*************************************************************************************************
void Node::set_identifier(std::string path) {
    m_identifier_type = EIdentifierType::PATH;
    m_uuid_identifier = {};
    m_path_identifier = std::move(path);
}

//*************************************************************************************************
void Node::set_identifier(uuids::uuid uuid) {
    m_identifier_type = EIdentifierType::UUID;
    m_path_identifier = {};
    m_uuid_identifier = std::move(uuid);
}