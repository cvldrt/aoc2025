#include "../utils.cpp"

u64 duplicate(u64 num)
{
    return num * std::pow(10, digit_length(num)) + num;
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

        u64 from_len = (digit_length(from));

        // take half of the digits, if the number of digits is not even,
        // use the closest higher power of 10
        u64 half = (from_len % 2 != 0) ? std::pow(10, from_len / 2)
                                       : from / std::pow(10, from_len / 2);

        // right half is bigger
        if (half < from % (u64)std::pow(10, from_len / 2)) {
            ++half;
        }

        u64 invalid = duplicate(half);
        while (invalid <= to) {
            res += invalid;
            invalid = duplicate(++half);
        }
    }

    P(res);
}
