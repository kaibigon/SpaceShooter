//
//  PlayermovementComponent.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//

#include "MovementComponent.hpp"

MovementComponent::MovementComponent()
{
    mVelValue = 5;
    mVelY = 0;
    mVelX = 0;
}

void MovementComponent::HandleEvent(SDL_Event &e)
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_w: mVelY -= mVelValue; break;
            case SDLK_s: mVelY += mVelValue; break;
            case SDLK_a: mVelX -= mVelValue; break;
            case SDLK_d: mVelX += mVelValue; break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_w: mVelY += mVelValue; break;
            case SDLK_s: mVelY -= mVelValue; break;
            case SDLK_a: mVelX += mVelValue; break;
            case SDLK_d: mVelX -= mVelValue; break;
        }
    }
}

//void MovementComponent::Update(TransformComponent* transformComponent)
//{
//    transformComponent->SetPosX(transformComponent->GetPosX() + mVelX);
//    transformComponent->SetPosY(transformComponent->GetPosY() + mVelY);
//}
