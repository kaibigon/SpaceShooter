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

// require input, movement
class InputSystem : public System
{
public:
    void HandleMovementInput(std::shared_ptr<Coordinator>& gCoordinator);
    void HandleShootingInput(std::shared_ptr<Coordinator>& gCoordinator, std::shared_ptr<RenderSystem> renderSystem, SDL_Renderer *renender, float x, float y, Direction direction, std::shared_ptr<BulletSystem> bulletSystem);
private:
    // some infos to handle shooting, should probably move to smh like player controller/weapon componnet
    float mShootingInterval = 500;
    float mLastShootTime = 0;
};
#endif /* InputSystem_hpp */
