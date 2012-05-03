#ifndef FOOD_H
#define FOOD_H

#include <QImage>
#include <QRect>

class Food
{
  protected:
    int x;
    int y;
    QImage image;
    QRect rect;
    bool eaten;

  public:
    Food();//Constructor
    Food(int x, int y);
    ~Food();//Destructor

    QRect getRect();
    void setRect(QRect);
    QImage & getImage();
    bool isEaten();
    void setEaten(bool);

};

#endif // FOOD_H

