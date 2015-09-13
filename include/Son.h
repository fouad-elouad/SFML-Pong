#ifndef SON_H
#define SON_H
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class Son
{
public:
    Son();
    void playSoundCollision();
    void playSoundCollisionSol();
    void playSoundGameOver();
    virtual ~Son();
protected:
private:
    sf::Sound m_soundCollision;
    sf::Sound m_soundCollisionSol;
    sf::Sound m_soundGameOver;
    sf::Sound m_soundCapture;
    sf::SoundBuffer m_soundBufferCollision;
    sf::SoundBuffer m_soundBufferCollisionSol;
    sf::SoundBuffer m_soundBufferGameOver;
    sf::SoundBuffer m_soundBufferCapture;
};

#endif // SON_H
