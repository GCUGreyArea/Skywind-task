#include <gtest/gtest.h>
#include <glog/logging.h>

#include "libTask.h"

TEST(testCmdParser,testThatCmdParserWorksWithBasicInput) {
    Numbers::CmdParser parser("//,\n1,2,3");

    ASSERT_EQ(parser.add(),6);
}


TEST(testCmdParser,testThatCmdParserWorksWithMultiDelimInput) {
    Numbers::CmdParser parser("//[,][.]\n1,2.3");

    ASSERT_EQ(parser.add(),6);
}

TEST(testCmdParser,testThatCmdParserBadInput) {
    EXPECT_THROW({
        try
        {
            Numbers::CmdParser parser("/[,][.]\n1,2.3");
        }
        catch(const Exception::Generic& e)
        {
            // and this tests that it has the correct message
            EXPECT_STREQ( "invalid input : /[,][.]\n1,2.3", e.what() );
            throw;
        }
    }, Exception::Generic);
}
