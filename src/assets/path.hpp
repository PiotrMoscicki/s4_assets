#pragma once

#include "assets_fwd.hpp"
#include "node.hpp"

namespace assets {

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class Path : public Node {
    public:
        Path() = default;
        Path(std::string path) : Node(std::move(path)) {}

    }; // class Path

} // namespace assets