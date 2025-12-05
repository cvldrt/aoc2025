#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>

#define P(param) std::cout << (param) << "\n"

typedef uint64_t u64;
typedef int64_t i64;

struct ranges {
    std::set<std::pair<u64, u64>> r;

    void add(u64 from, u64 to)
    {
        r.insert({from, to});
    }


    bool contains(u64 needle)
    {
        for (auto [from, to] : r) {
            if (needle >= from && needle <= to) return true;
        }

        return false;
    }

    void merge () {
        if (r.empty()) return;

        auto current = *r.begin();

        std::set<std::pair<u64, u64>> tmp;
        
        for (auto[from, to] : r) {
            if (current.second >= from) {
                current.second = std::max(current.second, to);
            } else {
                tmp.insert(current);
                current = {from, to};
            }
        }

        tmp.insert(current);

        r = tmp;
    }
};

void print_vec(auto vec, char delim = '\n')
{
    for (auto e : vec) {
        std::cout << e << delim;
    }

    std::cout << "\n";
}

std::vector<std::string> split(std::string& str, char ch)
{
    std::vector<std::string> res;

    std::stringstream stream(str);

    for (std::string line; getline(stream, line, ch);) {
        res.push_back(line);
    }

    return res;
}

std::vector<std::string> load(const std::string&& file_name)
{
    std::vector<std::string> res;

    std::fstream input(file_name);
    for (std::string line; getline(input, line);) {
        res.push_back(line);
    }

    return res;
}

u64 digit_length(auto num)
{
    if (num == 0) return 1;
    return trunc(log10(num)) + 1;
}

u64 count_around(auto& diagram, u64 x, u64 y, auto needle)
{
    u64 res = 0;

    for (int y_offset = -1; y_offset <= 1; ++y_offset) {
        for (int x_offset = -1; x_offset <= 1; ++x_offset) {
            if (y_offset == 0 && x_offset == 0) {
                continue;
            }

            if (y + y_offset < 0 || y + y_offset >= diagram.size() ||
                x + x_offset < 0 || x + x_offset >= diagram[y].size()) {
                continue;
            }

            if (diagram[y + y_offset][x + x_offset] == needle) {
                ++res;
            }
        }
    }

    return res;
}
