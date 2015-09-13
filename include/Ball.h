#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
#include <Son.h>

class Ball
{
public:
    Ball(sf::Vector2f position);
    sf::CircleShape getCircle() const;
    sf::Vector2f getDirection() const;
    float getVitesse() const;
    void setDirection(sf::Vector2f direction);
    void setVitesse(float vitesse);
    void moveBall(const int& gameWidth, bool collision, Son& son, float deltaTime);
    float left() const;
    float right() const;
    float top() const;
    float bottom() const;
    virtual ~Ball();

protected:
private:
    sf::CircleShape m_circle;
    sf::Vector2f m_direction;
    float m_vitesse;
    float m_rayon;
};

#endif // BALL_H
