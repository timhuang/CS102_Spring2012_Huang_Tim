#ifndef PENTA_H
#define PENTA_H

#include "enemy.h"

class Penta : public Enemy{
public:
    Penta(int , int);
    ~Penta();
    void patrol();
private:
    int pattern;
};

#endif // PENTA_H
