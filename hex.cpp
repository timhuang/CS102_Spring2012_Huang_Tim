#include "hex.h"

Hex::Hex(int x, int y) : Enemy(x,y)
{
    image.load(":/icons/images/Hex.png");
    rect = image.rect();
    rect.translate(x,y);
}
Hex::~Hex()
{
}
