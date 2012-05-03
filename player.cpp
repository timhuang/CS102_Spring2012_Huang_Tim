#include "player.h"
using namespace std;
Player::Player()
{
  image.load(":/icons/images/Player.png");
  collide = FALSE;
  rect = image.rect();
  reset();

}
Player::~Player(){
}

int Player::getX()
{
    //players center x coordinate
    int x;
    x = rect.left()+22;
    return x;
}
int Player::getY(){
    //players center y coordinate
    int y;
    y = rect.top()+22;
    return y;
}

void Player::up(int top){
  if(rect.top () >=4 && !wall_top())
    rect.moveTop(top);
}
void Player::down(int bottom){
  if(rect.bottom () <=696 && !wall_bottom() )
    rect.moveBottom(bottom);
}
void Player::left(int left){
  if(rect.left() >=4 && !wall_left())
    rect.moveLeft(left);
}
void Player::right(int right){
  if(rect.right() <= 996  && !wall_right())
    rect.moveRight(right);
}
void Player::reset()
{
  rect.moveTo(300,300);
}
void Player::setXDir(int x)
{
  xdir = x;
}
void Player::setYDir(int y)
{
  ydir = y;
}
int Player::getXDir()
{
  return xdir;
}
int Player::getYDir()
{
  return ydir;
}
QRect Player::getRect()
{
  return rect;
}
QImage & Player::getImage()
{
  return image;
}
bool Player::wall_bottom()
{
    //player cannot move through wall
	bool flag=FALSE;
    for(int i=0; i<12; i++){
		if(rect.bottom() == (maze.getRect(i)).top() && rect.intersects(maze.getRect(i)))
			flag=TRUE;
	}
	if(flag) return TRUE;
	else return FALSE;
}
bool Player::wall_left()
{
	bool flag=FALSE;
    for(int i=0; i<12; i++){
		if(rect.left() == (maze.getRect(i)).right() && rect.intersects(maze.getRect(i)))
			flag=TRUE;
	}
	if(flag) return TRUE;
	else return FALSE;
}
bool Player::wall_right()
{
	bool flag=FALSE;
    for(int i=0; i<12; i++){
		if(rect.right() == (maze.getRect(i)).left() && rect.intersects(maze.getRect(i)))
			flag=TRUE;
	}
	if(flag) return TRUE;
	else return FALSE;
}
bool Player::wall_top()
{
	bool flag=FALSE;
    for(int i=0; i<12; i++){
		if(rect.top() == (maze.getRect(i)).bottom() && rect.intersects(maze.getRect(i)))
			flag=TRUE;
	}
	if(flag) return TRUE;
	else return FALSE;
}

		
		
