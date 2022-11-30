//
//  System.h
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/30.
//

#ifndef System_h
#define System_h

#include <set>
#include "Entity.h"

class System
{
public:
    std::set<Entity> mEntities; // entities that are gonna excute system
};

#endif /* System_h */
