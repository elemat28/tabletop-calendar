#include <timedateservice.h>
#include <gtest/gtest.h>
#include <iostream>

TEST(timedateservice_return, timestampNotNull) {

    const auto actual = get_current_timestamp();
   
    ASSERT_NE(NULL, actual);
};


TEST(timedateservice_return, matchesCurrentTime) {
    const auto expected = time(NULL);
    const auto actual = get_current_timestamp();
   
    ASSERT_EQ(expected, actual);
};

