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
    // TODO: this for loop count the full square of entities, we actually just need half of it.
    int flag = 0;
    for(auto const& entityA : mEntities)
    {
        for (auto const& entityB : mEntities) {
            if (HasSameLayer(gCoordinator, entityA, entityB))
            {
                continue;
            }

            // should be a template, call corresponding event depends on the component type it has???
            // And this is soooooo bad, should rework everything ahhhh
            // shouldnt have any system inside other systems, system shouldnt be passed around systems
            if(IsOverlapping(gCoordinator, entityA, entityB))
            {
                if(gCoordinator->HasTag(entityA) && !std::strcmp(gCoordinator->GetTag()[entityA], "Bullet")
                && gCoordinator->HasTag(entityB) && !std::strcmp(gCoordinator->GetTag()[entityB], "Enemy"))
                {
                    gCoordinator->RemoveEntityFromSystem<MovementSystem>(entityA);
                    gCoordinator->RemoveEntityFromSystem<RenderSystem>(entityA);
                    gCoordinator->RemoveEntityFromSystem<BulletSystem>(entityA);
                    gCoordinator->RemoveEntityFromSystem<CollisionSystem>(entityA);
                    gCoordinator->DestroyEntity(entityA);
                    
                    gCoordinator->RemoveEntityFromSystem<MovementSystem>(entityB);
                    gCoordinator->RemoveEntityFromSystem<RenderSystem>(entityB);
                    gCoordinator->RemoveEntityFromSystem<EnemySystem>(entityB);
                    gCoordinator->RemoveEntityFromSystem<CollisionSystem>(entityB);
                    gCoordinator->DestroyEntity(entityB);
                    flag = 1;
                    break;
                }

                if(gCoordinator->HasTag(entityB) && !std::strcmp(gCoordinator->GetTag()[entityA], "Bullet")
                && gCoordinator->HasTag(entityA) && !std::strcmp(gCoordinator->GetTag()[entityB], "Enemy"))
                {
                    gCoordinator->RemoveEntityFromSystem<MovementSystem>(entityB);
                    gCoordinator->RemoveEntityFromSystem<RenderSystem>(entityB);
                    gCoordinator->RemoveEntityFromSystem<BulletSystem>(entityB);
                    gCoordinator->RemoveEntityFromSystem<CollisionSystem>(entityB);
                    gCoordinator->DestroyEntity(entityB);
                    
                    gCoordinator->RemoveEntityFromSystem<MovementSystem>(entityA);
                    gCoordinator->RemoveEntityFromSystem<RenderSystem>(entityA);
                    gCoordinator->RemoveEntityFromSystem<EnemySystem>(entityA);
                    gCoordinator->RemoveEntityFromSystem<CollisionSystem>(entityA);
                    gCoordinator->DestroyEntity(entityA);
                    flag = 1;
                    break;
                }
                printf("nmsl\n");
            }
        }
        
        if(flag == 1) break;
    }
}
