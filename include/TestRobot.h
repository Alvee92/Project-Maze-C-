#ifndef TESTROBOT_H
#define TESTROBOT_H

#include <Robot.h>


class TestRobot : public Robot
{
    public:
        TestRobot(int X, int Y);
        virtual ~TestRobot();
    protected:
    private:
};

#endif // TESTROBOT_H
