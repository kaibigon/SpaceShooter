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
SDLApp* app;
Coordinator gCoordinator;

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
    app = new SDLApp(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT);

    Mix_Music *gMusic = NULL;
    
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    
    if( TTF_Init() == -1 )
    {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    
    // Init Coordinator
    
    gCoordinator.Init();
    gCoordinator.RegisterComponent<TransformComponent>();
    gCoordinator.RegisterComponent<TextureComponent>();
    gCoordinator.RegisterComponent<MovementComponent>();
    gCoordinator.RegisterComponent<UITextComponent>();
    gCoordinator.RegisterComponent<TimerComponnet>();
    
    // Init entity and attach components
    Entity testEntity = gCoordinator.CreateEntity();
    Entity bgEntity = gCoordinator.CreateEntity();
    Entity player = gCoordinator.CreateEntity();
    Entity timer = gCoordinator.CreateEntity();
    
    auto movementSystem = gCoordinator.RegisterSystem<MovementSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<TransformComponent>());
        signature.set(gCoordinator.GetComponentType<MovementComponent>());
        gCoordinator.SetSystemSignature<MovementSystem>(signature);
//        gCoordinator.EntitySignatureChanged(player, signature);
    }
    
    auto renderSystem = gCoordinator.RegisterSystem<RenderSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<TextureComponent>());
        signature.set(gCoordinator.GetComponentType<TransformComponent>());
        gCoordinator.SetSystemSignature<RenderSystem>(signature);
//        gCoordinator.EntitySignatureChanged(bgEntity, signature);
//        gCoordinator.EntitySignatureChanged(player, signature);
    }
    
    auto timeSystem = gCoordinator.RegisterSystem<TimeSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<TimerComponnet>());
        gCoordinator.SetSystemSignature<TimeSystem>(signature);
    }
   
    gCoordinator.SetTag(player, "Player");
    printf("%s\n", gCoordinator.GetTag()[player]);
    gCoordinator.AddComponent(testEntity, TransformComponent{});
    
    gCoordinator.AddComponent(timer, TransformComponent{
        .x = 7*SCREEN_WIDTH/10,
        .y = 0,
        .z = 0,
    });
    gCoordinator.AddComponent(timer, TextureComponent{});
    gCoordinator.AddComponent(timer, TimerComponnet{});
    
    gCoordinator.AddComponent(bgEntity, TransformComponent{
        .x = 0,
        .y = 0,
        .z = 0,
    });
    gCoordinator.AddComponent(bgEntity, TextureComponent{});
    gCoordinator.AddComponent(player, TransformComponent{
        .x = 0,
        .y = 0,
        .z = 0,
    });
    gCoordinator.AddComponent(player, TextureComponent{});
    gCoordinator.AddComponent(player, MovementComponent{});
    
    // TODO add event to add/remove entity when there is a change of components in entities
    gCoordinator.SetEntitiesForSystem<RenderSystem>();
    gCoordinator.SetEntitiesForSystem<MovementSystem>();
    gCoordinator.SetEntitiesForSystem<TimeSystem>();
    
    // Init Systems
    movementSystem->Init();
    
    renderSystem->LoadTexture(bgEntity, app->GetRenderer(), "./SpaceShooter/Assets/bg.png");
    renderSystem->SetRenderRange(bgEntity, SCREEN_WIDTH, SCREEN_HEIGHT);
    renderSystem->LoadTexture(player, app->GetRenderer(), "./SpaceShooter/Assets/dot.bmp");
    renderSystem->SetRenderRange(player, 20, 20);
    
    renderSystem->LoadFromRenderedText(timer, app->GetRenderer(), "./SpaceShooter/Assets/pixel.TTF", "here to show time", {100, 100, 100, 255});
    renderSystem->SetRenderRange(timer, 3 * SCREEN_WIDTH/10, 100);
    timeSystem->setStartTime();
    
    bool quit = false;
    SDL_Event event;
    gMusic = Mix_LoadMUS("./SpaceShooter/Assets/bgMusic.mp3");

    while(!quit){

        while(SDL_PollEvent(&event)){
            
            if(event.type == SDL_QUIT){
                app->StopAppLoop();
                quit = true;
            }else if( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN )
            {
                timeSystem->setStartTime();
            }
            movementSystem->HandleInput(event);
        }
        
        if( Mix_PlayingMusic() == 0 )
        {
            Mix_PlayMusic( gMusic, -1 );
        }
        
        SDL_RenderClear(app->GetRenderer());
        SDL_SetRenderDrawColor(app->GetRenderer(),255,255,255,SDL_ALPHA_OPAQUE);
        
        timeSystem->showCurrentTime();
        renderSystem->LoadFromRenderedText(timer, app->GetRenderer(), "./SpaceShooter/Assets/pixel.TTF", "here to show time", {100, 100, 100, 255});
        movementSystem->Update();
        renderSystem->Render(app->GetRenderer());
        
        SDL_RenderPresent(app->GetRenderer());
        
        // TODO: Eventually set a frame cap
    }
//    app->SetEventCallback(HandleEvents);
//    app->SetUpdateCallback(HandleUpdate);
//    app->SetRenderCallback(HandleRendering);
//    app->RunLoop();
//    app->RunLoop();
//
    Mix_FreeMusic( gMusic );
    delete app;

    return 0;
}
