#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

#define P(param) std::cout << (param) << "\n"

typedef uint64_t u64; 
typedef int64_t  i64; 

void print_vec(auto vec, char delim = '\n'){
    for (auto e: vec){
        std::cout << e << delim;
    }
    
    std::cout << "\n";
}

std::vector<std::string> split(std::string& str, char ch)
{
    std::vector<std::string> res;

    std::stringstream stream(str);

    for (std::string line; getline(stream, line, ch);) {
        res.push_back(line);
    }

    return res;
}

std::vector<std::string> load(const std::string&& file_name)
{
    std::vector<std::string> res;

    std::fstream input(file_name);
    for (std::string line; getline(input, line);) {
        res.push_back(line);
    }

    return res;
}

u64 digit_length(auto num) {
    if (num == 0) return 1;
    return trunc(log10(num)) + 1;
}
