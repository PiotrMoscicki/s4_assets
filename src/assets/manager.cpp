#include "manager.hpp"

#include "ref.hpp"

using namespace assets;

namespace {
    const char* META_FILE_EXT = "ext";
}

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
        return m_ids.find(ref.id()) != m_ids.end();
    else
        return m_paths.find(ref.path()) != m_paths.end();
}

//*************************************************************************************************
void Manager::discover_assets() {
    discover_assets(m_filesystem->root());
}

//*************************************************************************************************
void Manager::discover_assets(const fs::Path& path) {
    const size_t children_count = m_filesystem->children_count(path);
    for (int i = 0; i < children_count; ++i) {
        const Path child = m_filesystem->child(i);
        if (m_filesystem->is_dir(child))
            discover_assets(child);
        else if (m_filesystem->is_file(child) && child.ext() == META_FILE_EXT)
            load_meta(child);
    }
}

//*************************************************************************************************
void Manager::load_meta(const fs::Path& asset_path) {
    auto asset = std::make_shared<Asset>();
    if (m_serializer->placement_deserialize(m_filesystem->read(asset_path), asset->meta)) {
        m_ids.insert({ asset->meta.id, asset });
        m_paths.insert({ asset_path, asset });
    }
}