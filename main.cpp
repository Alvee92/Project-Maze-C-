#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Maze.h>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>


using namespace std;

void Menu1(bool *pledge);
void Menu2(const char** mazefile);
void Menu3(bool *step);
int main()
{

    bool endgame = false ;
    const char *MazeFile = "mazedefault.txt";
    bool Pledge = false;
    bool Step = true;


while(true)
{


    Menu1(&Pledge);
    Menu2(&MazeFile);
    Menu3(&Step);
    try{
    Maze maze(MazeFile,Pledge);




    while(!endgame)
    {
    system("cls");
    endgame = maze.Play();
    if(Step)
    {
        maze.Display();
        system("pause");
        _sleep(500);
    }


    }

system("cls");
maze.Display();
maze.DisplayListMooves();
cout<<'\n';
maze.TotalCost();

system("pause");
endgame = false;

    }
 catch(string const& chaine)
    {
        cerr << chaine << endl;
        return 0;
    }

}
    return 0;
}

void Menu1(bool *pledge)
{
    system("cls");
    char selection;

cout<<"\nChoose the robot";
cout<<"\n================";
cout<<"\n 1 - Pledge robot";
cout<<"\n 2 - Classical robot";
cout<<"\n\n Enter selection: ";
// read the input
cin>>selection;

switch(selection)
{
case '1' :
    {
        *pledge = true;

    }
break;
case '2' :
    {
        *pledge = false;

    }
break;
default : cout<<"\n Invalid selection";
}
cout<<"\n";
}

void Menu2(const char** mazefile)
{
    system("cls");
    char selection;

cout<<"\nChoose the maze";
cout<<"\n===============";
cout<<"\n 0 - Default maze";
cout<<"\n 1 - Short maze 1";
cout<<"\n 2 - Short maze 2";
cout<<"\n 3 - Medium maze";
cout<<"\n 4 - Huge maze 1";
cout<<"\n 5 - Huge maze 2";
cout<<"\n 6 - Huge maze 3";
cout<<"\n\n Enter selection: ";
// read the input
cin>>selection;

switch(selection)
{
case '0' :
    {
        *mazefile = "mazedefault.txt";

    }
break;

case '1' :
    {
        *mazefile = "maze1.txt";

    }
break;
case '2' :
    {
        *mazefile = "maze2.txt";

    }
break;
case '3' :
    {
        *mazefile = "maze3.txt";

    }
break;
case '4' :
    {
        *mazefile = "maze4.txt";

    }
break;
case '5' :
    {
        *mazefile = "maze5.txt";

    }
break;
case '6' :
    {
        *mazefile = "maze6.txt";

    }
break;
default : cout<<"\n Invalid selection";
}
cout<<"\n";
}

void Menu3(bool *step)
{
    system("cls");
    char selection;

cout<<"\nChoose how you want to move the robot";
cout<<"\n=====================================";
cout<<"\n 1 - Automatic";
cout<<"\n 2 - Step by step (might be long)";
cout<<"\n\n Enter selection: ";
// read the input
cin>>selection;

switch(selection)
{
case '1' :
    {
        *step = false;

    }
break;
case '2' :
    {
        *step = true;

    }
break;
default : cout<<"\n Invalid selection";
}
cout<<"\n";
}
