#include "Pacman.h"
#include "CollisionManager.h"
#include "Map.h"

//inicializar variables y aplicar textura en el constructor??
Pacman::Pacman(){
    
    current_pos.x = 150.f;
    current_pos.y = 150.f;
    dir_move.x = 0.f;
    dir_move.y = 0.f;
    playerSpeed = 500.f;
    direction_ = Right; //empieza mirando a la derecha
    paused = false;
    alive = true;
    score = 0;

    if(!textura.loadFromFile("/home/fv/Escritorio/Pac-Man_sprite.png")){
           std::cout<<"Textura no aplicada"<<std::endl;
        }

    misprite.setTexture(textura);
    misprite.setPosition(current_pos);
    misprite.setScale(sf::Vector2f(0.2,0.2));

}

void Pacman::updatePos(int presionado){
    
    dir_move.x=0.f;
    dir_move.y=0.f;
         
    if(presionado==1){
         dir_move.x=-1.f;
         dir_move.y=0.f;
    }
    
    if(presionado==2){
         dir_move.x=1.f;
         dir_move.y=0.f;
    }
    
    if(presionado==3){
         dir_move.x=0.f;
         dir_move.y=1.f;
    }
    
    
    if(presionado==4){
         dir_move.x=0.f;
         dir_move.y=-1.f;
    }
    
}

void Pacman::interpolate(float d_time){
    
        current_pos.x += dir_move.x * playerSpeed * d_time;
        current_pos.y += dir_move.y * playerSpeed * d_time;
        
        misprite.setPosition(current_pos);
}

sf::Sprite Pacman::getSprite(){
    return misprite;
}

float Pacman::getVelocity(){
    return playerSpeed;
}

void Pacman::setDirection(Pacman::Direction direction){
    if(direction!=direction_){
        direction_=direction;
    }
}

void Pacman::pause(){
    
}

void Pacman::restart(){
    
}

void Pacman::resume(){
    
}

void Pacman::kill(){
    
}

bool Pacman::isAlive(){
    if(alive){
        return true;
    }else{
        return false;
    }
}

int Pacman::getScore(){
    return score;
}

sf::Vector2f Pacman::getCurrentPosition(){
    return current_pos;
}

Pacman::~Pacman(){
    
}

const sf::Sprite &Pacman::getSprite() const{
    return misprite;
}




