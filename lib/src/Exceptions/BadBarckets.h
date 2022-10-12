#ifndef BAD_BRACKETS_H
#define BAD_BRACKETS_H

/**
 * @file BadBarckets.h
 * @author barry.robinson (barry.robinson@alertlogic.com)
 * @brief Used to indicate not matching brackets in
 * delimeter.
 * @version 1.0
 * @date 12-10-2022
 *
 * @copyright Copyright (C) 2022 Alert Logic
 * @addtogroup lib
 * @{
 * @addtogroup Exceptions
 * @{
 * @addtogroup BadBrackets

 */
#include "Generic.h"

namespace Exception {

class BadBrackets : public Generic {
public:
    BadBrackets(size_t place)
        : Generic("no closing bracket found at " + std::to_string(place)) {}
};
/**
 * @}
 * @}
 * @}
 */
}

#endif//BAD_BRACKETS_H