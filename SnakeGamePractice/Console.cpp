#include "Console.h"
#include <iostream>
#include <windows.h>
#include "piece.h"
#include "player.h"


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

void ConsoleScreen::clear()
{
    for (size_t y = 0; y < YLine; y++)
    {
        for (size_t x = 0; x < XLine; x++)
        {
            ArrScreen[y][x] = BaseCh;
        }
        ArrScreen[y][XLine] = 0;
    }
}

void ConsoleScreen::set_piece(piece&)
{

}

void ConsoleScreen::set_player(player&)
{

}

void ConsoleScreen::set()
{
    piece _piece = piece();
    player _player = player();

    while (_player.Checklive())
    {
        clear();
        _player.get_input(*_piece);
        set_piece(*_piece);
        set_player(*_player);
        for (size_t y = 0; y < YLine; y++)
        {
            printf_s(ArrScreen[y]);
            printf_s("\n");
        }
        Sleep(300000);
        system("cls");
    }
}
