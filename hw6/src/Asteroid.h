/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/4/2019
 *     Description: The header file for the class Asteroid which extends Entity and controls the games asteroids.
 **********************************************************************************************************************/

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include "Entity.h"

class Asteroid: public Entity {
private:
    static int m_count;

public:
    Asteroid();
    ~Asteroid() override;
    void update() override;
    static int getCount();
};

#endif //ASTEROIDS_ASTEROID_H
