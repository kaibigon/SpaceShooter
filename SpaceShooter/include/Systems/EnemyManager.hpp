//
//  EnemyManager.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/15.
//

#ifndef EnemyManager_hpp
#define EnemyManager_hpp

#include <stdio.h>
#include "../../src/consts.h"
#include "../ECS/Entity.h"
#include "../ECS/Coordinator.h"
#include "../ECS/System.h"
#include "../Systems/RenderSystem.hpp"
#include "../Systems/MovementSystem.hpp"
#include "../Systems/RenderSystem.hpp"
#include "../Systems/EnemySystem.hpp"
#include "../Components/Components.h"

class EnemyManager
{
public:
    static EnemyManager& GetInstance();
    void SpawnEnemy(std::shared_ptr<Coordinator>& gCoordinator, std::shared_ptr<EnemySystem> enemySystem, std::shared_ptr<RenderSystem> renderSystem, SDL_Renderer *renender);
    void Update(std::shared_ptr<Coordinator>& gCoordinator, std::shared_ptr<EnemySystem> enemySystem, std::shared_ptr<RenderSystem> renderSystem, SDL_Renderer *renender, Entity player);
private:
    EnemyManager();
    EnemyManager(EnemyManager const&);
    Uint32 mSpawnInterval = 500;
    Uint32 mLastSpawnTime = 0;
    int mNumOfEnemies = 0;
};
#endif /* EnemyManager_hpp */
