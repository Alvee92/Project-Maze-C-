#include "RobotP.h"
#include <Robot.h>
#include <string>
#include <Box.h>

using namespace std;

RobotP::RobotP(int X, int Y)
    :Robot(X,Y)
{
    //ctor0
}

char RobotP::DisplayRobot() //Return the letter of the orientation.
{
    if(orientation == 0)
    {
        return 'N';
    }
    else if (orientation == 1)
    {
        return 'E';
    }
    else if (orientation == 2)
    {
        return 'S';
    }
    else if (orientation == 3)
    {
        return 'W';
    }
    else
    {
        throw std::string ("There is an error in the orientation on the Pledge robot");
    }
}

bool RobotP::Moove(int counterColumn, int counterLigne, std::vector<std::vector<Box* > > matrix)
{
    //Moving the robot with the pledge algorithm.

    if(orientation == 0) //First all moves will be diferent regarding the orientation.
        {
        if (y-1>=0 && counter ==0 && matrix.at(y-1).at(x)-> IsAvailable()) //When the counter is 0, the robot goes forward until a wall
        {
            y--;
            price ++;
            AddToListMooves('U');
            return matrix.at(y).at(x)-> EndGame();
        }
        else if(counter < 0 )  // if the counter is negative
        {
            if(x-1 >=0 && matrix.at(y).at(x-1)->IsAvailable())  //try to turn left first
            {
                RotationL();
                x--;
                price ++;
                AddToListMooves('L');
                return matrix.at(y).at(x)-> EndGame();
            }
            else if(y-1>= 0&&matrix.at(y-1).at(x)-> IsAvailable()) //Else go forward
            {
                y--;
                price ++;
                AddToListMooves('U');
                return matrix.at(y).at(x)-> EndGame();
            }
            else if(x+1<counterColumn&&matrix.at(y).at(x+1)->IsAvailable()) //else try to turn right
            {
                RotationR();
                x++;
                AddToListMooves('R');
                price++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else //else go back
            {
                RotationL();
                RotationL();
                return matrix.at(y).at(x)-> EndGame();
            }

        }
        else if(counter >= 0 ) // if the counter is positive
        {
            if( x+1<counterColumn && matrix.at(y).at(x+1)-> IsAvailable()) //try to turn right
            {
                RotationR();
                x++;
                AddToListMooves('R');
                price ++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else if(y-1>= 0 && matrix.at(y-1).at(x)-> IsAvailable()) //else go forward
            {
                y--;
                price ++;
                AddToListMooves('U');
                return matrix.at(y).at(x)-> EndGame();
            }
            else if(x-1>= 0 && matrix.at(y).at(x-1)-> IsAvailable()) //else try to turn left
            {
                RotationL();
                x--;
                AddToListMooves('L');
                price++;
                return matrix.at(y).at(x)-> EndGame();

            }

                else //else go back
            {
                RotationR();
                RotationR();
                return matrix.at(y).at(x)-> EndGame();
            }


        }

    }


    else if(orientation == 1)
    {
        if (x+1< counterColumn && counter ==0 && matrix.at(y).at(x+1)-> IsAvailable()) //Go Forward first
        {
            x++;
            AddToListMooves('R');
            price ++;
            return matrix.at(y).at(x)-> EndGame();
        }
        else if(counter < 0 )  // if the counter is negative
        {
            if(y-1 >= 0 && matrix.at(y-1).at(x)->IsAvailable())  //try to turn left first
            {
                RotationL();
                y--;
                AddToListMooves('U');
                price ++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else if(x+1 < counterColumn && matrix.at(y).at(x+1)-> IsAvailable())
            {
                x++;
                AddToListMooves('R');
                price ++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else if(y+1 < counterLigne && matrix.at(y+1).at(x)->IsAvailable()) //else try to turn right
            {
                RotationR();
                y++;
                AddToListMooves('D');
                price++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else //else go back
            {
                RotationR();
                RotationR();
                return matrix.at(y).at(x)-> EndGame();
            }

        }
        else if(counter >= 0 ) // if the counter is positive
        {
            if(y+1 < counterLigne && matrix.at(y+1).at(x)-> IsAvailable()) //try to turn right
            {
                RotationR();
                y++;
                AddToListMooves('D');
                price ++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else if(x+1< counterColumn && matrix.at(y).at(x+1)-> IsAvailable())
            {
                x++;
                AddToListMooves('R');
                price ++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else if(y-1 >= 0 && matrix.at(y-1).at(x)-> IsAvailable()) //else try to turn left
            {
                RotationL();
                y--;
                AddToListMooves('U');
                price++;
                return matrix.at(y).at(x)-> EndGame();

            }

                else //else go back
            {
                RotationR();
                RotationR();
                return matrix.at(y).at(x)-> EndGame();
            }


        }

    }



    else if(orientation == 2)
    {
        if (y+1 < counterLigne && counter ==0 && matrix.at(y+1).at(x)-> IsAvailable()) //Go Forward first
        {
            y++;
            AddToListMooves('D');
            price ++;
            return matrix.at(y).at(x)-> EndGame();
        }
        else if(counter < 0 )  // if the counter is negative
        {
            if(x+1< counterColumn && matrix.at(y).at(x+1)->IsAvailable())  //try to turn left first
            {
                RotationL();
                x++;
                AddToListMooves('R');
                price ++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else if(y+1 < counterLigne && matrix.at(y+1).at(x)-> IsAvailable())
            {
                y++;
                AddToListMooves('D');
                price ++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else if(x-1 >= 0 && matrix.at(y).at(x-1)->IsAvailable()) //else try to turn right
            {
                RotationR();
                x--;
                AddToListMooves('L');
                price++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else //else go back
            {
                RotationR();
                RotationR();
                return matrix.at(y).at(x)-> EndGame();
            }

        }
        else if(counter>=  0 ) // if the counter is positive
        {
            if(x-1 >= 0 && matrix.at(y).at(x-1)-> IsAvailable() ) //try to turn right
            {
                RotationR();
                x--;
                AddToListMooves('L');
                price ++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else if(y+1 < counterLigne && matrix.at(y+1).at(x)-> IsAvailable())
            {
                y++;
                AddToListMooves('D');
                price ++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else if(x+1< counterColumn && matrix.at(y).at(x+1)-> IsAvailable()) //else try to turn left
            {
                RotationL();
                x++;
                AddToListMooves('R');
                price++;
                return matrix.at(y).at(x)-> EndGame();

            }

                else //else go back
            {
                RotationR();
                RotationR();
                return matrix.at(y).at(x)-> EndGame();
            }


        }

    }




else if(orientation == 3)
    {
        if (x-1 >= 0 && counter ==0 && matrix.at(y).at(x-1)-> IsAvailable()) //Go Forward first
        {
            x--;
            AddToListMooves('L');
            price ++;
            return matrix.at(y).at(x)-> EndGame();
        }
        else if(counter < 0 )  // if the counter is negative
        {
            if(y+1 < counterLigne && matrix.at(y+1).at(x)->IsAvailable())  //try to turn left first
            {
                RotationL();
                y++;
                AddToListMooves('D');
                price ++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else if(x-1 >= 0 && matrix.at(y).at(x-1)-> IsAvailable())
            {
                x--;
                AddToListMooves('L');
                price ++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else if(y-1 >= 0 && matrix.at(y-1).at(x)->IsAvailable()) //else try to turn right
            {
                RotationR();
                y--;
                AddToListMooves('U');
                price++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else //else go back
            {
                RotationR();
                RotationR();
                return matrix.at(y).at(x)-> EndGame();
            }

        }
        else if(counter >= 0 ) // if the counter is positive
        {
            if(y-1 >= 0 &&  matrix.at(y-1).at(x)-> IsAvailable()) //try to turn right
            {
                RotationR();
                y--;
                AddToListMooves('U');
                price ++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else if(x-1 >= 0 && matrix.at(y).at(x-1)-> IsAvailable())
            {
                x--;
                AddToListMooves('L');
                price ++;
                return matrix.at(y).at(x)-> EndGame();
            }
            else if(y+1 < counterLigne && matrix.at(y+1).at(x)-> IsAvailable()) //else try to turn left
            {
                RotationL();
                y++;
                AddToListMooves('D');
                price++;
                return matrix.at(y).at(x)-> EndGame();

            }

                else //else go back
            {
                RotationR();
                RotationR();
                return matrix.at(y).at(x)-> EndGame();
            }


        }

    }



    else
    {
        throw std::string ("There is an error while moving the robot");
    }


}

void RobotP::RotationR() //Rotate the robot
{
    if(orientation == 3)  //If the robot facing West
    {
        orientation = 0;  //Orientation goes to 0, so the robot will face North
        price +=2;
        AddToListMooves('r');
        counter --;
    }
    else if(orientation < 3 && orientation >=0) //Else just increase orientation
    {
        orientation++;
        price +=2;
        AddToListMooves('r');
        counter --;
    }
    else
    {
        throw std::string ("There is an error in the right rotation");
    }
}

void RobotP::RotationL()
{

    if(orientation == 0)
    {
        orientation = 3;
        price +=2;
        AddToListMooves('r');
        counter ++;

    }
    else if(orientation <= 3 && orientation >0)
    {
        orientation--;
        price +=2;
        AddToListMooves('r');
        counter ++;
    }
    else
    {
        throw std::string ("There is an error in the left rotation");
    }
}

