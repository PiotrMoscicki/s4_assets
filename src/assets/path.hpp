#pragma once

#include "node.hpp"

namespace assets {

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class PathBase : public Node {
    public:
        PathBase() = default;
        PathBase(const char* path) : PathBase(std::string(path)) {}
        PathBase(std::string path) : m_path(std::move(path)) {}

        const std::string& path() const { return m_path; }

    protected:
        std::string m_path;

    }; // class PathBase

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    template <typename T>
    class Path : public PathBase {
    public:
        using PathBase::PathBase;

    }; // class Path

} // namespace assets