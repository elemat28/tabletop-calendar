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

<<<<<<< HEAD
void paint_box_grid(uint16_t boxWidthPX, uint16_t boxHeightPX, int columns, int rows, uint16_t startX, uint16_t startY){
=======
void paint_month_grid_header(uint16_t boxWidthPX, uint16_t boxHeightPX, uint16_t startX, uint16_t startY,  sFONT *Font, uint16_t Color_Foreground, uint16_t Color_Background, bool centerText){
    cursor.X = startX;
    Paint_DrawRectangle(cursor.X, cursor.Y, cursor.X+boxWidthPX*7 - 2, startY, Color_Background, DOT_PIXEL_2X2, DRAW_FILL_FULL);
        {
<<<<<<< HEAD
            Paint_DrawRectangle(cursor.X, cursor.Y, cursor.X+boxWidthPX, cursor.Y+boxHeightPX, (i+j)%7, DOT_PIXEL_2X2, DRAW_FILL_FULL);
=======
            Paint_DrawRectangle(cursor.X, cursor.Y, cursor.X+boxWidthPX-2, cursor.Y+boxHeightPX, (j)%2, DOT_PIXEL_2X2, DRAW_FILL_EMPTY);
>>>>>>> a62b15d (display monthly calendar grid on EPD_7in3f)
            cursor.X += boxWidthPX;
        };
        cursor.Y += boxHeightPX;
        cursor.X = startX;
    };
    
    
}