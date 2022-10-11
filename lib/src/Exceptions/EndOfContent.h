#ifndef END_OF_CONTENT_H
#define END_OF_CONTENT_H

#include "Generic.h"

namespace Exception {

class EndOfContent : public Generic {
public:
    EndOfContent(std::string word)
        : Generic("end of number list encountered while parsing " + word) {}
};
} // namespace Exception

#endif//END_OF_CONTENT_H