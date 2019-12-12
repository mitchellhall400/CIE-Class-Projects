/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/4/2019
 *     Description: The cpp file to outline all methods for the class Entity which outlines the basic assets of all of
 *                  the game entities
 **********************************************************************************************************************/

#include "Entity.h"

/* Static Variables */
unsigned int Entity::m_width = 1200;
unsigned int Entity::m_height = 800;

/* Constructor */
Entity::Entity() {
    m_life = true;
}

/**********************************************************************************************************************
 * Description: Sets the settings for the entity class
 *      Inputs: Animation &animation - the animation to be set
 *              float x - x value to be set
 *              float y - y value to be set
 *              float angle - angle to be set
 *              float radius - radius to be set
 *     Outputs: void
 **********************************************************************************************************************/
void Entity::settings(Animation &animation, float x, float y, float angle, float radius) {
    m_animation = animation;
    m_x = x;
    m_y = y;
    m_angle = angle;
    m_radius = radius;
}

/**********************************************************************************************************************
 * Description: Draws the sprite being handled by the class's member animation under the Animation class
 *      Inputs: sf::RenderWindow &app - The RenderWindow to draw the sprite in
 *     Outputs: void
 **********************************************************************************************************************/
void Entity::draw(sf::RenderWindow &app) {
    m_animation.updateSprite(m_x, m_y, m_angle + 90);
    app.draw(m_animation.getSprite());
}

/**********************************************************************************************************************
 * Description: Calls to m_animations method update()
 *      Inputs: N/A
 *     Outputs: void
 **********************************************************************************************************************/
void Entity::updateAnimation() {
    m_animation.update();
}

/**********************************************************************************************************************
 * Description: Gets m_animations bool value m_end
 *      Inputs: N/A
 *     Outputs: void
 **********************************************************************************************************************/
bool Entity::isEnd() {
    return m_animation.isEnd();
}


/* Getters and Setters */
float Entity::getX() const {
    return m_x;
}

void Entity::setX(float x) {
    m_x = x;
}

float Entity::getY() const {
    return m_y;
}

void Entity::setY(float y) {
    m_y = y;
}

float Entity::getDx() const {
    return m_dx;
}

void Entity::setDx(float dx) {
    m_dx = dx;
}

float Entity::getDy() const {
    return m_dy;
}

void Entity::setDy(float dy) {
    m_dy = dy;
}

float Entity::getRadius() const {
    return m_radius;
}

void Entity::setRadius(float radius) {
    m_radius = radius;
}

float Entity::getAngle() const {
    return m_angle;
}

void Entity::setAngle(float angle) {
    m_angle = angle;
}

bool Entity::isLife() const {
    return m_life;
}

void Entity::setLife(bool life) {
    m_life = life;
}

const std::string & Entity::getName() const {
    return m_name;
}

void Entity::setName(const std::string &name) {
    m_name = name;
}

const Animation & Entity::getAnimation() const {
    return m_animation;
}

void Entity::setAnimation(const Animation &mAnimation) {
    m_animation = mAnimation;
}

unsigned int Entity::getWidth() {
    return m_width;
}

void Entity::setWidth(unsigned int width) {
    m_width = width;
}

unsigned int Entity::getHeight() {
    return m_height;
}

void Entity::setHeight(unsigned int height) {
    m_height = height;
}
