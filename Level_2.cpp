#include "Level_2.h"

Level_2::Level_2(){
    image.load(":/icons/images/Level2.png");
    rect = image.rect();
    rect.translate(0,0);
}
Level_2::~Level_2(){
}
QRect Level_2::getRect(){
  return rect;
}
QImage & Level_2::getImage(){
  return image;
}
