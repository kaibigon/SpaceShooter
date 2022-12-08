//
//  entryPoint.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>
#include <sstream>

#include "consts.h"
#include "SDLApp.hpp"

#include "../include/ECS/Coordinator.h"
#include "../include/Components/Components.h"
#include "../include/Systems/MovementSystem.hpp"
#include "../include/Systems/RenderSystem.hpp"
#include "../include/Systems/TimeSystem.hpp"

// well I dont think one or two global variables is that evil... right -.-?
//Coordinator gCoordinator;

void HandleEvents()
{
    
}

void HandleUpdate()
{
}

void HandleRendering()
{
}

int main( int argc, char* args[] )
{
    const char* title = "Boden Hao Leng";
    SDLApp* app;
    
    app = new SDLApp(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT);
    app->Init();
//    app->SetEventCallback(HandleEvents);
//    app->SetUpdateCallback(HandleUpdate);
//    app->SetRenderCallback(HandleRendering);
    app->RunLoop();
//    Mix_FreeMusic( gMusic );
    delete app;

    return 0;
}
