#include "../utils.cpp"

bool overlap(auto rc1, auto rc2, auto lc1, auto lc2)
{
    bool isToLeft =
        std::min(rc1.first, rc2.first) >= std::max(lc1.first, lc2.first);
    bool isToRight =
        std::max(rc1.first, rc2.first) <= std::min(lc1.first, lc2.first);
    bool isBelow =
        std::min(rc1.second, rc2.second) >= std::max(lc1.second, lc2.second);
    bool isAbove =
        std::max(rc1.second, rc2.second) <= std::min(lc1.second, lc2.second);

    return !(isToLeft || isToRight || isBelow || isAbove);
}

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

            bool disrupted = false;
            for (int i = 0; i < coors.size() - 1; ++i) {
                auto c1 = coors[i];
                auto c2 = coors[i + 1];

                if (overlap(from, to, c1, c2)) {
                    disrupted = true;
                    break;
                }
            }

            if (size > max_size && !disrupted) {
                max_size = size;
            }
        }
    }

    P(max_size);
}
