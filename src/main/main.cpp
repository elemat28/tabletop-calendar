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
#include "displayservice.h"




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
    printf("blackImage...\r\n");
    UBYTE *BlackImage;
UDOUBLE Imagesize = ((EPD_7IN3F_WIDTH % 2 == 0)? (EPD_7IN3F_WIDTH / 2 ): (EPD_7IN3F_WIDTH / 2 + 1)) * EPD_7IN3F_HEIGHT;
if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
    printf("Failed to apply for black memory...\r\n");
    return -1;
};
    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlackImage, EPD_7IN3F_WIDTH, EPD_7IN3F_HEIGHT, 0, EPD_7IN3F_WHITE);
    Paint_SetScale(7);
    printf("Paint_SelectImage\r\n");
    Paint_SelectImage(BlackImage);
    printf("Paint_Clear\r\n");
    Paint_Clear(EPD_7IN3F_WHITE);
    printf("Paint_draw\r\n");
    paint_box_grid(DOW_WIDTH, DOW_HEIGHT, DOW_COLUMNS, DOW_ROWS, 0,DOW_GRID_Y_OFFSET);
    printf("EPD DISPLAY\r\n");
    EPD_7IN3F_Display(BlackImage);
    DEV_Delay_ms(3000);

    EPD_7IN3F_Sleep();
    return 0;
}
