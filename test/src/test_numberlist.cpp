#include <gtest/gtest.h>
#include <glog/logging.h>

#include "libTask.h"

TEST(testNumberList,testThatSimpleListIsMapped) {
    Numbers::NumberList list("1,2,3,4,5",{","});

    if(!list.to_num_vector())
        ASSERT_TRUE(false);

    auto& v = list.get_numbers();


    ASSERT_EQ(v.size(),5);

    ASSERT_EQ(v[0],1);
    ASSERT_EQ(v[1],2);
    ASSERT_EQ(v[2],3);
    ASSERT_EQ(v[3],4);
    ASSERT_EQ(v[4],5);
}

TEST(testNumberList,testLongerDelimiters) {
    Numbers::NumberList list("1-this-2%%%3%%%4,5",{",","-this-","%%%"});

    if(!list.to_num_vector())
        ASSERT_TRUE(false);

    auto& v = list.get_numbers();


    ASSERT_EQ(v.size(),5);

    ASSERT_EQ(v[0],1);
    ASSERT_EQ(v[1],2);
    ASSERT_EQ(v[2],3);
    ASSERT_EQ(v[3],4);
    ASSERT_EQ(v[4],5);

}

TEST(testNumberList,testNegativeNumberAtStartOfList) {
    Numbers::NumberList list("-1-this-2%%%3%%%4,5",{",","-this-","%%%"});

    EXPECT_THROW({
        try
        {
            list.to_num_vector();
        }
        catch( const Exception::NegativeNumber& e )
        {
            // and this tests that it has the correct message
            EXPECT_STREQ("-1 found in list -1-this-2%%%3%%%4,5", e.what());
            throw;
        }
    }, Exception::NegativeNumber);

}

TEST(testNumberList,testNegativeNumberInList) {
    Numbers::NumberList list("1-this-2%%%3%%%-4,5",{",","-this-","%%%"});

    EXPECT_THROW({
        try
        {
            list.to_num_vector();
        }
        catch( const Exception::NegativeNumber& e )
        {
            // and this tests that it has the correct message
            EXPECT_STREQ("-4 found in list 1-this-2%%%3%%%-4,5", e.what());
            throw;
        }
    }, Exception::NegativeNumber);

}

TEST(testNumberList,testNegativeNumberAtEndOfList) {
    Numbers::NumberList list("1-this-2%%%3%%%4,-5",{",","-this-","%%%"});

    EXPECT_THROW({
        try
        {
            list.to_num_vector();
        }
        catch( const Exception::NegativeNumber& e )
        {
            // and this tests that it has the correct message
            EXPECT_STREQ("-5 found in list 1-this-2%%%3%%%4,-5", e.what());
            throw;
        }
    }, Exception::NegativeNumber);

}

TEST(testNumberList,testBadDelimiter) {
    Numbers::NumberList list("1-this-2%%%%3%%%4,-5",{",","-this-","%%%"});

    EXPECT_THROW({
        try
        {
            list.to_num_vector();
        }
        catch( const Exception::IllegalDelimiter& e )
        {
            // and this tests that it has the correct message
            EXPECT_STREQ("illegal delimiter %%%% found in number list", e.what());
            throw;
        }
    }, Exception::IllegalDelimiter);

}

TEST(testNumberList,testThatCorrectValuesAreGiven) {
    Numbers::NumberList list("1,2,3,4,5",{","});

    ASSERT_TRUE(list.to_num_vector());

    ASSERT_EQ(list.add(),15);
}

TEST(testNumberList,testThatCorrectValuesAreGivenSimpleList) {
    Numbers::NumberList list("1,2,3",{","});

    ASSERT_TRUE(list.to_num_vector());

    ASSERT_EQ(list.add(),6);
}

TEST(testNumberList,testThatCorrectValuesAreGivenWithMax) {
    Numbers::NumberList list("1001,1002,1003,1004,1005",{","});

    ASSERT_TRUE(list.to_num_vector());

    ASSERT_EQ(list.add(),15);
}