#include "Console.h"
#include <iostream>
#include <windows.h>


ConsoleScreen::ConsoleScreen(char _BaseCh)
{
    BaseCh = _BaseCh;

    for (size_t y = 0; y < YLine; y++)
    {
        for (size_t x = 0; x < XLine; x++)
        {
            ArrScreen[y][x] = BaseCh;
        }
        ArrScreen[y][XLine] = 0;
    }
}

void ConsoleScreen::set() const
{
    while (OnOff)
    {
        for (size_t y = 0; y < YLine; y++)
        {
            printf_s(ArrScreen[y]);
            printf_s("\n");
        }
        Sleep(300000);
        system("cls");
    }
}
