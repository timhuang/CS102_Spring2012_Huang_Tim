#ifndef ENEMY_H_
#define ENEMY_H_

#include <QImage>
#include <QRect>
#include "player.h"

class Enemy {
 protected:
  int xdir;
  int ydir;
  QImage image;
  QRect rect;
 public:
  Enemy();
  Enemy(int x, int y);
  ~Enemy();
  void up(int);
  void down(int);
  void left(int);
  void right(int);
  QRect getRect();
  QImage & getImage();

};
#endif
