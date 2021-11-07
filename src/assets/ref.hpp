#pragma once

#include <variant>

#include "id.hpp"
#include "path.hpp"

namespace assets {

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class RefBase : public Node {
    public:
        RefBase() = default;
        RefBase(IdBase id) : m_value(std::move(id)) {}
        RefBase(PathBase path) : m_value(std::move(path)) {}

        bool is_id() const { return std::holds_alternative<IdBase>(m_value); }
        bool is_path() const { return std::holds_alternative<PathBase>(m_value); }
        const uuids::uuid& id() const { return std::get<IdBase>(m_value).id(); }
        const std::string& path() const { return std::get<PathBase>(m_value).path(); }

    protected:
        std::variant<IdBase, PathBase> m_value;

    }; // class RefBase

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    template <typename T>
    class Ref : public RefBase {
    public:
        using RefBase::RefBase;

    }; // class Ref

} // namespace assets