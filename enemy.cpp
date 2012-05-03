#include "enemy.h"

Enemy::Enemy(int x, int y)
{
}
Enemy::~Enemy()
{
}
QRect Enemy::getRect()
{
  return rect;
}
QImage & Enemy::getImage()
{
  return image;
}

