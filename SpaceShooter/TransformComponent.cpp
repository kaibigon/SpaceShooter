//
//  TransformComponent.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//

#include "TransformComponent.hpp"

TransformComponent::TransformComponent()
{
    mPosX = 0;
    mPosY = 0;
}

TransformComponent::~TransformComponent()
{
    
}

void TransformComponent::SetPosX(int posX)
{
    mPosX = posX;
}

void TransformComponent::SetPosY(int posY)
{
    mPosY = posY;
}

int TransformComponent::GetPosX()
{
    return mPosX;
}

int TransformComponent::GetPosY()
{
    return mPosY;
}
