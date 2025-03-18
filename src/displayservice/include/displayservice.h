



/* This ifdef allows the header to be used from both C and C++. */
extern "C" {
    #include <waveshare_eink.h>
}
#include "layout_EPD_7in3f_monthly.h"

struct paintcursor
{
    uint16_t X;
    uint16_t Y;
    /* data */
};


int display_init();
void paint_month_grid(uint16_t boxWidthPX, uint16_t boxHeightPX, int columns, int rows, uint16_t startX, uint16_t startY);
void paint_month_grid_header(uint16_t boxWidthPX, uint16_t boxHeightPX, uint16_t startX, uint16_t startY, sFONT *Font, uint16_t Color_Foreground, uint16_t Color_Background, bool centerText);