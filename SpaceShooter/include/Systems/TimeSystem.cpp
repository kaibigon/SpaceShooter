//
//  TimeSystem.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/5.
//

#include "TimeSystem.hpp"
#include "../ECS/Coordinator.h"
extern Coordinator gCoordinator;

void TimeSystem::showCurrentTime()
{
    for(auto const& entity : mEntities)
    {
        auto& textureComponent = gCoordinator.GetComponent<TextureComponent>(entity);
        auto& timerComponent = gCoordinator.GetComponent<TimerComponnet>(entity);
        std::stringstream tmp;
        tmp.str("");
        tmp << "Time " << SDL_GetTicks() - timerComponent.startTime;
        textureComponent.text = tmp.str();
    }
}

void TimeSystem::getCurrentTime()
{
    
}

void TimeSystem::showEclapsedTime()
{
    
}

void TimeSystem::setStartTime()
{
    for(auto const& entity : mEntities)
    {
        auto& timerComponent = gCoordinator.GetComponent<TimerComponnet>(entity);
        timerComponent.startTime = SDL_GetTicks();
        printf("nmsl");
    }
}

