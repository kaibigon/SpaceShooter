//
//  timer.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/27.
//
#pragma once

#ifndef timer_hpp
#define timer_hpp

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdint.h>
#include <sstream>

#endif /* timer_hpp */

class KTimer {
public:
    KTimer();
    
    void start();
    void stop();
    void pause();
    void resume();
    
    Uint32 getTicks();
    
    bool isStarted();
    bool isPaused();
    
private:
    uint32_t mStartTicks;
    uint32_t mPausedTicks;
    
    bool mPaused;
    bool mStarted;
};
