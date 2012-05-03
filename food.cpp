#include "food.h"

Food::Food(int x, int y)
{
}
Food::~Food()
{
}

QRect Food::getRect(){
  return rect;
}
QImage & Food::getImage(){
  return image;
}
bool Food::isEaten(){
  return eaten;
}
void Food::setEaten(bool eat){
  eaten = eat;
}
void Food::setRect(QRect rct)
{
  rect = rct;
}

