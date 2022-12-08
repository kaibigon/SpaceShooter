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

void RenderSystem::LoadTexture(std::shared_ptr<Coordinator>& gCoordinator, Entity entity, SDL_Renderer *renender, std::string path)
{
    SDL_Texture *newTexture = NULL;
    
    SDL_Surface *newSurface = AssetManager::GetInstance().GetSurface(path.c_str());
    
    newTexture = SDL_CreateTextureFromSurface(renender, newSurface);
    
    auto& textureComponent = gCoordinator->GetComponent<TextureComponent>(entity);
    textureComponent.texture = newTexture;
}

void RenderSystem::LoadFromRenderedText(std::shared_ptr<Coordinator>& gCoordinator, SDL_Renderer *renender, std::string path, std::string textureText, SDL_Color textColor )
{
    
    for(auto const& entity : mEntities)
    {
        if(!gCoordinator->HasTag(entity) || std::strcmp(gCoordinator->GetTag()[entity], "UI")) continue;
        auto& textureComponent = gCoordinator->GetComponent<TextureComponent>(entity);
        textureComponent.font = TTF_OpenFont(path.c_str(), 20);
       
        SDL_Surface* textSurface = TTF_RenderText_Solid( textureComponent.font, textureComponent.text.c_str(), textColor );

        if( textSurface != NULL )
        {
            // Create texture from surface pixels
            // newTexture = SDL_CreateTextureFromSurface( renender, textSurface );
            textureComponent.texture = SDL_CreateTextureFromSurface( renender, textSurface );
            if( textSurface == NULL )
            {
                printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
            }
            else
            {
                //Get image dimensions
                textureComponent.width = textSurface->w;
                textureComponent.height = textSurface->h;
            }

            //Get rid of old surface
            SDL_FreeSurface( textSurface );
        }
        else
        {
            printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
        }
    }
}

void RenderSystem::SetRenderRange(std::shared_ptr<Coordinator>& gCoordinator, Entity entity, int width, int height)
{
    auto& textureComponent = gCoordinator->GetComponent<TextureComponent>(entity);
    textureComponent.dst.w = width;
    textureComponent.dst.h = height;
}

void RenderSystem::Render(std::shared_ptr<Coordinator>& gCoordinator, SDL_Renderer *renender)
{
    for (auto const& entity : mEntities)
    {
        auto& textureComponent = gCoordinator->GetComponent<TextureComponent>(entity);
        auto& transformComponent = gCoordinator->GetComponent<TransformComponent>(entity);
        textureComponent.dst.x = transformComponent.x;
        textureComponent.dst.y = transformComponent.y;
        SDL_RenderCopy(renender, textureComponent.texture, NULL, &textureComponent.dst);
    }
}
