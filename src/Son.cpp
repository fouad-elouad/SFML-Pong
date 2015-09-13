#include "Son.h"

Son::Son()
{
    m_soundBufferCollision.loadFromFile("rsc/soundCollision.wav");
    m_soundCollision.setBuffer(m_soundBufferCollision);

    m_soundBufferCollisionSol.loadFromFile("rsc/soundCollisionSol.wav");
    m_soundCollisionSol.setBuffer(m_soundBufferCollisionSol);
}

void Son::playSoundCollision()
{
    m_soundCollision.play();
}

void Son::playSoundCollisionSol()
{
    m_soundCollisionSol.play();
}

void Son::playSoundGameOver()
{
    m_soundGameOver.play();
}

Son::~Son()
{
    //dtor
}
