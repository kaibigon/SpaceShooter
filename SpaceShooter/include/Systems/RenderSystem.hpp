//
//  RenderSystem.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/1.
//

#ifndef RenderSystem_hpp
#define RenderSystem_hpp

#include <stdio.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "../ECS/Entity.h"
#include "../ECS/System.h"

class RenderSystem : public System
{
public:
    void LoadTexture(Entity entity, SDL_Renderer *renender, std::string path);
    void LoadFromRenderedText(Entity entity, SDL_Renderer *renender, std::string path, std::string textureText, SDL_Color textColor );
    void SetRenderRange(Entity entity, int width, int height);
    void Render(SDL_Renderer *renender);
private:
    
};
#endif /* RenderSystem_hpp */
