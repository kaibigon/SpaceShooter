//
//  EntityManager.h
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/30.
//

#ifndef EntityManager_h
#define EntityManager_h

#include "Entity.h"
#include <array>
#include <cassert>
#include <queue>

class EntityManager
{
public:
    EntityManager()
    {
        for (Entity entity = 0; entity < MAX_ENTITIES; ++entity) {
            mAvailableEntities.push(entity);
        }
    }
    
    Entity CreateEntity()
    {
        assert(mLivingEntityCount < MAX_ENTITIES && "Too many entities in existence.");

        Entity id = mAvailableEntities.front();
        mAvailableEntities.pop();
        ++mLivingEntityCount;
        
        return id;
    }
    
    void DestroyEntity(Entity entity)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");

        mSignatures[entity].reset();
        mAvailableEntities.push(entity);
        --mLivingEntityCount;
    }

    void SetSignature(Entity entity, Signature signature)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");

        mSignatures[entity] = signature;
    }

    Signature GetSignature(Entity entity)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");

        return mSignatures[entity];
    }
    
    Entity GetNumOfEntities()
    {
        return mAvailableEntities.front();
    }
    
    
    
private:
    std::queue<Entity> mAvailableEntities{};
    std::array<Signature, MAX_ENTITIES> mSignatures{};
    uint32_t mLivingEntityCount{};
};

#endif /* EntityManager_h */
