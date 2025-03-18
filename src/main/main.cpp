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

#include <timedateservice.h>
extern "C" {
    #include <waveshare_eink.h>
}





/// @brief This is where the program starts
/// @return returns exit code
int main(int, char**){
    std::cout << "Hello, from tabletopCalendar!\n";
    std::cout << "current date is: ";
    time_t timestamp = get_current_timestamp();
    std::cout << ctime(&timestamp) << "\n";
#ifdef epd7in3f
std::cout << "epd7in3f defined \n";
#endif

#ifdef RPI
std::cout << "RPI defined \n";
#endif
    char output[50];
    timestamp_as_DDMMYY(output, &timestamp);
    waveshareCheckEnv();

    printf("e-Paper Init and Clear...\r\n");
    EPD_7IN3F_Init();
    EPD_7IN3F_Clear(EPD_7IN3F_ORANGE);
    std::cout << output << "\n";
    std::cout << output << "\n";
    EPD_7IN3F_Sleep();
    return 0;
}
