/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/4/2019
 *     Description: The cpp file to outline all methods for the class Player which extends Entity and controls the
 *                  player (rocket)
 **********************************************************************************************************************/

#include "Player.h"

/* Constructor */
Player::Player() {
    m_name = "player";
    m_thrust = false;
    m_dAngle = 0;
}

/* Set m_thrust */
void Player::setThrust(bool thrust) {
    m_thrust = thrust;
}

/* Get m_thrust */
bool Player::getThrust() const {
    return m_thrust;
}

/* Set m_dAngle */
void Player::setDAngle(float dAngle) {
    m_dAngle = dAngle;
}

/* Get m_dAngle */
float Player::getDAngle() const {
    return m_dAngle;
}

/**********************************************************************************************************************
 * Description: Updates the players position
 *      Inputs: N/A
 *     Outputs: void
 **********************************************************************************************************************/
void Player::update() {
    float speed;
    if(m_thrust) {
        m_dx += float(cos(double(m_angle * M_DEG_TO_RAD)) * 0.2);
        m_dy += float(sin(double(m_angle * M_DEG_TO_RAD)) * 0.2);
    }
    else {
        m_dx *= 0.99;
        m_dy *= 0.99;
    }

    speed = float(sqrt(double(m_dx * m_dx + m_dy * m_dy)));

    if(speed > M_MAX_SPEED) {
        m_dx *= M_MAX_SPEED / speed;
        m_dy *= M_MAX_SPEED / speed;
    }

    m_x += m_dx;
    m_y += m_dy;
    m_angle += m_dAngle;

    m_dAngle *= 0.90;

    if(m_x > float(m_width)) {
        m_x = 0;
    }
    if(m_x < 0) {
        m_x = float(m_width);
    }
    if(m_y > float(m_height)) {
        m_y = 0;
    }
    if(m_y < 0) {
        m_y = float(m_height);
    }
}