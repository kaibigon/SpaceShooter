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
#include <SDL2_image/SDL_image.h>

class SDLApp
{
public:
    SDLApp(const char* title,int x, int y, int w, int h);
    ~SDLApp();
    
    void SetEventCallback(std::function<void(void)> func);
    void SetRenderCallback(std::function<void(void)> func);
    void RunLoop();
    SDL_Renderer* GetRenderer() const;
    int GetMouseX();
    int GetMouseY();
    void StopAppLoop();
    
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




