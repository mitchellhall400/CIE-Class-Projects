/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/4/2019
 *     Description: The header file for the class Ufo which extends Entity and controls the games Ufo's.
 **********************************************************************************************************************/

#ifndef HW6_UFO_H
#define HW6_UFO_H

#include "Entity.h"

class Ufo: public Entity {
public:
    Ufo();
    void update() override;

};

#endif //HW6_UFO_H
