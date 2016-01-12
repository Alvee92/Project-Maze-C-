#ifndef BOX_H
#define BOX_H


class Box
{
    public:
        Box(int Y, int X);
        virtual char DisplayBox();  //Display the box in the console
        virtual bool IsAvailable(); //Return true for a passage and false for a wall
        virtual bool EndGame();     //Return true if the box is an exit
        int GetX();
        int GetY();
        char Compare(Box* box);     //Compare a box to an other to know if it is above, below left or right.
                                    // this method is used for the Return method of the robot.

    protected:

    private:
        int x;
        int y;
};

#endif // BOX_H
