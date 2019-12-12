/**********************************************************************************************************************
 *     Description: The cpp file to outline all methods for the class point which stores an x and y coordinate.
 **********************************************************************************************************************/

#include "point.h"

point::point(float x, float y) {        //Constructor
    this -> m_x = x;
    this -> m_y = y;
}

void point::setX(float x) {       //Setter
    this -> m_x = x;
}

void point::setY(float y) {       //Setter
    this -> m_y = y;
}

float point::getX() {     //Getter
    return m_x;
}

float point::getY() {     //Getter
    return m_y;
}