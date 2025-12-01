#include "../utils.cpp"

enum direction { LEFT = -1, RIGHT = 1 };

int main()
{
    auto input = load("input.txt");

    u64 res = 0;
    i64 pos = 50;

    for (auto& line : input) {
        direction dir = line[0] == 'R' ? RIGHT : LEFT;
        i64 clicks    = atoi(line.c_str() + 1);

        res += std::abs(pos / 100 - (pos + dir * clicks) / 100);
        res += pos > 0 && (pos + dir * clicks) <= 0 ||
               pos < 0 && (pos + dir * clicks) >= 0;

        pos += dir * clicks;
        pos %= 100;
    }

    P(res);
}
