#ifndef BARRE_H
#define BARRE_H
#include <SFML/Graphics.hpp>

class Barre
{
public:
    Barre(sf::Vector2f position);
    virtual ~Barre();
    sf::RectangleShape  getRectangle() const;
    void  setVitesse(const float& s);
    float getVitesse() const;
    float left() const;
    float right() const;
    float top() const;
    float bottom() const;
    void moveLeft(float deltaTime);
    void moveRight(const int& gameWith,float deltaTime);

protected:
private:
    sf::RectangleShape m_rectangle;
    float m_vitesse;
};

#endif // BARRE_H
