#pragma once
#include "InitialClass.h"


class piece;
class player;
class ConsoleScreen
{
public:
    ConsoleScreen(char _BaseCh);
    void clear();
    void set_piece(piece&);
    void set_player(player&);
    void set();

    
private:
    char BaseCh = '*';
    char ArrScreen[YLine][XLine + 1] = {};

};

