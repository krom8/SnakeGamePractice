#include "player.h"
#include "piece.h"
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
