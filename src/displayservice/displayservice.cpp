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

paintcursor cursor;


int display_init(){
    
    return 0;
}

void paint_box_grid(uint16_t boxWidthPX, uint16_t boxHeightPX, int columns, int rows, uint16_t startX, uint16_t startY){
    cursor.X = startX;
    cursor.Y = startY;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            Paint_DrawRectangle(cursor.X, cursor.Y, cursor.X+boxWidthPX, cursor.Y+boxHeightPX, (i+j)%7, DOT_PIXEL_2X2, DRAW_FILL_FULL);
            cursor.X += boxWidthPX;
        };
        cursor.Y += boxHeightPX;
        cursor.X = startX;
    };
    
    
}