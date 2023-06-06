#pragma once
#include "InitialClass.h"


class piece;
class player;
class wall;
class ConsoleScreen
{
public:
    ConsoleScreen(char _BaseCh);
    void clear();
    void PutCh(int2 _pos, char _char);
    void set_wall(wall& _wall);
    void set_piece(piece& _piece, wall&_wall);
    void set_player(player& _player);
    void set();


    
private:
    char BaseCh = '*';
    char ArrScreen[YLine][XLine + 1] = {};

};

