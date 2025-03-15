#include <iostream>
#include <ctime>




time_t get_current_timestamp();
time_t new_relative_timestamp(time_t* timestamp, int seconds);
time_t timestamp_seconds_from_now(int numberOfSeconds);
time_t timestamp_day_before(time_t* timestamp);

void timestamp_as_DDMMYY(char* charArr, time_t* timestamp);
void timestamp_as_DDMMYYYY(char* charArr, time_t* timestamp);

void timestamp_as_HHMM(char* charArr, time_t* timestamp, bool militaryFormat);
void timestamp_as_HHMMSS(char* charArr, time_t* timestamp, bool militaryFormat);

int day_of_the_week(time_t* timestamp);
int month_of_year(time_t* timestamp);
int len_of_month(time_t* timestamp);
