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

#include "TextureLoader.hpp"
#include "KTimer.hpp"
#include "consts.h"
#include "Player.hpp"
#include "SDLApp.hpp"
#include "GameEntity.hpp"

SDLApp* app;

GameEntity* bgEntity;

void HandleEvents(){
    SDL_Event event;

    // (1) Handle Input
    // Start our event loop
    while(SDL_PollEvent(&event)){
        // Handle each specific event
        if(event.type == SDL_QUIT){
            app->stopAppLoop();
        }
        // Detect collision from our two shapes if mouse
        // button is pressed
        if(event.button.button == SDL_BUTTON_LEFT){

        }
    }
}

void HandleRendering(){
    // Set draw positions and size
    bgEntity->render();
}

int main( int argc, char* args[] )
{
    // Setup the SDLApp
    const char* title = "New SDL2 Abstraction";
    app = new SDLApp(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT);

    // testing rendering
    bgEntity = new GameEntity(app->getRenderer());
    bgEntity->getTexture().loadFromFile(bgEntity->getRenderer(), "./SpaceShooter/Assets/bg.png");
    bgEntity->getTexture().setAlpha(50);
    bgEntity->getTexture().setWidth(SCREEN_WIDTH);
    bgEntity->getTexture().setHeight(SCREEN_HEIGHT);
    bgEntity->setPosX(0);
    bgEntity->setPosY(0);
    
    // Set callback functions
    app->setEventCallback(HandleEvents);
    app->setRenderCallback(HandleRendering);
    // Run our application until terminated
    app->runLoop();

    bgEntity->getTexture().free();
    // Clean up our application
    delete app;

    return 0;
}
