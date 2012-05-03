#ifndef SPHERA_H
#define SPHERA_H

#include <vector>
#include "enemy.h"
#include "bullet.h"
#include "maze.h"
#include <ctime>

class Sphera : public Enemy{
public:
    Sphera(int , int);
    ~Sphera();
    int coordX();
    int coordY();
    void move();
private:
    int cx;
    int cy;
    int pattern;
};

#endif // SPHERA_H
