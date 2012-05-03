#ifndef LEVEL_2_H
#define LEVEL_2_H

#include <QImage>
#include <QRect>

class Level_2{
private:
    QRect rect;
    QImage image;
public:
    Level_2();
    ~Level_2();
    QRect getRect();
    QImage & getImage();
};

#endif // LEVEL_2_H
