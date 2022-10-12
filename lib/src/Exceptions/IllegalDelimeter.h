#ifndef ILLEGAL_DELIMETER_H
#define ILLEGAL_DELIMETER_H
/**
 * @file IllegalDelimeter.h
 * @author barry.robinson (barry.robinson@alertlogic.com)
 * @brief
 * @version 1.0
 * @date 12-10-2022
 *
 * @copyright Copyright (C) 2022 Alert Logic
 * @addtogroup lib
 * @{
 * @addtogroup Exceptions
 * @{
 * @addtogroup IllegalDelimiter
*/
#include <string>
#include "Generic.h"

namespace Exception {

class IllegalDelimiter : public Generic {
public:
    IllegalDelimiter(std::string delim)
        : Generic("illegal delimiter " + delim + " found in number list") {}
};

}
/**
 * @}
 * @}
 * @}
 */
#endif//ILLEGAL_DELIMETER_H