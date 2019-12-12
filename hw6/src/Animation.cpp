/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/4/2019
 *     Description: The cpp file to outline all methods for the class Animation which handles animating series of
 *                  images.
 **********************************************************************************************************************/

#include "Animation.h"

/* Constructor */
Animation::Animation(const sf::Texture &t, float x, float y, float width, float height, int count, float speed) {
    m_frame = 0;
    m_speed = speed;
    for(int i = 0; i < count; i++) {
        m_frames.emplace_back(x + float(i) * width, y, width, height);
    }
    m_sprite.setTexture(t);
    m_sprite.setOrigin(width / 2, height / 2);
    m_sprite.setTextureRect(m_frames[0]);
}

/* Get Sprite */
const sf::Sprite & Animation::getSprite() const {
    return m_sprite;
}

/**********************************************************************************************************************
 * Description: Update m_sprite's position and rotation
 *      Inputs: float x - New x position
 *              float y - New y position
 *              float rot - New rotation
 *     Outputs: void
 **********************************************************************************************************************/
void Animation::updateSprite(float x, float y, float rot) {
    m_sprite.setPosition(x, y);
    m_sprite.setRotation(rot);
}

/**********************************************************************************************************************
 * Description: Updates the texture of the sprite to make it animate.
 *      Inputs: N/A
 *     Outputs: void
 **********************************************************************************************************************/
void Animation::update() {
    m_frame += m_speed;
    float n = m_frames.size();
    if(m_frame >= float(n)) {
        m_frame -= n;
    }
    if(n > 0) {
        m_sprite.setTextureRect(m_frames[int(m_frame)]);
    }
}

/**********************************************************************************************************************
 * Description: Determines if the animation has ended yet or not.
 *      Inputs: N/A
 *     Outputs: bool - whether or not the animation has ended
 **********************************************************************************************************************/
bool Animation::isEnd() const {
    return m_frame + m_speed >= m_frames.size();
}
