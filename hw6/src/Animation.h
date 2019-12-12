/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 11/4/2019
 *     Description: The header file for the class Animation which handles animating gifs.
 **********************************************************************************************************************/

#ifndef ASTEROIDS_ANIMATION_H
#define ASTEROIDS_ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation {
private:
    float m_frame{}, m_speed{};
    sf::Sprite m_sprite;
    std::vector<sf::IntRect> m_frames;

public:
    Animation() = default;
    Animation(const sf::Texture &t, float x, float y, float width, float height, int count, float speed);
    const sf::Sprite & getSprite() const;
    void updateSprite(float x, float y, float rot);
    void update();
    bool isEnd() const;

};

#endif //ASTEROIDS_ANIMATION_H
