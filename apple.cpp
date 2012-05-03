#include "apple.h"

Apple::Apple(int x, int y) : Food( x, y)
{
  image.load(":/icons/images/Apple.png");
  eaten = FALSE;
  rect = image.rect();
  rect.translate(x,y);
}
Apple::~Apple()
{
}
