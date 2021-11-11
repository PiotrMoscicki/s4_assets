#pragma once

namespace fs {

    class Path {
        const std::string& path() const;
        std::string name() const;
        std::string ext() const;

    }; // class Path

    class IFilesystem {
    public:
        Path root() const;
        Path parent() const;
        size_t children_count() const;
        Path child(const Path& path, size_t idx) const;

        bool is_dir(const Path& path) const;
        bool is_file(const Path& path) const;

        Path add(const Path& parent, const std::string& relative_path);
        

    }; // class IFilesystem

} // namespace fs