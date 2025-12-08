#include "../utils.cpp"

int main()
{
    auto input = load("input.txt");

    u64 res = 0;

    u64 height = input.size();
    u64 width  = input[0].size();

    for (int row = 1; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            if (input[row - 1][col] == 'S') {
                input[row][col] = '|';
            } else if (input[row - 1][col] == '|') {
                if (input[row][col] == '.') {
                    input[row][col] = '|';
                } else if (input[row][col] == '^') {
                    res += 1;
                    if (col > 0) input[row][col - 1] = '|';
                    if (col < width - 1) input[row][col + 1] = '|';
                }
            }
        }
    }

    P(res);
}
