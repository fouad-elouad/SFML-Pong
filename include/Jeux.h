#ifndef JEUX_H
#define JEUX_H
#include <Ball.h>
#include <Barre.h>

class Jeux
{
public:
    Jeux();
    int play();
    bool collisionBallBarre(Ball ball,Barre barre);
    bool collisionBallSol(Ball ball,Barre barre);
    void textClockVitesse(sf::Clock& clock,sf::Time& time, int& second, int& minute);
    static void menuDisplay(sf::RenderWindow& window);
    virtual ~Jeux();

protected:
private:
};

#endif // JEUX_H
