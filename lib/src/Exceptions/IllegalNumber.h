#ifndef ILLEGAL_NUMBER_H
#define ILLEGAL_NUMBER_H
/**
 * @file IllegalNumber.h
 * @author barry.robinson (barry.robinson@alertlogic.com)
 * @brief
 * @version 1.0
 * @date 10-10-2022
 *
 * @copyright Copyright (C) 2022 Alert Logic
 *
 */
#include <string>
#include "Generic.h"


namespace Exception {

class IllegalNumber : public Generic {
public:
    IllegalNumber(std::string num)
        : Generic("illegal number found " + num + " in number list") {}
};

}// namespace Exception

#endif//ILLEGAL_NUMBER_H