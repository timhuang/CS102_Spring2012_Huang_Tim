#include "game.h"
#include <QPainter>
#include <QApplication>
#include <QLabel>
#include <cstdlib>
#include <iostream>
using namespace std;

Game::Game(QWidget *parent):QWidget(parent)
{
  gameOver = FALSE;
  gameStarted = FALSE;
  gameWon = FALSE;
  paused = FALSE;
  penta_s = FALSE;
  bullet_shield = FALSE;
  shield = FALSE;
  sphera_shield = FALSE;

  player = new Player();
  enemy = new Ghost(100,600);
  maze = new Maze();
  heal = new Heal(400,400);
  penta = new Penta(800,650);

  life = 100;
  m = 0;
  score = 0;
  level = 1;

  stage_2 = FALSE;
  stage_3 = FALSE;
  spawn_1 = FALSE;
  spawn_2 = FALSE;

  level_2.load(":/icons/images/Level2.png");
  map2 = level_2.rect();
  map2.translate(0,0);
  level_3.load(":/icons/images/Level3.png");
  map3 = level_3.rect();
  map3.translate(0,0);

  pizza[0] = new Pizza(25,100);
  pizza[1] = new Pizza(130,540);
  pizza[2] = new Pizza(250,5);
  pizza[3] = new Pizza(500,420);
  pizza[4] = new Pizza(500,170);
  pizza[5] = new Pizza(178,123);
  ice[0] = new Ice(610,70);
  ice[1] = new Ice(225,502);
  ice[2] = new Ice(950, 630);
}

Game::~Game(){
  delete player;
  for(int i=0; i<6; i++){
	  delete pizza[i];
  }
  for(int i=0; i<3; i++){
      delete ice[i];
  }
  if(level>=2){
  for(int i=0; i<4; i++){
      delete bullet[i];
  }
  }
  if(level==3){
  for(int i=0; i<8; i++){
      delete sbullet[i];
  }
  }
  if(level>=2)
  {
      for(int i=0; i<6; i++){
        delete apple[i];
      }
  }
  if(level==3){
      for(int i=0; i<6; i++){
          delete milk[i];
      }
  }
  delete enemy;
  delete hex;
  delete maze;
  delete penta;
  delete heal;
}

void Game::paintEvent(QPaintEvent *event)
{
    //paint to screen
  QPainter painter(this);

  if(gameOver){
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Game Over");

    painter.setFont(font);
    int h=height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, "Game Over");
  }
  else if(gameWon){
    QFont font("Courier",17,QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("VICTORY!");
    painter.setFont(font);
    QString scored;
    scored.append(QString("%1").arg(score));
    QString str= "VICTORY! \nYour Score: " + scored ;
    int h=height();
    int w = width();
    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, str);

  }
  else{
      if(level == 2)
          painter.drawImage(map2, level_2);
      if(level == 3)
          painter.drawImage(map3, level_3);
	painter.drawImage(player->getRect(), player->getImage());
    painter.drawImage(enemy->getRect(), enemy->getImage());
    painter.drawImage(hex->getRect(),hex->getImage());
    if(!heal->isEaten()){
        painter.drawImage(heal->getRect(), heal->getImage());
    }
    painter.drawImage(penta->getRect(), penta->getImage());
    if(level==3)
        painter.drawImage(sphera->getRect(), sphera->getImage());
	for(int i=0; i<4; i++){
		painter.drawImage(maze->getRect(i), maze->getImage(i));
	}
	for(int i=4; i<8; i++){
		painter.drawImage(maze->getRect(i), maze->getImage(i-4));
	}
    for(int i=8; i<12; i++){
        painter.drawImage(maze->getRect(i), maze->getImage(i-8));
    }

	for(int i=0; i<6; i++){
        if(!pizza[i]->isEaten())
			painter.drawImage(pizza[i]->getRect(), pizza[i]->getImage());
	}
    if(level >= 2){
        for(int i=0; i<6; i++){
            if(!apple[i]->isEaten())
                painter.drawImage(apple[i]->getRect(), apple[i]->getImage());
        }
    }
    if(level == 3){
        for(int i=0; i<6; i++){
            if(!milk[i]->isEaten())
                painter.drawImage(milk[i]->getRect(), milk[i]->getImage());
        }
    }

    for(int i=0; i<3; i++){
        if(!ice[i]->isEaten())
            painter.drawImage(ice[i]->getRect(), ice[i]->getImage());
    }
    if(level>=2){
    for(int i=0; i<4; i++){
        painter.drawImage(bullet[i]->getRect(), bullet[i]->getImage());
    }
}
    if(level==3){
        for(int i=0; i<8; i++){
            painter.drawImage(sbullet[i]->getRect(), sbullet[i]->getImage());
        }
}
    QFont font("Courier", 10, QFont::DemiBold);//fonts being set.
    QFontMetrics fm(font);

    int textWidth = fm.width("Points");
    painter.setFont(font);

    int h = height();

    int w = width();

    QString lives;
    QString scored;
    QString currentLevel;
    lives.append(QString("%1").arg(life));
    scored.append(QString("%1").arg(score));
    currentLevel.append(QString("%1").arg(level));
    QString str="Level: " + currentLevel+ "\t\tHP: " + lives + "\tScore: " + scored ;
    painter.translate(QPoint(w/17, h/32));//location of where to print the string.
    painter.drawText(-textWidth/2, 0, str);
  }
}

void Game::timerEvent(QTimerEvent *event){
  checkCollision();
  if((player->getRect()).intersects(penta->getRect()) && !penta_s){
      life -= 23;
      penta_s = TRUE;
  }
  if(!(player->getRect()).intersects(penta->getRect())){
      penta_s = FALSE;
  }
  penta->patrol();
  if(level==3){
    sphera->move();
  }
  enemy->chase(*player);
  if(level>=2)
  {
      int num;
      for(int i=0; i<4; i++){
    if(player->getRect().intersects(bullet[i]->getRect()) && !bullet_shield){
        num = i;
        life-=12;
        bullet_shield=TRUE;
        }
   if(!player->getRect().intersects(bullet[num]->getRect()))
       bullet_shield=FALSE;
      }

  }

  if(level==3){
      //Sphera's bullets mechannic
      int d;
      sbullet[0]->up(8);
      sbullet[1]->down(4);
      sbullet[2]->left(4);
      sbullet[3]->right(8);
      sbullet[4]->topl(4);
      sbullet[5]->topr(8);
      sbullet[6]->botl(4);
      sbullet[7]->botr(8);
      if(bullet[0]->getRect().bottom()<=0 )
            bullet[0]->reset(sphera->coordX(),sphera->coordY());
      if(bullet[1]->getRect().top()>=700)
          bullet[1]->reset(sphera->coordX(),sphera->coordY());
      if(bullet[3]->getRect().left() >=1000)
          bullet[3]->reset(sphera->coordX(),sphera->coordY());
      if(bullet[2]->getRect().right() <=0)
          bullet[2]->reset(sphera->coordX(),sphera->coordY());
      if(bullet[4]->getRect().right() <=0 || bullet[4]->getRect().bottom()<=0)
          bullet[4]->reset(sphera->coordX(),sphera->coordY());
      if(bullet[5]->getRect().left() >=1000 || bullet[5]->getRect().bottom()<=0)
          bullet[5]->reset(sphera->coordX(),sphera->coordY());
      if(bullet[6]->getRect().right() <=0 || bullet[6]->getRect().top()>=700)
          bullet[6]->reset(sphera->coordX(),sphera->coordY());
      if(bullet[7]->getRect().left() >=1000 || bullet[7]->getRect().top()>=700)
          bullet[7]->reset(sphera->coordX(),sphera->coordY());
      for(int i=0; i<8; i++){
      if(player->getRect().intersects(sbullet[i]->getRect()) && !sphera_shield){
          d = i;
          life-=9;
          sphera_shield=TRUE;
          }
     if(!player->getRect().intersects(sbullet[d]->getRect()))
         sphera_shield=FALSE;
        }
  }
  if(level>=2){
    bullet[0]->topl(3);
    bullet[1]->topr(3);
    bullet[2]->botl(3);
    bullet[3]->botr(3);

    if(bullet[0]->getRect().bottom()<=0 && bullet[1]->getRect().bottom()<=0 && bullet[2]->getRect().top()>=700 && bullet[3]->getRect().top()>=700)
    {
        for(int i=0; i<4; i++)
        {
            bullet[i]->reset(580,332);
        }
    }
  }
  repaint();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    //Key event
  switch(event->key()){
  case Qt::Key_W:
    {
      int y = player->getRect().y();
      for(int i=1; i<=5; i++)
	player->up(y--);
    }
      break;
  case Qt::Key_S:
    {
      int y = (player->getRect().y()) + (player->getRect().width());
      for(int i =1; i<=5; i++)
	player->down(y++);
     }
      break;
  case Qt::Key_A:
    {
      int x = player -> getRect().x();
      for (int i =1; i<=5; i++)
	player ->left(x--);
     }
      break;
  case Qt::Key_D:
    {
      int x = (player -> getRect().x() + (player->getRect().width()));
      for (int i=1; i<=5; i++)
	player -> right(x++);
     }
      break;
  case Qt::Key_P:
  {
      pauseGame();
  }
      break;
  case Qt::Key_Space:
    {
      startGame();
    }
    break;
  case Qt::Key_Escape:
    {
      qApp->exit();
    }
    break;
  default:
    QWidget::keyPressEvent(event);
  }
}
void Game::startGame(){
    //Start Game (space key)

  if(!gameStarted){
    player->reset();
	for(int i=0; i<6; i++){
        pizza[i] ->setEaten(FALSE);
	}
    for(int i=0; i<3; i++){
        ice[i] ->setEaten(FALSE);
    }
    if(level==2)
    {
        for(int i=0; i<6; i++){
            apple[i] ->setEaten(FALSE);
        }
    }
    gameOver=FALSE;
    gameStarted = TRUE;
    timerId= startTimer(30);
  }
}
void Game::pauseGame()
{
    if(paused){
        timerId = startTimer(30);
        paused = FALSE;
    }else {
        paused = TRUE;
        killTimer(timerId);
    }
}

void Game::stopGame(){
    gameStarted = FALSE;
    killTimer(timerId);
    gameOver = TRUE;
}
void Game::victory()
{
  killTimer(timerId);
  gameWon = TRUE;
  gameStarted = FALSE;
}
void Game::checkCollision()
{
    //set food condition according to level
    if(level==3 && !stage_3){
        for(int i=0; i<6; i++){
            milk[i] ->setEaten(FALSE);
        }
        stage_3 = TRUE;
    }
    //proceed to level 2 after getting 6 pizza
  for(int i=0, j=0; i<6; i++){
    if(pizza[i]->isEaten()){
		j++;
    }
    if(j==6) {
        level = 2;
    }
  }
  if(level == 2 && !stage_2){
      stage_2 = TRUE;
      apple[0] = new Apple(900, 50);
      apple[1] = new Apple(380, 400);
      apple[2] = new Apple(850, 430);
      apple[3] = new Apple(230, 20);
      apple[4] = new Apple(505,420);
      apple[5] = new Apple(140, 550);
  }

  if(m==6) victory();

  //proceed to level 3 after getting 6 apples
  if(level==2){
    for(int i=0, j=0; i<6; i++){
        if(apple[i]->isEaten()){
            j++;
        }
        if(j==6) {
            level = 3;

        }
    }
  }
  if(level == 3 && !stage_3){
      milk[0] = new Milk(900, 200);
      milk[1] = new Milk(500, 420);
      milk[2] = new Milk(200, 310);
      milk[3] = new Milk(30, 70);
      milk[4] = new Milk(600, 170);
      milk[5] = new Milk(130, 540);
  }


  //check if food is eaten
  if((player->getRect()).intersects(heal->getRect()) && !heal->isEaten()){
    life*=1.75;
    heal->setEaten(TRUE);
    }
  for(int i=0; i<6; i++){
      if((player->getRect()).intersects(pizza[i]->getRect()) && !pizza[i]->isEaten()){
        score+=300;
        life+=2;
        pizza[i]->setEaten(TRUE);
    }
  }
  if(level==2){
  for(int i=0; i<6; i++){
      if((player->getRect()).intersects(apple[i]->getRect()) && !apple[i]->isEaten()){
        score+=500;
        life+=5;
        apple[i]->setEaten(TRUE);
    }
  }
  }
 if(level==3){
  for(int i=0; i<6; i++){
      if((player->getRect()).intersects(milk[i]->getRect()) && !milk[i]->isEaten()){
        score+=800;
        life+=10;
        milk[i]->setEaten(TRUE);
        m++;
    }
  }
 }

//check for player eating food
  for(int i=0; i<3; i++){
      if((player->getRect()).intersects(ice[i]->getRect()) && !ice[i]->isEaten()){
        score+=(10*life);
        ice[i]->setEaten(TRUE);
    }
  }
  if((player->getRect()).intersects(enemy->getRect()) && !shield){
      life -= 33;
      shield = TRUE;
  }
  if(!(player->getRect()).intersects(enemy->getRect())){
      shield = FALSE;
  }

  if(life <= 0) gameOver = TRUE;
  //spawn new creature
  if(level == 3 && !spawn_2){
      spawn_2 = TRUE;
      sphera = new Sphera(300,300);
          for(int i=0; i<8; i++)
          {
              sbullet[i]= new Bullet(sphera->coordX(),sphera->coordY());
          }
          spawn_2=TRUE;
  }
  if(level==2 && !spawn_1){
      hex = new Hex(565, 320);
  }
  //bullets of Hex
  if(level==2 && !spawn_1){
      for(int i=0; i<4; i++)
      {
          bullet[i]= new Bullet(580,332);
      }
      spawn_1=TRUE;
  }
}


