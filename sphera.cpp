#include "sphera.h"

Sphera::Sphera(int x, int y) : Enemy(x,y)
{
    image.load(":/icons/images/Sphera.png");
    rect = image.rect();
    rect.translate(x,y);
    pattern = 1;
}
Sphera::~Sphera()
{
}

int Sphera::coordX(){
    cx = rect.left() + 37/2;
    return cx;
}
int Sphera::coordY(){
    cy = rect.bottom() - 37/2;
    return cy;
}
void Sphera::move(){
    //AI movement pattern
    if(pattern==1){
        rect.translate(-3,0);
        if(rect.left() <= 20)
            pattern ++;
    }
    if(pattern==2){
        rect.translate(0,-3);
        if(rect.top()<= 425)
            pattern++;
    }
    if(pattern == 3){
        rect.translate(3,0);
        if(rect.right()>=330)
            pattern++;
    }
    if(pattern == 4){
        rect.translate(0,3);
        if(rect.bottom()>=605)
            pattern++;
    }
    if(pattern == 5){
        rect.translate(3, 0);
        if(rect.right()>=580)
            pattern++;
    }
    if(pattern == 6){
        rect.translate(0,3);
        if(rect.bottom()>=685)
            pattern=1;
    }
}
