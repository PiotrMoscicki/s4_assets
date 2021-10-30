#pragma once

#include <memory>

#include "assets_fwd.hpp"

namespace fs {

    class IFilesystem {

    }; // class IFilesystem

} // namespace fs

namespace sr {

    class ISerializer {

    }; // class ISerializer

} // namespace sr

namespace assets {

    class EditorManager;

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class ManagerBuilder {
    public:
        void set_filesystem(sta::shared_ptr<fs::IFilesystem> filesystem);
        void set_serializer(sta::shared_ptr<sr::ISerializer> serializer);

        Manager build_manager();
        EditorManager build_editor_manager();
        
    }; // class ManagerBuilder

} // namespace assets