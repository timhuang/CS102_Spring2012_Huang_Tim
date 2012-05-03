#ifndef MAZE_H_
#define MAZE_H_

#include <QImage>
#include <QRect>

class Maze{
 private:
  QImage image[4];
  QRect rect[12];
 public:
  Maze();
  ~Maze();
  QRect getRect(int);
  QImage & getImage(int);
};

#endif
