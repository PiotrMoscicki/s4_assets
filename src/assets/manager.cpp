#include "manager.hpp"

using namespace assets;

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************
Manager::Manager(std::shared_ptr<fs::IFilesystem> filesystem
    , std::shared_ptr<sr::ISerializer> serializer) 
    : m_filesystem(std::move(filesystem)), m_serializer(std::move(serializer))
{

}

//*************************************************************************************************
bool Manager::is_valid_asset(const RefBase&) {
    return true;
}