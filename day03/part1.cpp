#include "../utils.cpp"

int main()
{
    auto input = load("input.txt");

    u64 res = 0;

    for (auto& bank : input) {
        char it1 = '0', it2 = '0';
        u64 max_pos = 0;;

        for (u64 i = 0; i < bank.size() - 1; ++i) {
            if (bank[i] > it1) {
                it1 = bank[i];
                max_pos = i;
            }
        }

        for (int i = max_pos + 1; i < bank.size(); ++i) {
            if (bank[i] > it2) {
                it2 = bank[i];
            }

        }

        u64 joltage = (it1 - 48) * 10 + (it2 - 48);
        res += joltage;
    }

    P(res);
}
