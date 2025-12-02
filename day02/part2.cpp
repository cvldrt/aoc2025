#include <numeric>
#include <unordered_set>

#include "../utils.cpp"

u64 repeat(u64 num, u64 n)
{
    u64 res = 0;

    for (int i = 0; i < n; ++i) {
        res *= std::pow(10, digit_length(num));
        res += num;
    }

    return res;
}

int main()
{
    auto input = load("input.txt");

    auto ranges = split(input[0], ',');

    u64 res = 0;

    for (auto& range : ranges) {
        auto dash_pos = range.find('-');

        u64 from = atoll(range.substr(0, dash_pos).c_str());
        u64 to   = atoll(range.substr(dash_pos + 1).c_str());

        u64 min_digits = digit_length(from);
        u64 max_digits = digit_length(to);

        std::unordered_set<u64> results;

        for (u64 digits = min_digits; digits <= max_digits; ++digits) {
            for (u64 part_len = 1; part_len <= (digits / 2); ++part_len) {
                if (digits % part_len != 0) continue;

                for (u64 part = std::pow(10, part_len - 1);
                     part < std::pow(10, part_len); ++part) {
                    u64 invalid = repeat(part, digits / part_len);

                    if (invalid >= from && invalid <= to) {
                        results.insert(invalid);
                    }
                }
            }
        }

        res += std::accumulate(results.begin(), results.end(), (u64) 0);
    }

    P(res);
}
