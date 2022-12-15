//
//  SystemManager.h
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/30.
//

#ifndef SystemManager_h
#define SystemManager_h

#include <cassert>
#include <memory>
#include <unordered_map>

#include "System.h"
#include "Entity.h"
#include "EntityManager.h"

class SystemManager
{
public:
    template<typename T>
    std::shared_ptr<T> RegisterSystem()
    {
        const char* typeName = typeid(T).name();
        
        assert(mSystems.find(typeName) == mSystems.end() && "Registering system more than once.");
        
        auto system = std::make_shared<T>();
        mSystems.insert({typeName, system});
        return system;
    }
    
    template<typename T>
    void SetSignature(Signature signature)
    {
        const char* typeName = typeid(T).name();

        assert(mSystems.find(typeName) != mSystems.end() && "System used before registered.");

        mSignatures.insert({typeName, signature});
    }
    
    void EntityDestroyed(Entity entity)
    {
        for (auto const& pair : mSystems)
        {
            auto const& system = pair.second;

            system->mEntities.erase(entity);
        }
    }

    // TODO: add a event system to trigger this function
    void EntitySignatureChanged(Entity entity, Signature entitySignature)
    {
        for (auto const& pair : mSystems)
        {
            auto const& type = pair.first;
            auto const& system = pair.second;
            auto const& systemSignature = mSignatures[type];

            if ((entitySignature & systemSignature) == systemSignature)
            {
                system->mEntities.insert(entity);
            }
            else
            {
                system->mEntities.erase(entity);
            }
        }
    }
    
    std::unordered_map<const char*, Signature>& GetSignatures(){
        return mSignatures;
    }
    
    template<typename T>
    Signature& GetSystemSignature()
    {
        const char* systemName = typeid(T).name();
        return mSignatures[systemName];
    }
    
    template<typename T>
    void AddEntityToSystemRequiredEntities(Entity entity)
    {
        const char* systemName = typeid(T).name();
        
        auto const& system = mSystems[systemName];
        
        system->mEntities.insert(entity);
    }
    
    // TODO:
    template<typename T>
    void RemoveEntityFromSystemRequiredEntities(Entity entity)
    {
        const char* systemName = typeid(T).name();
        
        auto const& system = mSystems[systemName];
        
        system->mEntities.erase(entity);
    }

private:
    std::unordered_map<const char*, Signature> mSignatures{};
    std::unordered_map<const char*, std::shared_ptr<System>> mSystems{};
};
#endif /* SystemManager_h */
