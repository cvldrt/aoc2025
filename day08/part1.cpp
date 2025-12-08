#include <set>

#include "../utils.cpp"

typedef std::tuple<i64, i64, i64> coordinate;

double distance(auto c1, auto c2)
{
    auto [x1, y1, z1] = c1;
    auto [x2, y2, z2] = c2;

    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}

int main()
{
    auto input = load("input.txt");

    auto coor_cmp = [](auto lhs, auto rhs) {
        auto [from1, to1] = lhs;
        auto [from2, to2] = rhs;
        return distance(from1, to1) < distance(from2, to2);
    };

    std::set<std::pair<coordinate, coordinate>, decltype(coor_cmp)> coor_set;

    std::vector<coordinate> coors;
    for (auto& line : input) {
        auto s = split(line, ',');

        coordinate new_coor = {atoll(s[0].c_str()), atoll(s[1].c_str()),
                               atoll(s[2].c_str())};
        for (coordinate c : coors) {
            std::pair<coordinate, coordinate> new_pair = {c, new_coor};
            coor_set.insert(new_pair);
        }

        coors.push_back(new_coor);
    }

    std::vector<std::set<coordinate>> circuits;
    auto it = coor_set.begin();
    for (int i = 0; i < 1000; ++i, ++it){
        auto c1 = (*it).first;
        auto c2 = (*it).second;

        std::set<coordinate>* prev_added = nullptr;

        for (auto& set : circuits) {
            if (set.contains(c1) || set.contains(c2)) {
                if (prev_added) {
                    set.merge(*prev_added);
                    (*prev_added).clear();
                    break;
                }

                set.insert(c1);
                set.insert(c2);
                prev_added = &set;
            }
        }

        if (!prev_added) {
            std::set<coordinate> circuit;
            circuit.insert(c1);
            circuit.insert(c2);
            circuits.push_back(circuit);
        }
    }

    auto size_cmp  = [](auto lhs, auto rhs) {
        return lhs.size() < rhs.size();
    };

    u64 res = 1;
    for (int i = 0; i < 3; ++i) {
        auto it = std::max_element(circuits.begin(), circuits.end(), size_cmp);

        res *= (*it).size();
        circuits.erase(it);
    }

    P(res);
}
