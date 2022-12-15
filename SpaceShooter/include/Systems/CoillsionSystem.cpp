//
//  CoillsionSystem.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/13.
//

#include "CoillsionSystem.hpp"

bool CollisionSystem::HasSameLayer(std::shared_ptr<Coordinator>& gCoordinator, Entity entityA, Entity entityB)
{
    auto& colliderA = gCoordinator->GetComponent<CollisionComponent>(entityA);
    auto& colliderB = gCoordinator->GetComponent<CollisionComponent>(entityB);
 
    return colliderA.layer == colliderB.layer;
}

bool CollisionSystem::IsOverlapping(std::shared_ptr<Coordinator> &gCoordinator, Entity entityA, Entity entityB)
{
    auto& colliderA = gCoordinator->GetComponent<CollisionComponent>(entityA);
    auto& colliderB = gCoordinator->GetComponent<CollisionComponent>(entityB);
    
    auto& transformA = gCoordinator->GetComponent<TransformComponent>(entityA);
    auto& transformB = gCoordinator->GetComponent<TransformComponent>(entityB);
    
    // TODO: should make a vector2 for position
    float lb_Ax = transformA.x - colliderA.width/2;
    float lb_Ay = transformA.y - colliderA.height/2;
    
    float ur_Ax = transformA.x + colliderA.width/2;
    float ur_Ay = transformA.y + colliderA.height/2;
   
    float lb_Bx = transformB.x - colliderB.width/2;
    float lb_By = transformB.y - colliderB.height/2;
    
    return lb_Bx > lb_Ax && lb_Bx < ur_Ax && lb_By > lb_Ay && lb_By < ur_Ay;
}

void CollisionSystem::Update(std::shared_ptr<Coordinator>& gCoordinator)
{
    for (auto const& entityA : mEntities )
    {
        for (auto const& entityB : mEntities )
        {
            if (entityA == entityB || HasSameLayer(gCoordinator, entityA, entityB))
            {
                continue;
            }
            
            if(IsOverlapping(gCoordinator, entityA, entityB))
            {
                // should be a template, call corresponding event depends on the component type it has???
                // entityA.callColiisionEvent
                
                // entityB.callCollisionEvent
            }
        }
    }
}
