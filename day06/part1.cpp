#include <numeric>

#include "../utils.cpp"

template <typename T>
std::vector<T> parse(std::string& str)
{
    std::vector<T> res;
    std::stringstream ss(str);

    T n;

    ss >> std::ws;
    while (!ss.eof()) {
        ss >> n >> std::ws;
        res.push_back(n);
    }

    return res;
}

int main()
{
    auto input = load("input.txt");
    std::vector<std::vector<u64>> numbers;

    for (int i = 0; i < input.size() - 1; ++i) {
        if (input[i].empty()) continue;
        numbers.push_back(parse<u64>(input[i]));
    }

    auto operands = parse<char>(input[input.size() - 1]);

    u64 res = 0;

    u64 line_count = numbers.size();
    for (int i = 0; i < numbers[0].size(); ++i) {
        std::vector<u64> col;

        for (int n = 0; n < line_count; ++n) {
            col.push_back(numbers[n][i]);
        }

        if (operands[i] == '+') {
            res += std::accumulate(col.begin(), col.end(), (u64)0);
        } else {
            res += std::accumulate(col.begin(), col.end(), (u64)1,
                                   std::multiplies<u64>());
        }

        col.clear();
    }


    P(res);
}
