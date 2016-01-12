#include "Wall.h"

Wall::Wall(int X, int Y)
    :Box(X,Y)
{

}

char Wall::DisplayBox()
{
    return '#' ;
}

bool Wall::IsAvailable()
{
    return false;
}
