#include <gtest/gtest.h>
#include <glog/logging.h>

#include "libTask.h"

TEST(testUtils,testThatNumbersAreTranslatedCorrectly) {
    std::string num_str = "-124";
    int base = Utils::Numbers::is_number(num_str);
    ASSERT_EQ(base,10);

    int num = Utils::Numbers::to_int(num_str,base);
    ASSERT_EQ(num,-124);

    num_str = "0x24";
    base = Utils::Numbers::is_number(num_str);
    ASSERT_EQ(base,16);

    num = Utils::Numbers::to_int(num_str,base);
    ASSERT_EQ(num,36);

    num_str = "0b1001001";
    base = Utils::Numbers::is_number(num_str);

    ASSERT_EQ(base,2);

    num = Utils::Numbers::to_int(num_str,base);
    ASSERT_EQ(num,73);

    num_str= "010";
    base = Utils::Numbers::is_number(num_str);

    ASSERT_EQ(base,8);
    num = Utils::Numbers::to_int(num_str,base);
    ASSERT_EQ(num,8);

    num_str = "0n34";
    base = Utils::Numbers::is_number(num_str);

    ASSERT_EQ(base,0);
}