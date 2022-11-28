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

// okey how Im gonna deal with you -.-
GameEntity* bgEntity;

void HandleEvents(){
    SDL_Event event;

    // (1) Handle Input
    // Start our event loop
    while(SDL_PollEvent(&event)){
        // Handle each specific event
        if(event.type == SDL_QUIT){
            app->StopAppLoop();
        }
        // Detect collision from our two shapes if mouse
        // button is pressed
        if(event.button.button == SDL_BUTTON_LEFT){

        }
    }
}

void HandleRendering(){
    // Set draw positions and size
    bgEntity->Render();
}

int main( int argc, char* args[] )
{
    // Setup the SDLApp
    const char* title = "New SDL2 Abstraction";
    app = new SDLApp(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT);

    // testing rendering
    bgEntity = new GameEntity(app->GetRenderer());
    bgEntity->AddTextureComponent("./SpaceShooter/Assets/bg.png");
    bgEntity->GetTextureComponent().SetAlpha(50);
    bgEntity->GetTextureComponent().SetWidth(SCREEN_WIDTH);
    bgEntity->GetTextureComponent().SetHeight(SCREEN_HEIGHT);
    bgEntity->SetPosX(0);
    bgEntity->SetPosY(0);
    
    // Set callback functions
    app->SetEventCallback(HandleEvents);
    app->SetRenderCallback(HandleRendering);
    // Run our application until terminated
    app->RunLoop();

    delete bgEntity;
    delete app;

    return 0;
}
