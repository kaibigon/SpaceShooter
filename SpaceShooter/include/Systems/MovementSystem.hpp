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

class MovementSystem : public System
{
public:
    void Init();
    
    void HandleInput(SDL_Event &e);

    void MovementUpdate(int velX, int velY);
    
    void Update();
    
private:
//    int mVelX;
//    int mVelY;
//    int mVelValue;
};

#endif /* PhysicsSystem_hpp */
