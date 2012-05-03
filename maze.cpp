#include "maze.h"

Maze::Maze()
{
    //Different maze pieces

    image[0].load(":/icons/images/Maze1.png");
    image[1].load(":/icons/images/Maze2.png");
    image[2].load(":/icons/images/Maze3.png");
    image[3].load(":/icons/images/Maze4.png");

    for(int i = 0; i<4; i++)
    {
        rect[i] = image[i].rect();
    }
    for(int i=4; i <8; i++)
    {
        rect[i] = image[i-4].rect();
    }
    for(int i=8; i<12; i++)
    {
        rect[i] = image[i-8].rect();
    }
    rect[0].translate(90,65);
    rect[1].translate(90,90);
    rect[2].translate(200,480);
    rect[3].translate(100,480);
    rect[4].translate(200,610);
    rect[5].translate(570,5);
    rect[6].translate(460,390);
    rect[7].translate(460,390);
    rect[8].translate(1000,0);
    rect[9].translate(750,116);
    rect[10].translate(700,530);
    rect[11].translate(600,390);
}

Maze::~Maze()
{
}
QRect Maze::getRect(int i){
  return rect[i];
}
QImage & Maze::getImage(int i){
  return image[i];
}
