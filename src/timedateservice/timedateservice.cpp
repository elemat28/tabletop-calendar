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

