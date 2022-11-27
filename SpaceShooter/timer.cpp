//
//  timer.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/27.
//

#include "timer.hpp"

KTimer::KTimer()
{
    //Initialize the variables
    mStartTicks = 0;
    mPausedTicks = 0;

    mPaused = false;
    mStarted = false;
}

void KTimer::start()
{
    mStarted = true;
    mPaused = false;
    mStartTicks = SDL_GetTicks();
    mPausedTicks = 0;
}

void KTimer::stop()
{
    mStarted = false;
    mPaused = false;
    mStartTicks = 0;
    mPausedTicks = 0;
}

void KTimer::pause()
{
    if(mStarted && !mPaused)
    {
        mPaused = true;
        mPausedTicks = SDL_GetTicks() - mStartTicks;
        mStartTicks = 0;
    }
}

void KTimer::resume()
{
    if(mStarted && mPaused)
    {
        mPaused = false;
        mStartTicks = SDL_GetTicks() - mPausedTicks;
        mPausedTicks = 0;
    }
}

Uint32 KTimer::getTicks()
{
    Uint32 time = 0;
    
    if(mStarted)
    {
        if(mPaused)
        {
            time = mPausedTicks;
        }
        else
        {
            time = SDL_GetTicks() - mStartTicks;
        }
    }
    return time;
}

bool KTimer::isStarted()
{
    return mStarted;
}

bool KTimer::isPaused()
{
    return mPaused && mStarted;
}
