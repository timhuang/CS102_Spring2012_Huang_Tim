#ifndef GHOST_H
#define GHOST_H

#include "enemy.h"
#include "player.h"

class Ghost : public Enemy{
public:
    Ghost(int, int);
    ~Ghost();
    void chase(Player);
};

#endif // GHOST_H
