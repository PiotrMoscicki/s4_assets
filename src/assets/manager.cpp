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
bool Manager::is_valid(const RefBase& ref) const {
    if (ref.is_id())
        return is_valid(ref.id());
    else
        return is(valid(ref.path()));
}

//*************************************************************************************************
bool Manager::is_valid(const IdBase& id) const {
    return m_ids.find(id) != m_ids.end();
}

//*************************************************************************************************
bool Manager::is_valid(const PathBase&) const {
    return m_paths.find(id) != m_paths.end();;
}

//*************************************************************************************************
void Manager::discover_assets() const {
    
}