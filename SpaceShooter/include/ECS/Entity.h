//
//  Entity.h
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/30.
//

#ifndef Entity_h
#define Entity_h

#include <bitset>
#include <cstdint>

using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 5000;
using Signature = std::bitset<MAX_ENTITIES>;
using ComponentType = std::uint8_t;
const ComponentType MAX_COMPONENTS = 32;


#endif /* Entity_h */
