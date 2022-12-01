//
//  RenderSystem.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/1.
//

#ifndef RenderSystem_hpp
#define RenderSystem_hpp

#include <stdio.h>
#include "../ECS/Entity.h"
#include "../ECS/System.h"

class RenderSystem : public System
{
public:
    void LoadTexture(Entity entity, SDL_Renderer *renender, std::string path);
    void SetRenderRange(Entity entity, int width, int height);
    void Render(SDL_Renderer *renender);
private:
    
};
#endif /* RenderSystem_hpp */
