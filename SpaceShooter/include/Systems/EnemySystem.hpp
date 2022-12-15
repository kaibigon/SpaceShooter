//
//  EnemySystem.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/15.
//

#ifndef EnemySystem_hpp
#define EnemySystem_hpp

#include <stdio.h>
#include "../ECS/Entity.h"
#include "../ECS/Coordinator.h"
#include "../ECS/System.h"
#include "../Systems/RenderSystem.hpp"
#include "../Systems/MovementSystem.hpp"
#include "../Systems/RenderSystem.hpp"
#include "../Components/Components.h"

class EnemySystem : public System
{
public:
    void ChasePlayer(std::shared_ptr<Coordinator>& gCoordinator, Entity player);
    void Update(std::shared_ptr<Coordinator>& gCoordinator);
private:
    
};
#endif /* EnemySystem_hpp */
