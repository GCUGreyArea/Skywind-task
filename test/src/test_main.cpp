/**
 * @file test_parser.cpp
 * @author Barry Robinson (barry.w.robinson64@gmail.com)
 * @brief Test harness for filescan application library
 * @version 0.1
 * @date 26/09/2021
 * 
 * @copyright Copyright (c) 2021
 * @addtogroup test 
 * @{
 * @addtogroup main
 * @{
 * 
 */


#include <gtest/gtest.h>
#include <glog/logging.h>
/**
 * @brief Main function for test harness
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, const char ** argv) {
    google::InitGoogleLogging(argv[0]);
    testing::InitGoogleTest(&argc, (char**) argv);
    return RUN_ALL_TESTS();

}

/**
 * @}
 * @}
 */
