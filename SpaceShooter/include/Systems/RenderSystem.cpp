//
//  RenderSystem.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/1.
//

#include <SDL2/SDL.h>

#include "RenderSystem.hpp"
#include "AssetManager.hpp"
#include "../ECS/Coordinator.h"
#include "../Components/Components.h"


extern Coordinator gCoordinator;

void RenderSystem::LoadTexture(Entity entity, SDL_Renderer *renender, std::string path)
{
    SDL_Texture *newTexture = NULL;
    
    SDL_Surface *newSurface = AssetManager::GetInstance().GetSurface(path.c_str());
    
    newTexture = SDL_CreateTextureFromSurface(renender, newSurface);
    
    auto& textureComponent = gCoordinator.GetComponent<TextureComponent>(entity);
    textureComponent.texture = newTexture;
}

void RenderSystem::SetRenderRange(Entity entity, int width, int height)
{
    auto& textureComponent = gCoordinator.GetComponent<TextureComponent>(entity);
    textureComponent.dst.w = width;
    textureComponent.dst.h = height;
}

void RenderSystem::Render(SDL_Renderer *renender)
{
    for (auto const& entity : mEntities)
    {
        auto& textureComponent = gCoordinator.GetComponent<TextureComponent>(entity);
        auto& transformComponent = gCoordinator.GetComponent<TransformComponent>(entity);
        textureComponent.dst.x = transformComponent.x;
        textureComponent.dst.y = transformComponent.y;
        SDL_RenderCopy(renender, textureComponent.texture, NULL, &textureComponent.dst);
    }
}
