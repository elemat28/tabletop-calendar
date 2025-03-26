/**
 * @file timedateservice_test.cpp
 * @author Mateusz M
 * @brief Tests for timedateservice
 * @version 0.1
 * @date 2025-03-26
 * 
 * @copyright Copyright (c) 2025
 * 
 */
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





TEST(timedateservice_return, returnsSunday) {
    /**
     * @brief create a known timestamp and check if returned value matches the one set in definition 
     * Sunday, 2nd of February 2025, 13:31:01, not a leap year
     * 
     */
    struct tm date;
    time_t timestamp;
    date.tm_year = 2025 - 1900; // Number of years since 1900
    date.tm_mon = 2 - 1; // Number of months since January
    date.tm_mday = 2;
    date.tm_hour = 13;
    date.tm_min = 31;
    date.tm_sec = 1;
    date.tm_isdst = -1;
    timestamp = mktime(&date);
    const auto expected = 0; // 0 = Sunday, 1 = Monday, 6 = Saturday
    const auto actual = day_of_the_week(&timestamp);
   
    ASSERT_EQ(expected, actual);
};


TEST(timedateservice_return, returnsSaturday) {
    /**
     * @brief create a known timestamp and check if returned value matches the one set in definition 
     * Saturday, 1st of February 2025, 13:31:01, not a leap year
     * 
     */
    struct tm date;
    time_t timestamp;
    date.tm_year = 2025 - 1900; // Number of years since 1900
    date.tm_mon = 2 - 1; // Number of months since January
    date.tm_mday = 1;
    date.tm_hour = 13;
    date.tm_min = 31;
    date.tm_sec = 1;
    date.tm_isdst = -1;
    timestamp = mktime(&date);
    const auto expected = 6; // 0 = Sunday, 1 = Monday, 6 = Saturday
    const auto actual = day_of_the_week(&timestamp);
   
    ASSERT_EQ(expected, actual);
};



TEST(timedateservice_return, returnsFebruary) {
    /**
     * @brief create a known timestamp and check if returned value matches the one set in definition 
     * Saturday, 1st of February 2025, 13:31:01, not a leap year
     * 
     */
    struct tm date;
    time_t timestamp;
    date.tm_year = 2025 - 1900; // Number of years since 1900
    date.tm_mon = 2 - 1; // Number of months since January
    date.tm_mday = 1;
    date.tm_hour = 13;
    date.tm_min = 31;
    date.tm_sec = 1;
    date.tm_isdst = -1;
    timestamp = mktime(&date);
    const auto expected = 1; // 0 = January, 1 = February, 11 = December
    const auto actual = month_of_year(&timestamp);
   
    ASSERT_EQ(expected, actual);
};


TEST(timedateservice_return, returnsNonLeapFebruaryLen) {
    /**
     * @brief create a known timestamp and check if returned value matches the one set in definition 
     * Saturday, 1st of February 2025, 13:31:01, not a leap year
     * 
     */
    struct tm date;
    time_t timestamp;
    date.tm_year = 2025 - 1900; // Number of years since 1900
    date.tm_mon = 2 - 1; // Number of months since January
    date.tm_mday = 1;
    date.tm_hour = 13;
    date.tm_min = 31;
    date.tm_sec = 1;
    date.tm_isdst = -1;
    timestamp = mktime(&date);
    const auto expected = 28;
    const auto actual = len_of_month(&timestamp);
   
    ASSERT_EQ(expected, actual);
};


TEST(timedateservice_return, returnsLeapFebruaryLen) {
    /**
     * @brief create a known timestamp and check if returned value matches the one set in definition 
     * Saturday, 1st of February 2024, 13:31:01, a leap year (month)
     * 
     */
    struct tm date;
    time_t timestamp;
    date.tm_year = 2024 - 1900; // Number of years since 1900
    date.tm_mon = 2 - 1; // Number of months since January
    date.tm_mday = 1;
    date.tm_hour = 13;
    date.tm_min = 31;
    date.tm_sec = 1;
    date.tm_isdst = -1;
    timestamp = mktime(&date);
    const auto expected = 29;
    const auto actual = len_of_month(&timestamp);
   
    ASSERT_EQ(expected, actual);
};