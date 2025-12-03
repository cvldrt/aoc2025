#include "../utils.cpp"

#define BATTERIES 12

int main()
{
    auto input = load("input.txt");

    u64 res = 0;

    for (auto& bank : input) {
        char it     = '0';
        i64 max_pos = -1;
        u64 joltage = 0;

        for (i64 b = BATTERIES - 1; b >= 0; --b) {
            for (u64 i = max_pos + 1; i < bank.size() - b; ++i) {
                if (bank[i] > it) {
                    it      = bank[i];
                    max_pos = i;
                }
            }

            joltage = joltage * 10 + it - 48;
            it = '0';
        }

        res += joltage;
    }

    P(res);
}
