#include "../utils.cpp"
#include <numeric>

#define EMPTY 0
#define START -1
#define SPLIT -2

void print_grid(auto grid)
{
    u64 height = grid.size();
    u64 width  = grid[0].size();

    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            std::cout << grid[row][col] << "\t";
        }
        std::cout << std::endl;
    }
}

int main()
{
    auto input = load("input.txt");

    u64 height = input.size();
    u64 width  = input[0].size();

    std::vector<std::vector<i64>> num_map;

    for (int row = 0; row < height; ++row) {
        std::vector<i64> nums;
        for (int col = 0; col < width; ++col) {
            switch (input[row][col]) {
                case 'S':
                    nums.push_back(START);
                    break;
                case '^':
                    nums.push_back(SPLIT);
                    break;
                default:
                    nums.push_back(EMPTY);
            }
        }
        num_map.push_back(nums);
    }

    for (int row = 1; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            if (num_map[row - 1][col] == START) {
                num_map[row][col] = 1;
            } else if (num_map[row - 1][col] > EMPTY) {
                if (num_map[row][col] != SPLIT) {
                    num_map[row][col] += num_map[row - 1][col];
                }
                if (num_map[row][col] == SPLIT) {
                    if (col > 0) {
                        num_map[row][col - 1] += num_map[row - 1][col];
                    }
                    if (col < width - 1) {
                        num_map[row][col + 1] += num_map[row - 1][col];
                    }
                }
            }
        }
    }

    P("");

    print_grid(num_map);

    auto last = *(--num_map.end());

    P(std::accumulate(last.begin(), last.end(), (u64) 0));
}
