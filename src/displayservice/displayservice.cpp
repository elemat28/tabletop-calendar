/**
 * @file timedateservice.c
 * @author Mateusz M
 * @brief This library provides convinience functions for getting time, date and related
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <displayservice.h>
#include <iostream>
paintcursor cursor;


int display_init(){
    
    return 0;
}

void paint_month_grid_header(uint16_t boxWidthPX, uint16_t boxHeightPX, uint16_t startX, uint16_t startY,  sFONT *Font, uint16_t Color_Foreground, uint16_t Color_Background, bool centerText){
    cursor.X = startX;
    cursor.Y = startY - boxHeightPX - 2;
    Paint_DrawRectangle(cursor.X, cursor.Y, cursor.X+boxWidthPX*7 - 2, startY, Color_Background, DOT_PIXEL_2X2, DRAW_FILL_FULL);
    if(centerText){
        cursor.X += (boxWidthPX - Font->Width*3) / 2;
        cursor.Y += (boxHeightPX - Font-> Height) / 2;
    };
    //char DaysOfWeek = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"];
    char dayOfWeek[] = "MON\0TUE\0WED\0THU\0FRI\0SAT\0SUN";
    char* strItter =  dayOfWeek;
    for (size_t i = 0; i < 7; i++)
    {
        Paint_DrawString_EN(cursor.X, cursor.Y, strItter, Font, Color_Background, Color_Foreground);
        //Paint_DrawRectangle(cursor.X, cursor.Y, cursor.X+boxWidthPX-2, cursor.Y+boxHeightPX, EPD_7IN3F_BLUE, DOT_PIXEL_2X2, DRAW_FILL_EMPTY);
            cursor.X += boxWidthPX;
            strItter+=4;
    };
};

void paint_month_grid(uint16_t boxWidthPX, uint16_t boxHeightPX, int columns, int rows, uint16_t startX, uint16_t startY){
    cursor.X = startX;
    cursor.Y = startY;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            Paint_DrawRectangle(cursor.X, cursor.Y, cursor.X+boxWidthPX-2, cursor.Y+boxHeightPX, (j)%2, DOT_PIXEL_2X2, DRAW_FILL_EMPTY);
            cursor.X += boxWidthPX;
        };
        cursor.Y += boxHeightPX;
        cursor.X = startX;
    };
    
    
}