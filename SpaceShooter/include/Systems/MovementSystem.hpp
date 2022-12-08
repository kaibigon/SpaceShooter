//
//  PhysicsSystem.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/30.
//

#ifndef PhysicsSystem_hpp
#define PhysicsSystem_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "../ECS/System.h"
#include "../ECS/Coordinator.h"

class MovementSystem : public System
{
public:
    void Init();
    
    void HandleInput(std::shared_ptr<Coordinator>& gCoordinator, SDL_Event &e);

    void MovementUpdate(std::shared_ptr<Coordinator>& gCoordinator, int velX, int velY);
    
    void Update(std::shared_ptr<Coordinator>& gCoordinator, float deltaTime);
    
private:
//    int mVelX;
//    int mVelY;
//    int mVelValue;
};

#endif /* PhysicsSystem_hpp */
