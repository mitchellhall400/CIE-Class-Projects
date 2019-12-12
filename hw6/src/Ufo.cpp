/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/4/2019
 *     Description: The cpp file to outline all methods for the class Ufo which extends Entity and controls the
 *                  games Ufo's.
 **********************************************************************************************************************/

#include "Ufo.h"

/* Constructor */
Ufo::Ufo() {
    m_name = "ufo";
}

void Ufo::update() {
    m_x += 3;
    if(m_x > m_width) {
        m_life = false;
    }
}