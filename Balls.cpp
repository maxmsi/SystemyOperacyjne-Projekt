#include "Balls.h"



Balls::Balls(){
    quantityofballs = 0;
}

Balls::~Balls(){
    ballsInWindow.clear();
}

void Balls::addBall(){


    ballsInWindow.push_back(Ball(quantityofballs++));
}
