#ifndef ILLEGAL_DELIMETER_H
#define ILLEGAL_DELIMETER_H

#include <string>
#include "Generic.h"

namespace Exception {

class IllegalDelimiter : public Generic {
public:
    IllegalDelimiter(std::string delim)
        : Generic("illegal delimiter " + delim + " found in number list") {}
};

}

#endif//ILLEGAL_DELIMETER_H