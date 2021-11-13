#pragma once

namespace fs {

    class Path {
        const std::string& path() const;
        std::string name() const;
        std::string ext() const;

    }; // class Path

    class IFilesystem {
    public:
        virtual Path root() const;
        virtual Path parent() const;
        virtual size_t children_count() const;
        virtual Path child(const Path& path, size_t idx) const;

        virtual bool is_dir(const Path& path) const;
        virtual bool is_file(const Path& path) const;

        virtual Path add(const Path& parent, const std::string& relative_path);
        virtual void remove(const Path& path);
        virtual Path rename(const Path& path, const std::string& new_name);
        virtual Path move(const Path& path, const Path& new_parent);

        virtual rtti::Buffer read(const Path& path) const;
        virtual bool write(const Path& path, const rtti::Buffer& buf) const;

    }; // class IFilesystem

} // namespace fs