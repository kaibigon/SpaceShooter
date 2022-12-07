//
//  TimeSystem.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/5.
//

#include "TimeSystem.hpp"
#include "../ECS/Coordinator.h"
extern Coordinator gCoordinator;

void TimeSystem::ShowCurrentTime()
{
    for(auto const& entity : mEntities)
    {
        auto& textureComponent = gCoordinator.GetComponent<TextureComponent>(entity);
        auto& timerComponent = gCoordinator.GetComponent<TimerComponnet>(entity);
        std::stringstream tmp;
        tmp.str("");
        tmp << "Time " << GetTicks() << "FPS " << mFps;
        textureComponent.text = tmp.str();
    }
}

void TimeSystem::GetCurrentTime()
{
    
}

void TimeSystem::ShowEclapsedTime()
{
    
}

void TimeSystem::SetStartTime()
{
    for(auto const& entity : mEntities)
    {
        auto& timerComponent = gCoordinator.GetComponent<TimerComponnet>(entity);
        timerComponent.startTime = SDL_GetTicks();
        printf("nmsl");
    }
}

void TimeSystem::StartTime()
{
    mStarted = true;
    mPaused = false;

    mStartTime = SDL_GetTicks();
    mPauseTime = 0;
}

void TimeSystem::StopTime()
{
    mStarted = false;

    mPaused = false;

    mStartTime = 0;
    mPauseTime = 0;
}

void TimeSystem::PauseTime()
{
    //If the timer is running and isn't already paused
    if( mStarted && !mPaused )
    {
        //Pause the timer
        mPaused = true;

        //Calculate the paused ticks
        mPauseTime = SDL_GetTicks() - mStartTime;
        mStartTime = 0;
    }
}

void TimeSystem::ResumeTime()
{
    if( mStarted && mPaused )
    {
        //Unpause the timer
        mPaused = false;

        //Reset the starting ticks
        mStartTime = SDL_GetTicks() - mPauseTime;

        //Reset the paused ticks
        mPauseTime = 0;
    }
}

Uint32 TimeSystem::GetTicks()
{
    //The actual timer time
    Uint32 time = 0;

    //If the timer is running
    if( mStarted )
    {
        //If the timer is paused
        if( mPaused )
        {
            //Return the number of ticks when the timer was paused
            time = mPauseTime;
        }
        else
        {
            //Return the current time minus the start time
            time = SDL_GetTicks() - mStartTime;
        }
    }

    return time;
}

void TimeSystem::HandleInput(SDL_Event &e)
{
    if(e.type == SDL_KEYDOWN)
    {
        if( e.key.keysym.sym == SDLK_o )
        {
            if( mStarted )
            {
                StopTime();
            }
            else
            {
                StartTime();
            }
        }
        else if( e.key.keysym.sym == SDLK_p )
        {
            if( mPaused )
            {
                ResumeTime();
            }
            else
            {
                PauseTime();
            }
        }
    }
}

void TimeSystem::CalFps()
{
    mFpsTicks = SDL_GetTicks();
}

void TimeSystem::StartFps()
{
    mFpsStartTicks = SDL_GetTicks();
}

void TimeSystem::ShowFps()
{
    mFpsTicks = SDL_GetTicks();
    mFrames++;
    mFps = mFrames / (mFpsTicks / 1000);
}

