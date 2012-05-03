#include "heal.h"

Heal::Heal(int x, int y) : Food(x,y)
{
    image.load(":/icons/images/Heal.png");
    eaten = FALSE;
    rect = image.rect();
    rect.translate(x,y);
}
Heal::~Heal()
{

}
