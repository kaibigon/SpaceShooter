//
//  SDLApp.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//

#ifndef SDLApp_hpp
#define SDLApp_hpp

#include <stdio.h>
#include <functional>
#include <iostream>
#include <SDL2/SDL.h>

class SDLApp
{
public:
    SDLApp(const char* title,int x, int y, int w, int h);
    ~SDLApp();
    
    void setEventCallback(std::function<void(void)> func);
    void setRenderCallback(std::function<void(void)> func);
    void runLoop();
    SDL_Renderer* getRenderer() const;
    int getMouseX();
    int getMouseY();
    void stopAppLoop();
    
private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    bool mGameIsRunning = true;
    int mMouseX;
    int mMouseY;
    std::function<void(void)> mEventCallback;
    std::function<void(void)> mRenderCallback;
};
#endif /* SDLApp_hpp */




