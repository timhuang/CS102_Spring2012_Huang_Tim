
#ifndef PLAYER_H_
#define PLAYER_H_

#include <QImage>
#include <QRect>
#include "maze.h"

class Player{
private:
  int xdir;
  int ydir;
  int speed;
  bool collide;
  QImage image;
  QRect rect;
  Maze maze;
 public:
  Player();
  ~Player();
  void reset();
  void up(int);
  void down(int);
  void left(int);
  void right(int);
  int getX();
  int getY();
  int getXDir();
  int getYDir();
  void setXDir(int);
  void setYDir(int);
  bool wall_left();
  bool wall_right();
  bool wall_top();
  bool wall_bottom();
  QRect getRect();
  QImage & getImage();
};
#endif

