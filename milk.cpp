#include "milk.h"

Milk::Milk(int x, int y) : Food(x,y)
{
    image.load(":/icons/images/Milk.png");
    rect = image.rect();
    rect.translate(x,y);
}
Milk::~Milk()
{

}
