#include "Console.h"
#include <iostream>
#include <windows.h>
#include "piece.h"
#include "player.h"
#include <array>
#include <list>
#include "wall.h"
#include <conio.h>




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

void ConsoleScreen::PutCh(int2 _pos, char _char)
{
    ArrScreen[_pos.y][_pos.x] = _char;
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

void ConsoleScreen::set_wall(wall& _wall)
{
    std::array<int2, 10> wall_array = _wall.get_wall();
    for (int i=0; i < 10; ++i)
    {
        int2 wall_pos = wall_array[i];
        PutCh(wall_pos, 'x');
    }
    

}

void ConsoleScreen::set_piece(piece& _piece, wall& _wall)
{
    int current = _piece.get_current();
    std::array<int2, 10> _piece_array = _piece.get_array();
    std::array<int2, 10> _wall_array = _wall.get_wall();
    bool same_loc = true;
    while (same_loc)
    {
        same_loc = false;
        for (int i = 0; i < 10; ++i)
        {
            if (_piece_array[current] == _wall_array[i])
                same_loc = true;
        }
        if (same_loc)
        {
            current = _piece.another_current();
        }
        
    }
    PutCh(_piece_array[current], 'o');


}

void ConsoleScreen::set_player(player& _player)
{
    std::list<int2> _player_list = _player.get_player_list();
    std::list<int2>::iterator StartIter = _player_list.begin();
    std::list<int2>::iterator EndIter = _player_list.end();


    for (; StartIter.operator!=(EndIter); ++StartIter)
    {
        PutCh(*StartIter, 'A');
    }
}



void ConsoleScreen::set()
{
    piece _piece = piece();
    player _player = player();
    wall _wall = wall();

    while (_player.Checklive())
    {
        set_wall(*_wall);
        set_piece(*_piece, *_wall);
        set_player(*_player);
        for (size_t y = 0; y < YLine; y++)
        {
            printf_s(ArrScreen[y]);
            printf_s("\n");
        }
        Sleep(300);
        system("cls");

        clear();
        if (0 != _kbhit())
        {
            _player.get_input(*_piece, *_wall);
        }
        _player.move(*_piece, *_wall);

    }
    printf_s("Game Ends.\n");
    printf_s("For exit, press any key.\n");

    char Select = (char)_getch();
}
