/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/4/2019
 *     Description: The header file for the class Entity which outlines the basic assets of all of the game entities
 **********************************************************************************************************************/

#ifndef ASTEROIDS_ENTITY_H
#define ASTEROIDS_ENTITY_H

#include <SFML/Graphics.hpp>
#include "Animation.h"

class Entity {
protected:
    const float M_DEG_TO_RAD = 0.017453f;
    static unsigned int m_width;
    static unsigned int m_height;
    float m_x{}, m_y{}, m_dx{}, m_dy{}, m_radius{}, m_angle{};
    bool m_life;
    std::string m_name;
    Animation m_animation;

public:
    Entity();
    virtual void update(){}     //Virtual method to be overloaded in derived classes
    void settings(Animation &animation, float x, float y, float angle = 0, float radius = 1);
    void draw(sf::RenderWindow &app);
    virtual ~Entity() = default;

    /* Getters and Setters */
    void updateAnimation();
    bool isEnd();
    float getX() const;
    void setX(float x);
    float getY() const;
    void setY(float y);
    float getDx() const;
    void setDx(float dx);
    float getDy() const;
    void setDy(float dy);
    float getRadius() const;
    void setRadius(float radius);
    float getAngle() const;
    void setAngle(float angle);
    bool isLife() const;
    void setLife(bool life);
    const std::string & getName() const;
    void setName(const std::string &name);
    const Animation & getAnimation() const;
    void setAnimation(const Animation &animation);
    static unsigned int getWidth();
    static void setWidth(unsigned int width);
    static unsigned int getHeight();
    static void setHeight(unsigned int height);

};

#endif //ASTEROIDS_ENTITY_H
