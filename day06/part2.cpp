#include <cassert>
#include <numeric>

#include "../utils.cpp"

int main()
{
    auto input = load("input.txt");

    u64 res = 0;

    std::vector<u64> nums;
    char op;

    u64 x = 0;
    for (int i = input[0].size() - 1; i >= 0; --i) {
        bool empty = true;
        u64 n      = 0;

        for (int j = 0; j < input.size(); ++j) {
            if (isdigit(input[j][i])) {
                n     = n * 10 + input[j][i] - 48;
                empty = false;
            } else if (input[j][i] == '+' || input[j][i] == '*') {
                op    = input[j][i];
                empty = false;
            }
        }

        if (!empty || i == 0) {
            nums.push_back(n);
        }

        if (empty || i == 0 || n == 0) {
            if (op == '+') {
                res += std::accumulate(nums.begin(), nums.end(), (u64)0);
            } else {
                res += std::accumulate(nums.begin(), nums.end(), (u64)1,
                                       std::multiplies<u64>());
            }

            print_vec(nums);
            nums.clear();
        }
    }

    P(res);
}
