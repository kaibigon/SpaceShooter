//
//  InputSystem.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/12.
//

#ifndef InputSystem_hpp
#define InputSystem_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "../ECS/System.h"
#include "../ECS/Coordinator.h"
#include "../Components/Components.h"
#include "BulletSystem.hpp"

class InputSystem : public System
{
public:
    void HandleMovementInput(std::shared_ptr<Coordinator>& gCoordinator);
    void HandleShootingInput(std::shared_ptr<Coordinator>& gCoordinator, std::shared_ptr<RenderSystem> renderSystem, SDL_Renderer *renender, float x, float y, Direction direction, std::shared_ptr<BulletSystem> bulletSystem);
private:
    // TODO: should probably move to smh like player controller/weapon componnet, will just leave it here now
    float mShootingInterval = 500;
    float mLastShootTime = 0;
};
#endif /* InputSystem_hpp */
