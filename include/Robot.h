#ifndef ROBOT_H
#define ROBOT_H
#include <Box.h>
#include <vector>
#include <stack>
#include <string>


class Robot
{
    public:
      Robot(int Y, int X);
    int GetX();
    int GetY();
    void AddToStack(Box* c);       //Add a box to the stack of the robot
    void AddToList(Box* c);        //Add a box to the list of the robot
    void AddToListMooves(char c);  //When the robot goes up down right or left, it is registered in a vector
    char DisplayRobot();           //Display the robot on the console
    bool Moove(int counterColumn,int counterLigne,std::vector<std::vector<Box*> > matrix);  //Move the robot.
    bool HasPassed(Box* c);        //Return true or false if the robot has passed or not on the box
    int GetPrice();
    void AddCash();
    Box* Return();                 //if the robot is stuck, moves the robot on the box which is at the top of the stack
    std::vector <char> ListMooves;


    protected:

   int x;
   int y;
   int price = 0;  //The total cost for the moves
   private:

  std::stack<Box*> Stack;         //Contains all the boxes the robot has passed,  but it will be use if the robot is stuck
  std::vector <Box*> ListBoxes;  //Contains all the boxes the robot has passed
                                 // When the robot tries to move, it will avoid to go to already visited boxes.


};

#endif // ROBOT_H
