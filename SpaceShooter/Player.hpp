//
//  player.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/27.
//

#ifndef Player_hpp
#define Player_hpp

#include <SDL2/SDL.h>
#include <stdio.h>

#include "consts.h"
#include "TextureComponent.hpp"

#endif /* player_hpp */

class Player
{
public:
    static const int WIDTH = 20;
    static const int HEIGHT = 20;
    
    static const int VEL = 5;
    
    Player();
    ~Player();
    
    void handleEvent(SDL_Event &e);
    void move();
    void render(SDL_Renderer *renderer);
    TextureComponent* getTexture();
    void setTexture(TextureComponent texture);
    
private:
    TextureComponent mTexture;
    int mPosX;
    int mPosY;
    int mVelX;
    int mVelY;
};
