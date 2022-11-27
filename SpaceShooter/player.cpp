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

Player::~Player()
{
    mTexture.free();
}

void Player::handleEvent(SDL_Event &e)
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_w: mVelY -= VEL; break;
            case SDLK_s: mVelY += VEL; break;
            case SDLK_a: mVelX -= VEL; break;
            case SDLK_d: mVelX += VEL; break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_w: mVelY += VEL; break;
            case SDLK_s: mVelY -= VEL; break;
            case SDLK_a: mVelX += VEL; break;
            case SDLK_d: mVelX -= VEL; break;
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
    printf("player;s width: %d, height: %d\n", mTexture.getWidth(), mTexture.getHeight());
    mTexture.render(renderer, mPosX, mPosY, mTexture.getWidth(), mTexture.getHeight());
}

void Player::setTexture(LTexture texture)
{
    mTexture = texture;
}

LTexture* Player::getTexture()
{
    return &mTexture;
}