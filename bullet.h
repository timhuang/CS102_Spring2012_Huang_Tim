#ifndef BULLET_H
#define BULLET_H

#include <QRect>
#include <QImage>
#include <player.h>

class Bullet{
public:
    Bullet(int, int);
    ~Bullet();

public:
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
    void reset(int, int);
    void moveToward(Player, int);
    void up(int);
    void down(int);
    void left(int);
    void right(int);
    void topr(int);
    void topl(int);
    void botr(int);
    void botl(int);
    QRect getRect();
    QImage & getImage();

private:
    int dx;
    int dy;
    int speed;
    int xdir;
    int ydir;
    int coordx;
    int coordy;
    QImage image;
    QRect rect;
};

#endif // BULLET_H
