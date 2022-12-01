//
//  MovementComponent.h
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/1.
//

#ifndef MovementComponent_h
#define MovementComponent_h

#include <SDL2/SDL.h>

struct MovementComponent
{
    int velX = 0;
    int velY = 0;
    int velValue = 0;
    int accer = 0;
};

#endif /* MovementComponent_h */
