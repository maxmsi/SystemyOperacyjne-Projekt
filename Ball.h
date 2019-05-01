#ifndef BALL_H
#define BALL_H

class Ball
{
private:

public:
    int previousX;
    int previousY;
    int currentX;
    int currentY;
    int helpX;
    int helpY;

    double angleX;
    double angleY;
    int speed;
    double direction;
    int id;
    void ballNextPos();
    Ball(int number);
    ~Ball();
};


#endif
