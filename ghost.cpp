#include "ghost.h"

Ghost::Ghost(int x, int y) : Enemy(x,y){
    image.load(":/icons/images/Ghost.png");
    rect = image.rect();
    rect.translate(x,y);
}

Ghost::~Ghost(){
}

void Ghost::chase(Player p)
{
    //The ghost follows the player
    if(p.getRect().x() > rect.x()) xdir = 1;
    if(p.getRect().x() < rect.x()) xdir = -1;
    if(p.getRect().y() > rect.y()) ydir = 1;
    if(p.getRect().y() < rect.y()) ydir = -1;
    rect.translate(xdir, ydir);
}
