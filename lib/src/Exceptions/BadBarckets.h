#ifndef BAD_BRACKETS_H
#define BAD_BRACKETS_H

#include "Generic.h"

namespace Exception {

class BadBrackets : public Generic {
public:
    BadBrackets(size_t place)
        : Generic("no closing bracket found at " + std::to_string(place)) {}
};

}

#endif//BAD_BRACKETS_H