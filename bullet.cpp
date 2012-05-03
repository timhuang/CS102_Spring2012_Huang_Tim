#include "bullet.h"
#include <iostream>
using namespace std;

Bullet::Bullet(int x, int y){
    image.load(":/icons/image/Bullet.png");
    rect = image.rect();
    rect.translate(x,y);
    coordx = rect.left() +5;
    coordy = rect.top() + 5;
}
Bullet::~Bullet(){
}

int Bullet::getXDir(){
    return xdir;
}
int Bullet::getYDir(){
    return ydir;
}
QImage & Bullet::getImage(){
    return image;
}
QRect Bullet::getRect(){
    return rect;
}

void Bullet::setXDir(int x){
    xdir = x;
}
void Bullet::setYDir(int y){
    ydir = y;
}
void Bullet::up(int n)
{
    rect.translate(0,-n);
}
void Bullet::down(int n){
    rect.translate(0,n);
}
void Bullet::left(int n){
    rect.translate(-n,0);
}
void Bullet::right(int n){
    rect.translate(n,0);
}
void Bullet::topl(int n){
    rect.translate(-n,-n);
}
void Bullet::topr(int n){
    rect.translate(n,-n);
}
void Bullet::botl(int n){
    rect.translate(-n,n);
}
void Bullet::botr(int n){
    rect.translate(n,n);
}
void Bullet::moveToward(Player p, int n){
    //bullet move toward the center of player Rect
    dx = p.getX() - coordx;
    dy = p.getY() - coordy;
    if(dx == 0){
        if(dy <=0) rect.translate(0, -n);
        if(dy >=0) rect.translate(0, n);
    }
    else {
        if(dx <=0) rect.translate(-n, (dy/dx)*n);
        if(dx >=0) rect.translate(n, (dy/dx)*n);
    }
}
void Bullet::reset(int x, int y){
    rect.moveTo(x,y);
}
