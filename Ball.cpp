#include "Ball.h"
#include <cstdlib>
#include "ncurses.h"
#include <iostream>
#include <ncurses.h>
#include "Window.h"
#include "Balls.h"

        void Ball::ballNextPos()
	{
	    int xsize,ysize = 0;
	    // uzyskanie rozmiaru terminala
	    getmaxyx(stdscr,ysize,xsize);

            int tmpX = currentX;
            int tmpY = currentY;



                    if (tmpX + angleX > xsize -2) {
                        tmpX = xsize -1;
		        angleX = -angleX;
		    }
		    
		    if ( tmpX + angleX < 1) {
		        tmpX = 1;
		        angleX = -angleX; 
		    }
		    
		    else
		    {
                        tmpX = tmpX + angleX ;
		    }

		    
                    if (tmpY + angleY > ysize - 2) {
                        tmpY = ysize - 3;
                        angleY = -angleY;
		    }
		   
                    if ( tmpY + angleY <= 1) {
                        tmpY = 1;
                        angleY = -angleY;
                    }

                    else
                    {

                        tmpY=tmpY + angleY;
                    }


	    previousX = currentX;
	    previousY = currentY;
            currentX = tmpX;
	    currentY = tmpY;

	}



	Ball::Ball(int number){
	    int yScreen = 0,xScreen = 0;
	    getmaxyx(stdscr,yScreen,xScreen);
            currentX = xScreen/2;
            currentY = yScreen/2;
            angleX = -(rand()%7-3);
            angleY = 1;
            id = number;
            previousX =0;
            previousY =0;
            direction=angleX;
            helpX=-1;
            helpY=-1;


}
        Ball::~Ball(){

        }
