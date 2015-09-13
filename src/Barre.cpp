#include "Barre.h"


Barre::Barre(sf::Vector2f position)
{
    m_rectangle = sf::RectangleShape();
    m_rectangle.setSize(sf::Vector2f(80,15));
    m_rectangle.setFillColor(sf::Color::Red);
    m_rectangle.setPosition(position);
    m_rectangle.setOutlineThickness(2);
    m_rectangle.setOutlineColor(sf::Color::White);
    m_vitesse = 500.f;

}

float Barre::left() const
{

    return m_rectangle.getPosition().x-3;
}
float Barre::right() const
{

    return m_rectangle.getPosition().x + m_rectangle.getSize().x+3;
}
float Barre::top() const
{
    return m_rectangle.getPosition().y-3;
}
float Barre::bottom() const
{
    return m_rectangle.getPosition().y + m_rectangle.getSize().y+3;
}

void Barre::moveLeft(float deltaTime)
{

    for(int i=0; i<m_vitesse; i++)
    {
        if(left() <= 0)
            break;
        else m_rectangle.move(- deltaTime ,0);
    }
}

void Barre::moveRight(const int& gameWith, float deltaTime)
{
    for(int i=0; i<m_vitesse; i++)
    {
        if(right() >= gameWith)
            break;
        else m_rectangle.move(deltaTime,0);
    }
}

sf::RectangleShape Barre::getRectangle() const
{
    return m_rectangle;
}
void  Barre::setVitesse(const float& s)
{
    if(m_vitesse<15)
        m_vitesse = s;
}
float Barre::getVitesse() const
{
    return m_vitesse;
}
Barre::~Barre()
{
    //dtor
}
