
#include <stdio.h>
#include "waveshare_eink.h"

int main(void){
    printf("Hello, World!\n");
    waveshareCheckEnv();
    printf("init display...\n");
    EPD_7IN3F_Init();
    printf("clear display...\n");
    EPD_7IN3F_Clear(EPD_7IN3F_GREEN);
    return 0;
};