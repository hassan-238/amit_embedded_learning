#ifndef CMD_HELPER_H
#define CMD_HELPER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void PressEnterToContinue()
{
    // ClearBuffer();
    printf("Press Enter to Continue...\n");
    char c = getchar();
    while (c != '\n')
        c = getchar();
}
static void ClearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear")
#endif
}

static char *GetString()
{
    static char buffer[256] = {0};
    fgets(buffer, sizeof(buffer), stdin);
}

static void PrintMenuTitle(const char *str)
{
    const static int HORIZONTAL_PADDING = 1;
    const static int VERTICAL_PADDING = 1;
    const static char* VERTICAL_WALLS = "|";
    const static char* HORIZONTAL_WALLS = "=";
    int width = strlen(str) + HORIZONTAL_PADDING * 2 + 2;

    for (int i = 0; i < width; i++)
    {
        printf(HORIZONTAL_WALLS);
    }
    printf("\n");
    for (int h = 0; h < VERTICAL_PADDING; h++)
    {
        for (int i = 0; i < width; i++)
        {
            printf((i == 0 || i == width - 1) ? VERTICAL_WALLS : " ");
        }
        printf("\n");
    }

    printf(VERTICAL_WALLS);
    for (int i = 0; i < HORIZONTAL_PADDING; i++)
    {
        printf(" ");
    }
    printf(str);
    for (int i = 0; i < HORIZONTAL_PADDING; i++)
    {
        printf(" ");
    }
    printf("%s\n",VERTICAL_WALLS);


    for (int h = 0; h < VERTICAL_PADDING; h++)
    {
        for (int i = 0; i < width; i++)
        {
            printf((i == 0 || i == width - 1) ? VERTICAL_WALLS : " ");
        }
        printf("\n");
    }
    
    for (int i = 0; i < width; i++)
    {
        printf(HORIZONTAL_WALLS);
    }
    printf("\n");
}

#endif