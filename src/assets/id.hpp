#pragma once

#include "assets_fwd.hpp"
#include "node.hpp"

namespace assets {

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class Id : public Node {
    public:
        Id() = default;
        Id(uuids::uuid uuid) : Node(std::move(uuid)) {}

    }; // class Id

} // namespace assets