#include "Passage.h"

Passage::Passage(int X,int Y, bool  Exit)
    :Box(X,Y), exit(Exit)
{
    //ctor
}

char Passage::DisplayBox()
{
    if(exit){return 'F';}
    else{
    return ' ';}
}
bool Passage::IsAvailable()
{

    return true;
}

bool Passage::EndGame()
{
   return exit;
}
