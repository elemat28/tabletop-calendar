/**
 * @file timedateservice.cpp
 * @author Mateusz M
 * @brief This library provides convinience functions for getting time, date and related
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <timedateservice.h>


/**
 * @brief Get the timestamp of NOW
 * @return time_t 
 */
time_t get_current_timestamp(){
    time_t stamp = time(NULL);
    return stamp;
}

/**
 * @brief Creates a new timestamp relative to the timestamp passed as arg
 * 
 * @param timestamp pointer to existing timestamp
 * @param seconds how long before or after should the new timestamp be
 */
time_t new_relative_timestamp(time_t* timestamp, int seconds){
    time_t new_time = long(&timestamp + seconds);
    return new_time;
}

/**
 * @brief Convinence function that returns timestamp that is numberOfSeconds away from NOW.
 * 
 * @param numberOfSeconds how long before or after NOW should the new timestamp be
 */
time_t timestamp_seconds_from_now(int numberOfSeconds){
    time_t now = get_current_timestamp();
    time_t returnableTimestamp = new_relative_timestamp(&now, numberOfSeconds);
    return returnableTimestamp; 
}

/**
 * @brief Puts the date of the timestamp into the array as 8 chars in the format of Day/Month/Year, eg '14/03/25'
 * 
 * @param charArr needs to be at least 8 chars long 
 * @param timestamp pointer to existing timestamp
 */
void timestamp_as_DDMMYY(char* charArr, time_t* timestamp){
    struct tm datetime = *localtime(timestamp);
    strftime(charArr, 50, "%d/%m/%y", &datetime);
}

/**
 * @brief Puts the date of the timestamp into the array as 10 chars in the format of Day/Month/Year, eg '14/03/2025'
 * 
 * @param charArr needs to be at least 10 chars long 
 * @param timestamp pointer to existing timestamp
 */
void timestamp_as_DDMMYYYY(char* charArr, time_t* timestamp){
    struct tm datetime = *localtime(timestamp);
    strftime(charArr, 10, "%d/%m/%Y", &datetime);
}

/**
 * @brief Returns day of week for the given timestmap 
 * 
 * @param timestamp 
 * @return int 0-6, 0 = Sunday, 1 = Monday, 6 = Saturday
 */
int day_of_the_week(time_t* timestamp){
    struct tm datetime = *localtime(timestamp);
     return datetime.tm_wday;
};

/**
 * @brief Returns month of the year for the given timestmap 
 * 
 * @param timestamp 
 * @return int 0-11, 0 = January 
 */
int month_of_year(time_t* timestamp){
    struct tm datetime = *localtime(timestamp);
     return datetime.tm_mon;
};

/**
 * @brief finds out how many days in the month of the passed timestamp
 * 
 * As this information is not stated as part of tm struct, it needs to be calculated 
 * it's done by creating a new tm from timestamp passed as arg, updating the tm to first day of the next month
 * and then creating a timestamp from the new tm and taking away 1 day of seconds from that time stamp which gets us to last day of the current month
 * 
 * @param timestamp 
 * @return int 0-31, accounts for leap years/months 
 */
int len_of_month(time_t* timestamp){
    struct tm datetime = *localtime(timestamp);
    if(datetime.tm_mon == 11){
        datetime.tm_year +=1;
        datetime.tm_mon = 0;
    } else {
        datetime.tm_mon += 1;
    };
    datetime.tm_mday = 1;
    const time_t stamp_day_before = mktime(&datetime) - 60*60*24;

    datetime = *localtime(&stamp_day_before);
    return datetime.tm_mday;

};