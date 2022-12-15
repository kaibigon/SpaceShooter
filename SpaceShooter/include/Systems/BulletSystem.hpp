//
//  BulletSystem.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/11.
//

#ifndef BulletSystem_hpp
#define BulletSystem_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

#include "RenderSystem.hpp"
#include "MovementSystem.hpp"
#include "../Components/Components.h"
#include "../ECS/Coordinator.h"
#include "../ECS/System.h"

class BulletSystem : public System
{
public:
    void SpawnBullet(std::shared_ptr<Coordinator>& gCoordinator, std::shared_ptr<RenderSystem> renderSystem, SDL_Renderer *renender, float x, float y, Direction direction);
    void DestoryBullet(std::shared_ptr<Coordinator>& gCoordinator, Entity bullet);
    void OnCollisionEvent(std::shared_ptr<Coordinator>& gCoordinator, Entity bullet);
    void Update(std::shared_ptr<Coordinator>& gCoordinator);
private:
    
};
#endif /* BulletSystem_hpp */
