#pragma once

const int XLine = 40;
const int YLine = 20;
class ConsoleScreen
{
public:
    ConsoleScreen(char _BaseCh);
    void set() const;

    void turnoff()
    {
        OnOff = false;
    }







    
private:
    char BaseCh = '*';
    char ArrScreen[YLine][XLine + 1] = {};
    bool OnOff = true;
};

