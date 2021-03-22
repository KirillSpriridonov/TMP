#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

const int UNDEFINED = -5;

struct TValue {
    unsigned val;
    unsigned int lineCount;
    unsigned int wordCount;
};

struct TAnsVal {
    unsigned lineCount;
    unsigned wordCount;
};


bool operator==(const unsigned lhs, const TValue &rhs) {
    return lhs == rhs.val;
}

bool operator!=(const unsigned lhs, const TValue &rhs) {
    return lhs != rhs.val;
}

std::ostream &operator<<(std::ostream &out, const TAnsVal obj) {
    out << obj.lineCount << ", " << obj.wordCount;
    return out;
}

class TApostolicoGiancarlo {
    std::unordered_map<unsigned, int> rightIdPattern;
}
