//
//  EntityManager.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/29.
//

#ifndef EntityManager_hpp
#define EntityManager_hpp

#include <stdio.h>
#include <vector>
#include "GameEntity.hpp"
class EntityManager
{
private:
    std::vector<std::unique_ptr<GameEntity>> entities;
    
public:
    void Update();
    void Render();
    void Refresh();
    GameEntity& AddEntity();
};
#endif /* EntityManager_hpp */
