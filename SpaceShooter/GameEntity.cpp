//
//  gameEntity.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//

#include "GameEntity.hpp"

void GameEntity::setPosX(int posX)
{
    mPosX = posX;
}

void GameEntity::setPosY(int posY)
{
    mPosY = posY;
}

int GameEntity::getPosX()
{
    return mPosX;
}

int GameEntity::getPosY()
{
    return mPosY;
}
