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
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>

#include "consts.h"
#include "../include/ECS/Coordinator.h"
#include "../include/Components/Components.h"
#include "../include/Systems/TimeSystem.hpp"
#include "../include/Systems/RenderSystem.hpp"
#include "../include/Systems/MovementSystem.hpp"
#include "../include/Systems/InputSystem.hpp"
#include "../include/Systems/AssetManager.hpp"

class SDLApp
{
public:
    SDLApp(const char* title,int x, int y, int w, int h);
    ~SDLApp();
    SDL_Renderer* GetRenderer() const;
    
    void EcsInit();
    void EcsRegiesterComponents();
    void EcsCreateInitialEntities();
    void EcsRegisterSystems();
    
    void Init();
    void Run();
    void Stop();
    
private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Event event;
    
    std::shared_ptr<Coordinator> gCoordinator;
    std::shared_ptr<TimeSystem> timeSystem;
    std::shared_ptr<RenderSystem> renderSystem;
    std::shared_ptr<MovementSystem> movementSystem;
    std::shared_ptr<InputSystem> inputSystem;
    std::shared_ptr<BulletSystem> bulletSystem;
    std::shared_ptr<AssetManager> assetManager;
    Mix_Music *gMusic = NULL;
    
    bool mGameIsRunning = true;
    float mLastFrameTicks = 0;
};
#endif /* SDLApp_hpp */




