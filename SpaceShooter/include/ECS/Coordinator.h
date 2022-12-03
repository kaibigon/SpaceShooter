//
//  Coordinator.h
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/30.
//

#ifndef Coordinator_h
#define Coordinator_h

#include "ComponentManager.h"
#include "EntityManager.h"
#include "SystemManager.h"
#include "Entity.h"
#include <memory>
#include <queue>

class Coordinator
{
public:
    void Init()
    {
        mComponentManager = std::make_unique<ComponentManager>();
        mEntityManager = std::make_unique<EntityManager>();
        mSystemManager = std::make_unique<SystemManager>();
    }
    
    // Entity methods
    Entity CreateEntity()
    {
        return mEntityManager->CreateEntity();
    }
    
    void DestroyEntity(Entity entity)
    {
        mEntityManager->DestroyEntity(entity);

        mComponentManager->EntityDestroyed(entity);

        mSystemManager->EntityDestroyed(entity);
    }
    
    // Component methods
    template<typename T>
    void RegisterComponent()
    {
        mComponentManager->RegisterComponent<T>();
    }
    
    template<typename T>
    void AddComponent(Entity entity, T component)
    {
        mComponentManager->AddComponent<T>(entity, component);

        auto signature = mEntityManager->GetSignature(entity);
        signature.set(mComponentManager->GetComponentType<T>(), true);
        mEntityManager->SetSignature(entity, signature);

//        mSystemManager->EntitySignatureChanged(entity, signature);
    }
    
    template<typename T>
    void RemoveComponent(Entity entity)
    {
        mComponentManager->RemoveComponent<T>(entity);

        auto signature = mEntityManager->GetSignature(entity);
        signature.set(mComponentManager->GetComponentType<T>(), false);
        mEntityManager->SetSignature(entity, signature);

//        mSystemManager->EntitySignatureChanged(entity, signature);
    }
    
    template<typename T>
    T& GetComponent(Entity entity)
    {
        return mComponentManager->GetComponent<T>(entity);
    }

    template<typename T>
    ComponentType GetComponentType()
    {
        return mComponentManager->GetComponentType<T>();
    }

    // System methods
    template<typename T>
    std::shared_ptr<T> RegisterSystem()
    {
        return mSystemManager->RegisterSystem<T>();
    }

    template<typename T>
    void SetSystemSignature(Signature signature)
    {
        mSystemManager->SetSignature<T>(signature);
    }
    
//     find all entities that have the components system requires.
    template<typename T>
    void SetEntitiesForSystem()
    {
        const char* systemName = typeid(T).name();
        
        Signature systemSignature = mSystemManager->GetSystemSignature<T>();

        Entity numOfEntities = mEntityManager->GetNumOfEntities();
        
        for(std::uint32_t i = 0; i < numOfEntities; i++)
        {
            Signature entitySignature = mEntityManager->GetSignature(i);
            
            if ((entitySignature & systemSignature) == systemSignature)
            {
//                system->mEntities.insert(i);
                mSystemManager->AddEntityToSystemRequiredEntities<T>(i);
            }
            else
            {
//                system->mEntities.erase(i);
            }
        }
    }

    void EntitySignatureChanged(Entity entity, Signature entitySignature)
    {
        mSystemManager->EntitySignatureChanged(entity, entitySignature);
    }
    
    void SetTag(Entity entity, const char* tagName)
    {
        Tag.insert({entity, tagName});
    }
    
    std::unordered_map<Entity, const char*>& GetTag()
    {
        return Tag;
    }
    
    bool HasTag(Entity entity)
    {
        return Tag.find(entity) != Tag.end();
    }
    
    
private:
    std::unique_ptr<ComponentManager> mComponentManager;
    std::unique_ptr<EntityManager> mEntityManager;
    std::unique_ptr<SystemManager> mSystemManager;
    std::unordered_map<Entity, const char*> Tag{};
};
#endif /* Coordinator_h */
