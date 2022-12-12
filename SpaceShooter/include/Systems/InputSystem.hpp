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

// require input, movement
class InputSystem : public System
{
public:
    void HandleMovementInput(std::shared_ptr<Coordinator>& gCoordinator, SDL_Event &e);
    void HandleShootInput(std::shared_ptr<Coordinator>& gCoordinator, SDL_Event &e);
};
#endif /* InputSystem_hpp */
