#ifndef WALL_H
#define WALL_H

#include <Box.h>


class Wall : public Box
{
    public:
        Wall(int X, int Y);
        bool IsAvailable();
        char DisplayBox();
    protected:
    private:
};

#endif // WALL_H
