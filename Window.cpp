#include <iostream>
#include <ncurses.h>
#include "Window.h"
#include "Balls.h"

window::~window()
{
        endwin();

}

window::window(){

    prepareWindow();
    drawWindow();
}

void window::prepareWindow(){
    initscr(); // rozpoczęcie trybu curses
    noecho();  // wylaczenie efektu echa
    curs_set(0); // wylaczenie kursora
    clear();     // wyczyszczenie ekranu
    refresh(); // wypisanie na ekranie
}
void window::printSymbol(int x, int y){
    move(y,x);
    printw("O");
}

void window::clearPreviousSymbol(int x, int y){
    move(y,x);
    printw(" ");
}
void window::drawWindow(){

    int xsize=0,ysize=0;
    getmaxyx(stdscr,ysize, xsize);



    for(int i = 0; i < xsize; i++)
    {
        //rysowanie kolumn
	
        move(0,i);
        printw("-");
	move(ysize-1,i);
        printw("~");

    }

    for(int i = 0; i < xsize; i++)
    {
        //rysowanie wierszy
        move(i,0);
        printw("|");
	move(i,xsize-1);
        printw("|");
    }
     refresh();
}

void window::updateWindow(Balls vecballs){
    drawWindow();
    for(int i = 0; i < vecballs.quantityofballs; i++)
       {
               //rysowanie kulek

               clearPreviousSymbol(vecballs.ballsInWindow[i].previousX,vecballs.ballsInWindow[i].previousY);

                if(vecballs.ballsInWindow[i].helpX==vecballs.ballsInWindow[i].currentX && vecballs.ballsInWindow[i].helpY!=vecballs.ballsInWindow[i].currentY)
                {continue;}
                else if(vecballs.ballsInWindow[i].helpX==vecballs.ballsInWindow[i].previousX && vecballs.ballsInWindow[i].helpY==vecballs.ballsInWindow[i].previousY)
                    {
                        clearPreviousSymbol(vecballs.ballsInWindow[i].previousX,vecballs.ballsInWindow[i].previousY);
                        printSymbol(vecballs.ballsInWindow[i].currentX, vecballs.ballsInWindow[i].currentY);
                        refresh();
                     vecballs.ballsInWindow[i].helpX = vecballs.ballsInWindow[i].currentX;
                     vecballs.ballsInWindow[i].helpY = vecballs.ballsInWindow[i].currentY;
                }
                  else  {
                         clearPreviousSymbol(vecballs.ballsInWindow[i].helpX,vecballs.ballsInWindow[i].helpY);
                         printSymbol(vecballs.ballsInWindow[i].currentX, vecballs.ballsInWindow[i].currentY);
                         refresh();
                      vecballs.ballsInWindow[i].helpX = vecballs.ballsInWindow[i].currentX;
                      vecballs.ballsInWindow[i].helpY = vecballs.ballsInWindow[i].currentY;

                     }


    }
}
