//
//  PlayermovementComponent.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//

#ifndef PlayermovementComponent_hpp
#define PlayermovementComponent_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

#include "TransformComponent.hpp"
class MovementComponent
{
public:
    MovementComponent();
    ~MovementComponent();
    
    void HandleEvent(SDL_Event &e);
    void Update(TransformComponent* transformComponent);
    
private:
    int mVelValue;
    int mVelY;
    int mVelX;
};

#endif /* PlayermovementComponent_hpp */
