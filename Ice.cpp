#include "ice.h"

Ice::Ice(int x, int y) : Food( x, y)
{
  image.load(":/icons/images/Ice.png");
  eaten = FALSE;
  rect = image.rect();
  rect.translate(x,y);
}
Ice::~Ice()
{
}
