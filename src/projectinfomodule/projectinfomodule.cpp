/**
 * @file projectinfomodule.cpp
 * @author Mateusz M
 * @brief This plugin displays a box with selectable inf about current project
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <projectinfomodule.h>






int get_project_name(){
    return 0;
};

void draw_author_name(paintcursor cursor){
    char intro[] = "By: ";
        char arrToPrint[5+ strlen(projectAuthor)];
        strcpy(arrToPrint, intro);
        strcat(arrToPrint, projectAuthor);
        Paint_DrawString_EN(cursor.X, cursor.Y, arrToPrint, &Font8, EPD_7IN3F_GREEN, EPD_7IN3F_WHITE);
};

void draw_github_repo(paintcursor cursor){
    char intro[] = "GitHub: ";
        char arrToPrint[strlen(intro) + strlen(projectGithubdir)];
        strcpy(arrToPrint, intro);
        strcat(arrToPrint, projectGithubdir);
        Paint_DrawString_EN(cursor.X, cursor.Y, arrToPrint, &Font8, EPD_7IN3F_GREEN, EPD_7IN3F_WHITE);
};


void draw_project_info( sFONT *Font, bool includeVersion, bool includeAuthor, bool includeGitHub){
    paintcursor cursor;
    cursor.X = EXTRA_MODULES_X_OFFSET;
    cursor.Y = 0;
    int bottomOfTopBar = (DOW_GRID_Y_OFFSET-DOW_GRID_HEADER_HEIGHT - 2);
    Paint_DrawRectangle(cursor.X, cursor.Y, EPD_7IN3F_WIDTH, bottomOfTopBar, EPD_7IN3F_GREEN, DOT_PIXEL_2X2, DRAW_FILL_FULL);
    cursor.X += 2;
    Paint_DrawString_EN(cursor.X, cursor.Y, projectName, &Font16, EPD_7IN3F_GREEN, EPD_7IN3F_WHITE);
    cursor.Y += 16;

    if(includeAuthor && includeGitHub){
        cursor.Y = (bottomOfTopBar - 19);
        draw_author_name(cursor);
        cursor.Y += 9;
        draw_github_repo(cursor);
    } else {
        cursor.Y = (bottomOfTopBar - 9);
        if(includeAuthor){
            draw_author_name(cursor);
        }
        else if (includeGitHub)
        {
           draw_github_repo(cursor); /* code */
        };
        
    };
    
}

