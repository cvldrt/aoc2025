#include "../utils.cpp"

int main()
{
    auto input = load("input.txt");

    std::vector<std::pair<i64, i64>> coors;

    for (auto& line : input) {
        size_t del_pos = line.find(',');
        coors.emplace_back(atoll(line.substr(0, del_pos).c_str()),
                           atoll(line.substr(del_pos + 1).c_str()));
    }

    u64 max_size = 0;

    for (auto from : coors) {
        for (auto to : coors) {
            u64 size = (std::abs(to.first - from.first) + 1) *
                       (std::abs(to.second - from.second) + 1);
            max_size = size > max_size ? size : max_size;
        }
    }

    P(max_size);
}
