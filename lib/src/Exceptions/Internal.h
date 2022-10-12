#ifndef INTERNAL_EXCEPTION
#define INTERNAL_EXCEPTION

/**
 * @file Internal.h
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
 * @addtogroup Internal
 */
#include "Generic.h"

namespace Exception {

class Internal : public Generic {
public:
    Internal(std::string err)
        : Generic(err) {}
};
}

/**
 * @}
 * @}
 * @}
 */
#endif//INTERNAL_EXCEPTION