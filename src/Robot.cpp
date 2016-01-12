#include "Robot.h"
#include <Robot.h>
#include <Box.h>
#include <Passage.h>
#include "exception"
#include <string>
#include <iostream>
#include <stdlib.h>


using namespace std;

Robot::Robot(int Y, int X)
    :y(Y), x(X)
{
    //ctor
}


int Robot::GetX()
{
    return x;
}

int Robot::GetY()
{
    return y;
}
char Robot::DisplayRobot()
{
    return 'r';
}

void Robot::AddToStack(Box* c)
{
   Stack.push(c) ;
}


void Robot::AddToList(Box* c)
{
    ListBoxes.push_back(c);
}

void Robot::AddToListMooves(char c)
{
    ListMooves.push_back(c);
}

bool Robot::Moove(int counterColumn,int counterLigne,std::vector<std::vector<Box*> > matrix)
{
    //A simple algorithm, trying first to go right then down, left and up.
    bool endgame = false;
    if(x+1<counterColumn&&(!this->HasPassed((matrix.at(y).at(x+1))))&&matrix.at(y).at(x+1)->IsAvailable())
            {
            Box* c = matrix.at(y).at(x+1);

                 x = x+1;
                 endgame = c->EndGame();
                 this -> AddToList(c);
                 this-> AddToStack(c);
                 this -> AddToListMooves('R');
                 this -> AddCash();

            }

        else if(y+1<counterLigne&&(!this->HasPassed((matrix.at(y+1).at(x))))&&matrix.at(y+1).at(x)->IsAvailable())
        {
            Box* c = matrix.at(y+1).at(x);

                 y = y+1;
                 endgame = c->EndGame();
                 this -> AddToList(c);
                 this-> AddToStack(c);
                 this -> AddToListMooves('D');
                 this -> AddCash();

        }
        else if(x-1>=0&&(!this->HasPassed((matrix.at(y).at(x-1))))&&matrix.at(y).at(x-1)->IsAvailable())
        {
            Box* c = matrix.at(y).at(x-1);

                 x = x-1;
                 endgame = c->EndGame();
                 this -> AddToList(c);
                 this-> AddToStack(c);
                 this -> AddToListMooves('L');
                 this -> AddCash();

        }

        else if(y-1>=0&&(!this->HasPassed((matrix.at(y-1).at(x))))&&matrix.at(y-1).at(x)->IsAvailable())
        {
            Box* c = matrix.at(y-1).at(x);

                 y = y-1;
                 endgame = c->EndGame();
                 this -> AddToList(c);
                 this-> AddToStack(c);
                 this -> AddToListMooves('U');
                 this -> AddCash();

        }

        else //If the robot is stuck:
        {
            try{Box* lastbox = this -> Return(); //It tries to go to the last box

            Box* currentbox = new Box(this->GetY(), this ->GetX());
            this -> AddToListMooves(lastbox->Compare(currentbox));  //This method give the movement of the robot while returning
                                                                    //U, R, D, L
            x=lastbox-> GetX();  //Move the robot
            y= lastbox->GetY();

            this -> AddCash();
            }
            catch(std::string const& chaine)
    {
        cerr << chaine << endl;
       endgame = true;
        }
    }
    return endgame;
}


bool Robot::HasPassed(Box* c)
{
    bool result = false;
   for(int counterBox= 0; counterBox < ListBoxes.size(); counterBox++)
   {
       if((ListBoxes.at(counterBox)->GetX() == c->GetX())&&ListBoxes.at(counterBox)->GetY() == c->GetY())
       {
           result = true;
       }
   }
    return result;

}

Box* Robot::Return()
{
    //This method forces the robot to go to the last boxes it visited
       Stack.pop();
    if(Stack.empty())
    {
         throw std::string("The robot is stuck.\nThere might be no exit in the maze.\n");
    }


return Stack.top();

}

int Robot::GetPrice()
{
    return price;
}
void Robot::AddCash()
{
    price++;
}
