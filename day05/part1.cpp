#include "../utils.cpp"

int main()
{
    auto input = load("input.txt");

    ranges r;

    u64 empty_pos = 0;

    for (int i = 0; i < input.size(); ++i) {
        if (input[i].empty()) break;

        ++empty_pos;

        auto dash_pos = input[i].find('-');

        u64 from = atoll(input[i].substr(0, dash_pos).c_str());
        u64 to   = atoll(input[i].substr(dash_pos + 1).c_str());

        r.add(from, to);
    }

    u64 res = 0;

    for (int i = empty_pos; i < input.size(); ++i) {
        if (r.contains(atoll(input[i].c_str()))) ++res;
    }

    P(res);
}
