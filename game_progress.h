#ifndef GAME_H_
#define GAME_H_

#include "player.h"
#include "pizza.h"
#include "ghost.h"
#include "hex.h"
#include "ice.h"
#include "hp.h"
#include "Level_2.h"
#include "maze.h"
#include "apple.h"
#include "bullet.h"
#include "sphera.h"
#include "penta.h"
#include "milk.h"
#include <QWidget>
#include <QKeyEvent>
#include <QLabel>
#include <QString>
#include <QTimer>
#include <QImage>
#include <QRect>

class Game : public QWidget
{
  Q_OBJECT

 public:
  Game(QWidget * parent = 0);
  ~Game();
 protected:
  void paintEvent(QPaintEvent* event);
  void timerEvent(QTimerEvent *event);
  void keyPressEvent(QKeyEvent * event);

  void startGame();
  void stopGame();
  void pauseGame();
  void victory();
  void checkCollision();
  void splash();

 private:
  QRect map2;
  QImage level_2;
  QRect map3;
  QImage level_3;
  int x;
  int player_x;
  int player_y;
  int timerId;
  int level;
  bool shot_hit;
  Maze *maze;
  //enemies
  Player *player;
  Ghost *enemy;
  Hex *hex;
  Sphera *sphera;
  Penta *penta;
  //food
  Pizza *pizza[6];
  Ice *ice[3];
  Apple *apple[6];
  Milk *milk[6];
  HP *hp;

  Bullet *bullet[4];
  Bullet *sbullet[8];
  bool gameOver;
  bool gameWon;
  bool gameStarted;
  bool newBullets;
  bool paused;
  bool shield;
  bool bullet_shield;
  bool spawn_1;
  bool spawn_2;
  bool stage_2;
  bool stage_3;
  bool hp_spawn;
  int life;
  int score;
  int m;
};

#endif
