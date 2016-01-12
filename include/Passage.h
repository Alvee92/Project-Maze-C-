#ifndef PASSAGE_H
#define PASSAGE_H

#include <Box.h>


class Passage : public Box
{
    public:
        Passage(int X, int Y, bool  Exit);
        char DisplayBox();
        bool IsAvailable();
        bool EndGame();


    protected:

    private:
        bool exit;  //A boolean to know if it's an exit.

};

#endif // PASSAGE_H
