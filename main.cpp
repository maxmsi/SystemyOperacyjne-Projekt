#include <iostream>
#include <ncurses.h>
#include <vector>
#include <time.h>
#include <thread>
#include <unistd.h>
#include "Balls.h"
#include "Window.h"

using namespace std;

bool Runs = true;
window Window;
Balls balls;


void ballThreadFunction(int BallId){

    while(Runs){
        usleep(49500);
        balls.ballsInWindow[BallId].ballNextPos();
    }
}
void updateWindowTh(){
    while(Runs){
        usleep(10);
        Window.updateWindow(balls);
    }
    usleep(10000);
    endwin();
}
void exitTh(){
    while(Runs){
        char key = getch();
        if(key == 'x')
        Runs = false;
    }
    //usleep(100000);
}

int main(){
    
    unsigned ballscreated = 0;


    srand(time(NULL));
    vector<std::thread> ballsthreads;
    std::thread WindowThread(updateWindowTh);
    std::thread exitThread(exitTh);

    for(int i=0;i<10;i++)
    {

        balls.addBall();
        ballsthreads.push_back(std::thread(ballThreadFunction,i));
	ballscreated = i + 1;
        sleep(2);
        if(!Runs) break;

    }


    WindowThread.join();
    exitThread.join();
   for(int i = 0; i <ballscreated; i++)
    {
         ballsthreads[i].join();
    }
   while(Runs){}
   usleep(1000);
    return 0;
}


