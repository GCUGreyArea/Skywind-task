#include <gtest/gtest.h>
#include <glog/logging.h>

#include "libTask.h"

TEST(testExceptions,testThatNegativeNumberExceptionCreatesCorrectOutput) {
    // Test the exception output and that it is caught
    EXPECT_THROW({
        try
        {
            throw Exception::NegativeNumber("-10","1,2,-10");
        }
        catch( const Exception::NegativeNumber& e )
        {
            // and this tests that it has the correct message
            EXPECT_STREQ( "-10 found in list 1,2,-10", e.what() );
            throw;
        }
    }, Exception::NegativeNumber);
}