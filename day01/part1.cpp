#include "../utils.cpp"

enum direction { LEFT = -1, RIGHT = 1};

int main()
{
    auto input = load("input.txt");

    u64 res = 0;
    i64 pos = 50;

    for (auto& line : input) {

        direction dir = line[0] == 'R' ? RIGHT : LEFT;
        i64 clicks = atoi(line.c_str() + 1);

        pos += clicks * dir;
        res += pos % 100 == 0;
    }

    P(res);
}
