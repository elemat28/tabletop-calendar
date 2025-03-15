/**
 * @file main.cpp
 * @author Mateusz M
 * @brief 
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "main.h"



/// @brief This is where the program starts
/// @return returns exit code
int main(int, char**){
    std::cout << "Hello, from tabletopCalendar!\n";
    std::cout << "current date is: ";
    time_t timestamp = get_current_timestamp();
    std::cout << ctime(&timestamp) << "\n";
    char output[50];
    timestamp_as_DDMMYY(output, &timestamp);
    std::cout << output << "\n";


    return 0;
}
