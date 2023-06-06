#include "player.h"
#include "piece.h"
#include "wall.h"
#include <conio.h>

void player::get_input(piece& _piece, wall& _wall)
{
    char Select = (char)_getch();
    switch (Select)
    {
    case 'a':
        MovePos = int2({0, -1});
        break;
    case 'd':
        MovePos = int2({ 0, 1 });
        break;
    case 'w':
        MovePos = int2({ -1, 0 });
        break;
    case 's':
        MovePos = int2({ 1, 0 });
        break;
    default:
        break;
    }
}

void player::move(piece& _piece, wall& _wall)
{
    std::list<int2>::iterator StartIter = player_list.begin();
    std::list<int2>::iterator EndIter = player_list.end();

    int2 prev = *StartIter;
    *StartIter += MovePos;
    ++StartIter;
    for (; StartIter.operator!=(EndIter); ++StartIter)
    {
        int2 assign_prev = prev;
        prev = *StartIter;
        *StartIter = assign_prev;
        

    }
    check_piece(_piece);
    check_wall(_wall);
    crash();
}

void player::check_piece(piece& _piece)
{
    std::list<int2>::iterator StartIter = player_list.begin();
    std::list<int2>::iterator EndIter = player_list.end();
    std::array<int2, 10> piece_array = _piece.get_array();
    int current = _piece.get_current();
    if (*StartIter == piece_array[current])
    {
        int2 tail = int2({ (*StartIter).y - MovePos.y, (*StartIter).x - MovePos.x });
        ++StartIter;
        for (; StartIter.operator!=(EndIter); ++StartIter)
        {
            if (tail == *StartIter)
            {
                tail -= MovePos;
            }
        }
        player_list.push_back(tail);
        current = _piece.another_current();
    }
}

void player::check_wall(wall& _wall)
{
    std::list<int2>::iterator StartIter = player_list.begin();
    std::array<int2, 10> wall_array = _wall.get_wall();
    for (int i = 0; i < 10; ++i)
    {
        if (wall_array[i] == *StartIter)
            Die();
    }
    if ((*StartIter).x >= XLine || (*StartIter).x < 0)
    {
        Die();
    }
    if ((*StartIter).y >= YLine || (*StartIter).y < 0)
    {
        Die();
    }
}
void player::crash()
{
    std::list<int2>::iterator StartIter = player_list.begin();
    std::list<int2>::iterator Head = player_list.begin();
    std::list<int2>::iterator EndIter = player_list.end();
    ++StartIter;
    for (; StartIter.operator!=(EndIter); ++StartIter)
        if (*Head == *StartIter)
        {
            Die();
        }
}