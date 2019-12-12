/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/4/2019
 *     Description: The cpp file to outline all methods for the class Asteroids which extends Entity and controls the
 *                  games asteroids.
 **********************************************************************************************************************/

#include "Asteroid.h"

int Asteroid::m_count = 0;

/* Constructor */
Asteroid::Asteroid() {
    m_dx = float((rand() % 6) - 3);
    m_dy = float((rand() % 6) - 3);
    m_name = "asteroid";
    m_count++;
}

/* Destructor */
Asteroid::~Asteroid() {
    m_count--;
}

/**********************************************************************************************************************
 * Description: Updates the asteroids position
 *      Inputs: N/A
 *     Outputs: void
 **********************************************************************************************************************/
void Asteroid::update() {
    m_x += m_dx;
    m_y += m_dy;

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

/* Get Count */
int Asteroid::getCount() {
    return m_count;
}
