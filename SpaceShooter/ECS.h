//
//  ECS.h
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/29.
//

#ifndef ECS_h
#define ECS_h

#include <array>
#include <bitset>
#include <iostream>

class GameEntity;
class Component;

using ComponentTypeID = std::size_t;
constexpr std::size_t MAX_ENTITIES = 5000;
constexpr std::size_t MAX_COMPONENTS = 32;

using ComponentBitset = std::bitset<MAX_COMPONENTS>;
using ComponentArray = std::array<Component*, MAX_COMPONENTS>;

inline ComponentTypeID getUniqueComponentID()
{
    static ComponentTypeID lastID = 0;
    return lastID++;
}

template<typename T>
inline ComponentTypeID getComponentTypeID() noexcept
{
    static const ComponentTypeID typeID = getUniqueComponentID();
    return typeID;
}

#endif /* ECS_h */
