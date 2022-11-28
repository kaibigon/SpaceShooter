//
//  gameEntity.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//

#include "GameEntity.hpp"

GameEntity::GameEntity(){
    mTexture = nullptr;
    mTransform = nullptr;
}

GameEntity::GameEntity(SDL_Renderer *renderer)
{
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
    if ( mTexture != nullptr && mTransform != nullptr)
    {
        mTexture->Render(mRenderer,
                         mTransform->GetPosX(),
                         mTransform->GetPosY(),
                         mTexture->GetWidth(),
                         mTexture->GetHeight());
    }
}

void GameEntity::AddTextureComponent()
{
    mTexture = new TextureComponent();
}

void GameEntity::AddTextureComponent(std::string filepath)
{
    mTexture = new TextureComponent();
    mTexture->LoadFromFile(mRenderer, filepath);
}

TextureComponent& GameEntity::GetTextureComponent()
{
    return *mTexture;
}

void GameEntity::AddTransformComponent()
{
    mTransform = new TransformComponent();
}

TransformComponent& GameEntity::GetTransformComponent()
{
    return *mTransform;
}

void GameEntity::AddMovementComponent()
{
    mMovement = new MovementComponent();
}

MovementComponent& GameEntity::GetMovementComponent()
{
    return *mMovement;
}

SDL_Renderer* GameEntity::GetRenderer()
{
    return mRenderer;
}

