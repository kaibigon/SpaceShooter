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

int main( int argc, char* args[] )
{
    const char* title = ">_<";
    
    SDLApp* app;
    app = new SDLApp(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT);
    app->Init();
    app->Run();
    
    delete app;
    return 0;
}
