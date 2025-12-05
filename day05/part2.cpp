#include "../utils.cpp"


int main()
{
    auto input = load("input.txt");

    ranges r;

    for (int i = 0; i < input.size(); ++i) {
        if (input[i].empty()) break;

        auto dash_pos = input[i].find('-');

        u64 from = atoll(input[i].substr(0, dash_pos).c_str());
        u64 to   = atoll(input[i].substr(dash_pos + 1).c_str());

        r.add(from, to);
    }

    r.merge();

    u64 res = 0;

    for (auto[from, to]: r.r) {
        res += to - from + 1;
    }

    P(res);
}
