#ifndef ROBOTP_H
#define ROBOTP_H
#include <Box.h>
#include <vector>
#include <Robot.h>

class RobotP : public Robot
{
    public:
        RobotP(int X, int Y);
        char DisplayRobot();
        bool Moove(int counterColumn,int counterLigne,std::vector<std::vector<Box*> > matrix);
        void RotationR();    //Rotate the robot
        void RotationL();
        int counter = 0;   //The counter used in the Pledge algorithm

    protected:
    private:
        int orientation = 0;  //We use an int to know in which position is the robot (North, South Est or West)




};

#endif // ROBOTP_H
