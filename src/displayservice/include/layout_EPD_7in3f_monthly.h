#ifndef MONTHLY_LAYOUT
#define MONTHLY_LAYOUT
//DOW = Day of week
#define DOW_WIDTH 86
#define DOW_HEIGHT 64
#define DOW_COLUMNS 7
#define DOW_ROWS 6

#define DOW_GRID_HEADER_HEIGHT DOW_HEIGHT/2

#define DOW_GRID_HEIGHT DOW_HEIGHT*DOW_ROWS
#define DOW_GRID_Y_OFFSET EPD_7IN3F_HEIGHT-DOW_GRID_HEIGHT
#define DOW_GRID_WIDTH DOW_WIDTH*DOW_COLUMNS
#define DOW_GRID_W_HEADER_HEIGHT DOW_GRID_HEIGHT+DOW_GRID_HEADER_HEIGHT

#define _REMAINING_SCREEN_WIDTH EPD_7IN3F_WIDTH-DOW_GRID_WIDTH
#define EXTRA_MODULES_X_OFFSET DOW_GRID_WIDTH
#endif