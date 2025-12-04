#include "../utils.cpp"

int main()
{
    auto input = load("input.txt");

    u64 res = 0;

    for (int y = 0; y < input.size(); ++y) {
        for (int x = 0; x < input[0].size(); ++x) {
            if (input[y][x] == '@' && count_around(input, x, y, '@') < 4) {
                ++res;
            }
        }
    }

    P(res);
}
