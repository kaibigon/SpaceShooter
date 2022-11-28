//
//  gameEntity.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//

#include "GameEntity.hpp"

GameEntity::GameEntity(){
    mTexture = nullptr;
}

GameEntity::GameEntity(SDL_Renderer *renderer)
{
    mPosX = 0;
    mPosY = 0;
    mRenderer = renderer;
}

GameEntity::~GameEntity()
{
    if (mTexture != nullptr) {
        delete mTexture;
    }
}

void update()
{
    
}

void GameEntity::Render()
{
    if ( mTexture != nullptr)
    {
        mTexture->Render(mRenderer, mPosX, mPosY, mTexture->GetWidth(), mTexture->GetHeight());
    }
}

void GameEntity::AddTextureComponent()
{
    mTexture = new LTexture();
}

void GameEntity::AddTextureComponent(std::string filepath)
{
    mTexture = new LTexture();
    mTexture->LoadFromFile(mRenderer, filepath);
}

LTexture& GameEntity::GetTextureComponent()
{
    return *mTexture;
}

SDL_Renderer* GameEntity::GetRenderer()
{
    return mRenderer;
}

void GameEntity::SetPosX(int posX)
{
    mPosX = posX;
}

void GameEntity::SetPosY(int posY)
{
    mPosY = posY;
}

int GameEntity::GetPosX()
{
    return mPosX;
}

int GameEntity::GetPosY()
{
    return mPosY;
}
