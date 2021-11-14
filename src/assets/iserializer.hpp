#pragma once

namespace sr {

    

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class ISerializer {
    public:
        rtti::Buffer serialize(const rtti::ObjectRef& obj) const;

        template <typename T>
        bool placement_deserialize(const rtti::Buffer& buf, T& dst) const;
        bool placement_deserialize(const rtti::Buffer& buf, rtti::ObjectRef& dst) const;
        rtti::Object deserialize(const rtti::Buffer& buf, const rtti::Type* type) const;

    }; // class ISerializer

} // namespace sr