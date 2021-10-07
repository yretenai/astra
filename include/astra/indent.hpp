#pragma once

#include <cstdint>
#include <istream>
#include <ostream>
#include <string>

namespace astra::io {
    class indent {
    private:
        uint64_t level = 0;

    public:
        std::string text;

        explicit indent(size_t l) : level(l > 0 ? l : 0), text(level * 2, ' ') {}

        indent operator+(const uint64_t &v) const { return indent(level + v); }

        indent operator-(const uint64_t &v) const { return indent(level - v); }

        indent operator+=(const uint64_t &v) {
            level += v;
            text = std::string(level * 2, ' ');
            return *this;
        }

        indent operator-=(const uint64_t &v) {
            if (v > level)
                level = 0;
            else
                level -= v;
            text = std::string(level * 2, ' ');
            return *this;
        }

        indent &operator=(const uint64_t &v) {
            level = v;
            text = std::string(level * 2, ' ');
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &os, const indent &i) {
            os << i.text;
            return os;
        }
    };
} // namespace astra::io
