//
//  Component.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/29.
//

#ifndef Component_hpp
#define Component_hpp

#include <stdio.h>
#include "GameEntity.hpp"

class GameEntity;
class Component
{
public:
    Component() = default ;
    virtual ~Component() = default;
    virtual void Init() {}
    virtual void Update() {}
    virtual void Render() {}
    
    GameEntity* entity;
};

#endif /* Component_hpp */
