#include "Box.h"
#include <stdlib.h>
#include "exception"

Box::Box(int Y, int X)
    :y(Y), x(X)
{

}

int Box::GetX()
{
    return x;
}

int Box::GetY()
{
    return y;
    }

char Box::DisplayBox()
{

}



bool Box::IsAvailable()
{

}
bool Box::EndGame()
{

}

char Box::Compare(Box* box)
{
    if (box -> GetY() > this->y)
    {
        return 'U';
    }
    else if (box -> GetY() < this->y)
    {
        return 'D';
    }
    else if (box -> GetX() > this->x)
    {
        return 'L';
    }
    else if (box -> GetX() < this->x)
    {
        return 'R';
    }
    else {return 'e';}

}


