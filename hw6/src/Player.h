/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/4/2019
 *     Description: The header file for the class Player which extends Entity and controls the player (rocket)
 **********************************************************************************************************************/

#ifndef ASTEROIDS_PLAYER_H
#define ASTEROIDS_PLAYER_H

#include "Entity.h"
#include <cmath>

class Player: public Entity {
private:
    const float M_MAX_SPEED = 15;
    bool m_thrust;
    float m_dAngle;

public:
    Player();
    void setThrust(bool thrust);
    bool getThrust() const;
    void setDAngle(float dAngle);
    float getDAngle() const;
    void update() override;

};

#endif //ASTEROIDS_PLAYER_H
