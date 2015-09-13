#include "Jeux.h"
#include <sstream>
#include <cmath>

namespace patch
{
template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}
}

void Jeux::textClockVitesse(sf::Clock& clock,sf::Time& time, int& second, int& minute)
{
    time = clock.getElapsedTime();
    second = floor(time.asSeconds());
    if (second % 60 == 0 && second != 0)
    {
        //std::cout << "minute "<< minute << " second " <<second  << std::endl;
        minute = minute+1;
        clock.restart();
    }
}

bool Jeux::collisionBallBarre(Ball ball,Barre barre)
{
    if(ball.getCircle().getPosition().x >= barre.left() && ball.getCircle().getPosition().x<= barre.right() && ball.bottom()>=barre.top()-1)
        return true;
    return false;
}

bool Jeux::collisionBallSol(Ball ball, Barre barre)
{
    if(ball.bottom() >= barre.top()+3)
        return true;
    return false;
}

int Jeux::play()
{
    const int gameWidth = 800;
    const int gameHeight = 600;
    sf::RenderWindow window(sf::VideoMode(gameWidth,gameHeight), "CRZ Pong");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(1000);
    window.setMouseCursorVisible(false);

    sf::Image icon;
    if(!icon.loadFromFile("rsc/icon.png"))
        return EXIT_FAILURE;
    window.setIcon(45,40,icon.getPixelsPtr());

    Barre barre(sf::Vector2f(400,560));
    Ball ball(sf::Vector2f(300,300));
    bool isPlaying = true;
    bool gameOver = false;
    int score=0;

    sf::Texture image;
    image.loadFromFile("rsc/background.jpg");
    sf::Sprite background(image);
    background.setScale(sf::Vector2f(1.5,2));

    Son son;

    sf::Font font;
    if (!font.loadFromFile("rsc/sansation.ttf"))
        return EXIT_FAILURE;

    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(100);
    pauseMessage.setPosition(260, 220);
    pauseMessage.setColor(sf::Color::Black);
    pauseMessage.setString("PAUSE");

    sf::Text textGameOver;
    textGameOver.setFont(font);
    textGameOver.setCharacterSize(120);
    textGameOver.setPosition(50, 220);
    textGameOver.setColor(sf::Color::White);
    textGameOver.setString("GAME OVER");

    sf::Text text1;
    text1.setFont(font);
    text1.setCharacterSize(20);
    text1.setPosition(0, 0);
    text1.setColor(sf::Color::Black);
    text1.setString("capture : S \nPause : Espace");

    sf::Clock clock;
    sf::Clock clockDeltaTime;
    clock.restart();
    sf::Time time;

    sf::Text textScore;
    textScore.setPosition(660,0);
    textScore.setFont(font);
    textScore.setCharacterSize(30);
    textScore.setColor(sf::Color::White);

    int minute = 0;
    int second =0;

    while (window.isOpen())
    {
        std::string score_str = patch::to_string(score);
        textScore.setString("Score : "+score_str);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
            {
                if(isPlaying)
                    isPlaying = false;
                else isPlaying = true;
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::S))
            {
                sf::Image image;
                image = window.capture();
                std::string second_str = patch::to_string(second);
                std::string minute_str = patch::to_string(minute);
                image.saveToFile("save/capture"+minute_str+second_str+".png");

            }

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::P))
            {
                window.close();
                Jeux jeux;
                jeux.play();
            }
        }

        float deltaTime = clock.restart().asSeconds();

        window.clear(sf::Color::White);
        window.draw(background);

        if(gameOver)
        {
            window.draw(textGameOver);
        }
        else
        {
            if(isPlaying)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    barre.moveLeft(deltaTime);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    barre.moveRight(gameWidth,deltaTime);
                }

                textClockVitesse(clock, time, second, minute);
                ball.moveBall(gameWidth,false, son, deltaTime);

                if(collisionBallSol(ball,barre))
                {
                    son.playSoundGameOver();
                    gameOver = true;
                    isPlaying = false;
                }
                else if(collisionBallBarre(ball,barre))
                {
                    ball.moveBall(gameWidth,true,son, deltaTime);
                    score +=1;
                }

            }
            else
            {
                window.draw(pauseMessage);
            }

        }

        window.draw(barre.getRectangle());
        window.draw(ball.getCircle());
        window.draw(text1);
        window.draw(textScore);

        window.display();
    }
    return 0;
}

Jeux::Jeux()
{
}

Jeux::~Jeux()
{
}


