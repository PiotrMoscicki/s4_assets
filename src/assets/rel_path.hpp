#pragma once

#include "node.hpp"

namespace assets {

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class RelPathBase : public Node {
    public:
        RelPathBase() = default;
        RelPathBase(const char* rel_path) : RelPathBase(std::string(rel_path)) {}
        RelPathBase(std::string rel_path) : m_rel_path(std::move(rel_path)) {}

        const std::string& rel_path() const { return m_rel_path; }

    protected:
        std::string m_rel_path;

    }; // class RelPathBase

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    template <typename T>
    class RelPath : public RelPathBase {
    public:
        using RelPathBase::RelPathBase;

    }; // class RelPath

} // namespace assets