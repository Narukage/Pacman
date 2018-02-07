#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef PACMAN_H
#define PACMAN_H
#endif /* PACMAN_H */

class Pacman{
    
private:
    float playerSpeed;
    sf::Vector2f current_pos;
    sf::Vector2f dir_move;
    sf::Sprite misprite;
    
    enum Direction{
        Left = -1,
        Right = 1,
        Up = 2,
        Down = -2,
        None = 0
    };
    
    Direction direction_;
    bool paused;
    bool alive;
    sf::Texture textura;  
    
    
public:

    void pause(); //stop pacman animation
    void resume(); //resume pacman animation
    void restart(); //reinicia su posicion en el mapa
    void kill();
    bool isAlive();
    void updatePos(int presionado); //pacman movement
    void interpolate(float d_time);    //pacman render interpolation
    float getVelocity();
    void setDirection(Pacman::Direction direction); //cambiar direccion en la que mira
    sf::Sprite getSprite();
    Pacman();
    
};
