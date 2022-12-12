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

#include "../ECS/Coordinator.h"
#include "../ECS/System.h"

// transform, render, bullet component
class BulletSystem : public System
{
public:
    void HandleInput(std::shared_ptr<Coordinator>& gCoordinator, SDL_Event &e);
    void SpawnBullet(std::shared_ptr<Coordinator>& gCoordinator);
    void Update();
private:
};
#endif /* BulletSystem_hpp */
