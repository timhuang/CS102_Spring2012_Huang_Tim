#ifndef HEX_H
#define HEX_H

#include "enemy.h"
#include "player.h"

class Hex : public Enemy{
public:
    Hex(int, int);
    ~Hex();
    void shoot();
};

#endif // HEX_H
