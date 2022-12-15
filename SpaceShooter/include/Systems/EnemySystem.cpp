//
//  EnemySystem.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/15.
//

#include "EnemySystem.hpp"

void EnemySystem::ChasePlayer(std::shared_ptr<Coordinator> &gCoordinator, Entity player)
{
//    auto& playerMovement = gCoordinator->GetComponent<MovementComponent>(player);
    auto& playerTransform = gCoordinator->GetComponent<TransformComponent>(player);
    
    for(auto const& enemy : mEntities)
    {
        auto& enemyMovement = gCoordinator->GetComponent<MovementComponent>(enemy);
        auto& enemyTransform = gCoordinator->GetComponent<TransformComponent>(enemy);
        
        // TODO: omg I need a vec2
        float vec_x = playerTransform.x - enemyTransform.x;
        float vec_y = playerTransform.y - enemyTransform.y;
        float vec_mag = std::sqrt(std::pow(vec_x, 2) + std::pow(vec_y, 2));
//        float enemy_mag = std::sqrt(std::pow(enemyTransform.x, 2) + std::pow(enemyTransform.y, 2));
        
        float dotProd = vec_x * 1.0 + vec_y * 0 ;
        float dotProd_x = vec_x / vec_mag;
        float dotProd_y = vec_y / vec_mag;
        float cos0 = dotProd / vec_mag;
        float theta = std::acos(cos0);
        float sin0 = std::sin(theta);
        
        printf("%f, %f\n", sin0, cos0);
        // since coordination is differetn, rendering based on left-upper corner
        enemyMovement.velX = enemyMovement.velValue * dotProd_x;
        enemyMovement.velY = enemyMovement.velValue * dotProd_y;
    }
}
