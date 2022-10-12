#ifndef END_OF_CONTENT_H
#define END_OF_CONTENT_H
/**
 * @file EndOfContent.h
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
 * @addtogroup EndOfContent
 * @{
 */
#include "Generic.h"

namespace Exception {

class EndOfContent : public Generic {
public:
    EndOfContent(std::string word)
        : Generic("end of number list encountered while parsing " + word) {}
};

} // namespace Exception

/**
 * @}
 * @}
 * @}
 *
 */
#endif//END_OF_CONTENT_H