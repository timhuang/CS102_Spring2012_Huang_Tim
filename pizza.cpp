#include "pizza.h"

Pizza::Pizza(int x, int y) : Food( x, y)
{
  image.load(":/icons/images/Pizza.png");
  eaten = FALSE;
  rect = image.rect();
  rect.translate(x,y);
}
Pizza::~Pizza()
{
}

