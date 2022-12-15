//
//  CoillsionSystem.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/13.
//

#ifndef CoillsionSystem_hpp
#define CoillsionSystem_hpp

#include <stdio.h>
#include "../ECS/Entity.h"
#include "../ECS/Coordinator.h"
#include "../ECS/System.h"
#include "../Components/Components.h"

class CollisionSystem : public System
{
public:
    bool HasSameLayer(std::shared_ptr<Coordinator>& gCoordinator, Entity entityA, Entity entityB);
    bool IsOverlapping(std::shared_ptr<Coordinator>& gCoordinator, Entity entityA, Entity entityB);
    void Update(std::shared_ptr<Coordinator>& gCoordinator);
};

#endif /* CoillsionSystem_hpp */
