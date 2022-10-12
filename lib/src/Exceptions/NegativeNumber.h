#ifndef NEGATIVE_NUMBER_EXCEPTION
#define NEGATIVE_NUMBER_EXCEPTION
/**
 * @file NegativeNumber.h
 * @author barry.robinson (barry.robinson@alertlogic.com)
 * @brief Defines an exception thrown when a negative number is
 * found in the input.
 * @version 1.0
 * @date 10-10-2022
 *
 * @copyright Copyright (C) 2022 Alert Logic
 * @addtogroup lib
 * @{
 * @addtogroup Exceptions
 * @{
 * @addtogroup NegativeNumber
 */

#include <string>

#include "Generic.h"

namespace Exception {

class NegativeNumber : public Generic {
public:
    NegativeNumber(std::string num, std::string list)
        : Generic(num + " found in list " + list) {}
};
}

/**
 * @}
 * @}
 * @}
 */
#endif//NEGATIVE_NUMBER_EXCEPTION