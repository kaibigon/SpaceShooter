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
    mText.str("");
    mFrames = 0;
}

KTimer::~KTimer()
{
    mTexture.free();
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

void KTimer::handleEvent(SDL_Event &e)
{
    if( e.type == SDL_KEYDOWN )
    {
        if(e.key.keysym.sym == SDLK_n)
        {
            if(isStarted())
            {
                stop();
            }
            else
            {
                start();
            }
        }
        else if (e.key.keysym.sym == SDLK_m)
        {
            if(isPaused())
            {
                resume();
            }
            else
            {
                pause();
            }
        }
    }
}

void KTimer::setTexture(LTexture texture)
{
    mTexture = texture;
}

void KTimer::updateTimeText()
{
    mText.str("");
    mText << "Time: " << round(getTicks() / 1000.f);
}

void KTimer::updateFpsText()
{
    mText.str("");
    mText << "FPS: " << round(mFrames / (getTicks() / 1000.f ));
}

void KTimer::updateFrames()
{
    mFrames++;
}

void KTimer::render(TTF_Font *font, SDL_Renderer *renderer, SDL_Color textColor,
                    int x, int y, int width, int height)
{
    mTexture.loadFromRendereredText(font, renderer, mText.str().c_str(), textColor);
    mTexture.render(renderer, x, y, width, height);
}
