//
//  timer.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/27.
//
#pragma once

#ifndef KTimer_hpp
#define KTimer_hpp

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include <stdint.h>
#include <sstream>

#include "TextureLoader.hpp"

#endif /* timer_hpp */

class KTimer {
public:
    KTimer();
    ~KTimer();
    
    void start();
    void stop();
    void pause();
    void resume();
    
    Uint32 getTicks();
    
    bool isStarted();
    bool isPaused();
    void handleEvent(SDL_Event &e);
    void setTexture(LTexture texture);
    void updateTimeText();
    void updateFpsText();
    void updateFrames();
    void render(TTF_Font *font, SDL_Renderer *renender, SDL_Color textColor, int x, int y, int width, int height);
    
private:
    LTexture mTexture;
    std::stringstream mText;
    
    uint32_t mStartTicks;
    uint32_t mPausedTicks;
    
    int mFrames;
    
    bool mPaused;
    bool mStarted;
};
