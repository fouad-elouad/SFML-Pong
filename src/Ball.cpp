#include "Ball.h"

Ball::Ball(sf::Vector2f position)
{
    m_rayon = 10;
    m_circle = sf::CircleShape(m_rayon);
    m_circle.setFillColor(sf::Color::Yellow);
    m_circle.setPosition(position);
    m_circle.setOrigin(m_rayon,m_rayon);
    m_circle.setOutlineThickness(2);
    m_circle.setOutlineColor(sf::Color::White);
    m_vitesse = 600.f;
    m_direction.x = m_vitesse;
    m_direction.y = -m_vitesse;
}

sf::CircleShape Ball::getCircle() const
{
    return m_circle;
}

sf::Vector2f Ball::getDirection() const
{
    return m_direction;
}

float Ball::getVitesse() const
{
    return m_vitesse;
}
void Ball::setDirection(sf::Vector2f direction)
{
    m_direction = direction;
}

void Ball::setVitesse(float vitesse)
{
    m_vitesse=vitesse;
}

void Ball::moveBall(const int& gameWidth, bool collision, Son& son, float deltaTime)
{
    if(left()<=2)
    {
        son.playSoundCollisionSol();
        m_direction.x = -m_direction.x;
    }

    if(right()>=gameWidth-2)
    {
        son.playSoundCollisionSol();
        m_direction.x = -m_direction.x;
    }

    if(collision)
    {
        son.playSoundCollision();
        m_direction.y = -m_direction.y;
    }

    if(top()<=2)
    {
        son.playSoundCollisionSol();
        m_direction.y = -m_direction.y;
    }

    m_circle.move(m_direction * deltaTime);
}

float Ball::left() const
{
    return m_circle.getPosition().x-m_circle.getRadius()-3;
}
float Ball::right() const
{
    return m_circle.getPosition().x + m_circle.getRadius()+3;
}
float Ball::top() const
{
    return m_circle.getPosition().y-m_circle.getRadius()-3;
}
float Ball::bottom() const
{
    return m_circle.getPosition().y+m_circle.getRadius()+3;
}

Ball::~Ball()
{
}
