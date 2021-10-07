#pragma once

#include <filesystem>
#include <fstream>
#include <memory>

#include "runtime_array.hpp"

namespace astra::io {
    std::shared_ptr<astra::mem::runtime_array<uint8_t>> read_file(const std::filesystem::path &path) {
        std::ifstream file(path, std::ios::binary | std::ios::in);
        auto size = static_cast<size_t>(std::filesystem::file_size(path));
        auto bytes = std::make_shared<astra::mem::runtime_array<uint8_t>>(nullptr, size);
        file.seekg(0, std::ios::beg);
        file.read(reinterpret_cast<char *>(bytes->data()), static_cast<std::streamsize>(size));
        file.close();
        return bytes;
    }

    void write_file(const std::filesystem::path &path, std::shared_ptr<astra::mem::runtime_array<uint8_t>> &buffer) {
        std::ofstream file(path, std::ios::binary | std::ios::out | std::ios::trunc);
        file.write(reinterpret_cast<const char *>(buffer->data()), static_cast<std::streamsize>(buffer->size()));
        file.flush();
        file.close();
    }

    inline void align(uintptr_t &value, uintptr_t align) {
        auto v = value % align;
        if (v != 0) {
            value += align - v;
        }
    }
} // namespace astra::io
