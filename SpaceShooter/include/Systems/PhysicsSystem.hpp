//
//  PhysicsSystem.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/30.
//

#ifndef PhysicsSystem_hpp
#define PhysicsSystem_hpp

#include <stdio.h>
#include "../ECS/System.h"

class PhysicsSystem : public System
{
public:
    void Init();

    void Update();
};

#endif /* PhysicsSystem_hpp */
