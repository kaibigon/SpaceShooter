//
//  player.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/27.
//

#include "player.hpp"

Player::Player()
{
    mPosX = 100;
    mPosY = 100;

    mVelX = 0;
    mVelY = 0;
}

void Player::handleEvent(SDL_Event &e)
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:    mVelY -= VEL; break;
            case SDLK_DOWN:  mVelY += VEL; break;
            case SDLK_LEFT:  mVelX -= VEL; break;
            case SDLK_RIGHT: mVelX += VEL; break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:    mVelY += VEL; break;
            case SDLK_DOWN:  mVelY -= VEL; break;
            case SDLK_LEFT:  mVelX += VEL; break;
            case SDLK_RIGHT: mVelX -= VEL; break;
        }
    }
}

void Player::move()
{
    mPosX += mVelX;
    
    if((mPosX < 0) || (mPosX + WIDTH) > SCREEN_WIDTH)
    {
        mPosX -= mVelX;
    }
    
    mPosY += mVelY;
    
    if((mPosY < 0) || (mPosY + HEIGHT) > SCREEN_HEIGHT)
    {
        mPosY -= mVelY;
    }
}

void Player::render(SDL_Renderer *renderer)
{
    playerTexture.render(renderer, mPosX, mPosY, playerTexture.getWidth(), playerTexture.getHeight());
}

void Player::setTexture(LTexture texture)
{
    playerTexture = texture;
}
