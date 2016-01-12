#ifndef MAZE_H
#define MAZE_H
#include <Box.h>
#include <Robot.h>
#include <vector>
#include <string>
#include <RobotP.h>

using namespace std;

class Maze
{
    public:
         Maze(const char *fileMaze, bool pledge); //Create a maze, if pledge is true, use the pledge algorithm
         void Display(); //Display the maze in the console
         void Add(Box *c);  //Add a box to the matrix of the maze
         bool Play();  //Play means moving the robot
         void DisplayListMooves();  //Display the list of moves made by the robot
         void TotalCost();
         RobotP *robotP = NULL;  //an instance if Pledge robot
         Robot *robot = NULL;  //an instance of the robot

    protected:
    private:
        int counterLigne = -1;  //the number of line in the maze
        int counterColumn =0;
        int limit = 200; //the limit of the maze size
        std::vector<std::vector<Box*> > matrix; //the matrix which contains the boxes.



};
#endif // MAZE_H
