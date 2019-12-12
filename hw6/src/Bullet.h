/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/4/2019
 *     Description: The header file for the class Bullet which extends Entity and controls the games bullets.
 **********************************************************************************************************************/

#ifndef ASTEROIDS_BULLET_H
#define ASTEROIDS_BULLET_H

#include "Entity.h"
#include <cmath>

class Bullet: public Entity {
public:
    Bullet();
    void update() override;

};

#endif //ASTEROIDS_BULLET_H
