/**********************************************************************************************************************
 *     Description: The header file for the point class which stores an x and y coordinate.
 **********************************************************************************************************************/

#ifndef HW5_POINT_H
#define HW5_POINT_H

class point {
private:
    float m_x{}, m_y{};

public:
    explicit point(float x = 0, float y = 0);
    void setX(float x);
    void setY(float y);
    float getX();
    float getY();
};

#endif //HW5_POINT_H
