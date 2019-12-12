/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/4/2019
 *     Description: The cpp file to outline all methods for the class Bullet which extends Entity and controls the
 *                  games bullets.
 **********************************************************************************************************************/

#include "Bullet.h"

/* Constructor */
Bullet::Bullet() {
    m_name = "bullet";
}

/**********************************************************************************************************************
 * Description: Updates the bullets position
 *      Inputs: N/A
 *     Outputs: void
 **********************************************************************************************************************/
void Bullet::update() {
    m_dx = float(cos(double(m_angle * M_DEG_TO_RAD)) * 6);
    m_dy = float(sin(double(m_angle * M_DEG_TO_RAD)) * 6);
    m_angle += float((rand() % 5 - 2) / 3.0);
    m_x += m_dx;
    m_y += m_dy;

    if(m_x > float(m_width) || m_x < 0 || m_y > float(m_height) || m_y < 0) {
        m_life = false;
    }
}
