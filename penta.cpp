#include "penta.h"

Penta::Penta(int x, int y) : Enemy(x, y)
{
    image.load(":/icons/images/Penta.png");
    rect = image.rect();
    rect.translate(x,y);
    pattern = 1;
}
Penta::~Penta()
{
}
void Penta::patrol(){
    if(pattern==1)
    {
        rect.translate(0,-2);
        if(rect.top() <= 500){
            pattern++;
        }
    }
    if(pattern==2)
    {
        rect.translate(2,0);
        if(rect.right()>=1000){
            pattern++;
        }
    }
    if(pattern==3)
    {
        rect.translate(-2,0);
        if(rect.left()<=800){
            pattern++;
        }
    }
    if(pattern==4)
    {
        rect.translate(0,2);
        if(rect.bottom()>=700){
            pattern = 1;
        }
    }
}
