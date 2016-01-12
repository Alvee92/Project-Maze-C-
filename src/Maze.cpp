#include "Maze.h"
#include <Robot.h>
#include <Box.h>
#include <Passage.h>
#include <Wall.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "exception"
#include <RobotP.h>

using namespace std;

Maze:: Maze(const char *fileMaze,bool pledge)
{
    string contents;
    string sentence;
    int ligne, column;
    const char* filename ;
    filename = fileMaze;


    ifstream file(fileMaze, ios::in); //First read the maze file

     if(file)
    {

        file >> ligne >> column;
        if(ligne<0 || ligne>limit || column <0 || column >limit)
        {
            throw std::string("The maze file is not correct, or the maze is too big.\nMake sure that the number of lines and columns appears a the top of the file.\nMake sure that the maze is not bigger than 100x100.\n");
        }
        matrix.resize(ligne);
        for(int i =0; i<ligne;i++)
    {
       matrix.at(i).resize(column);
       }
    }

        //Then for each character read the maze will create an associated box (wall or passage) and add it to the matrix
        //the same for the robot
        while (getline(file, contents))
        {


        if((contents.length()< column && counterLigne != -1) )
        {
            throw std::string("The maze file is incorrect.\nA line might be incomplete.\n");
        }

            for( counterColumn = 0; counterColumn< contents.length();counterColumn++)
                       {

                switch(contents[counterColumn])
                {
                case 'X':
                case '+':
                case '-':
                case '|':
                    {

                        try{
                        Wall *wall = new Wall(counterLigne, counterColumn );
                        Add(wall);
                        }
                        catch(exception e){}

                    }
                    break;

                case ' ':
                    {
                        try{
                        Passage *passage = new Passage(counterLigne,counterColumn,false);
                        Add(passage);
                        }
                        catch(exception e){}
                    }
                    break;

                     case 'F':
                    {

                        Passage *p = new Passage(counterLigne,counterColumn,true);
                        Add(p);
                    }
                    break;

                     case 'S':
                    {

                        Passage *p = new Passage(counterLigne,counterColumn,false);
                        Add(p);
                        bool test = pledge;

                        if(pledge)
                        {
                           robotP= new RobotP(counterLigne,counterColumn);
                           robotP->AddToStack(p);
                        robotP->AddToList(p);
                        }
                        else{
                                robot= new Robot(counterLigne,counterColumn);
                        robot->AddToStack(p);
                        robot->AddToList(p);}

                    }
                      break;


                     default :
                        throw std::string ("There is a bad character in the maze file.\nOnly X, S, F and spaces are tolerated.\n");


                }

            }
    counterLigne++;
        }

        file.close();

        if(robot == NULL && robotP == NULL)
        {
            throw std::string ("There is no robot in the maze.\n");
        }

    }





void Maze::Display()
{
    //Display the boxes and the robot of the maze
    char c;


    for(int i =0; i< matrix.size(); i++)
    {
        for(int j = 0; j<matrix.at(i).size(); j++)
        {

            try{
            c = matrix.at(i).at(j)->DisplayBox();
            }
            catch(exception e){}

        if(robotP == NULL){
            if((robot->GetX() == j)&&(robot->GetY() == i))
                {
                    c = robot->DisplayRobot();
                }
        }
        else
        {
            if((robotP->GetX() == j)&&(robotP->GetY() == i))
                {
                    c = robotP->DisplayRobot();
                }
        }
            cout<<c;

        }
        cout<<"\n";
    }



}


void Maze::Add(Box *c)
{
    try{
     matrix.at(c->GetY()).at(c->GetX())=c;
    }
    catch(exception e){}
}


bool Maze::Play()   //this method just consists in moving the robot
{
    if(robotP ==NULL)
    {
        return robot-> Moove(counterColumn, counterLigne, matrix);
    }
    else
    {
      return robotP-> Moove(counterColumn, counterLigne, matrix);

    }
}



void Maze::DisplayListMooves() //Display the moves of the robot
{
    int i;
    cout <<"\n \n";
    if(robotP ==NULL)
    {
        for(i = 0; i<robot->ListMooves.size();i++)
{
    cout<<robot->ListMooves.at(i)<< ' ';
}
    cout <<"\n";
    }
    else
    {
        for(i = 0; i<robotP->ListMooves.size();i++)
{
    cout<<robotP->ListMooves.at(i)<< ' ';
}
    cout <<"\n";
    }
}

void Maze::TotalCost() //Give the total cost of the robot
{

    if(robotP ==NULL)
    {
            cout<<"The total cost is "<< robot -> GetPrice() << '$'<<"\n \n";
    }
    else
    {
        cout<<"The total cost is "<< robotP -> GetPrice() << '$'<<"\n \n";
    }
}
