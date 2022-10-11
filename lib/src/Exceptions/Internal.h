#ifndef INTERNAL_EXCEPTION
#define INTERNAL_EXCEPTION

#include "Generic.h"

namespace Exception {

class Internal : public Generic {
public:
    Internal(std::string err)
        : Generic(err) {}
};
}

#endif//INTERNAL_EXCEPTION