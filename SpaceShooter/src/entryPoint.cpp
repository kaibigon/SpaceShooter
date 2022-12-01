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

#include "consts.h"
#include "SDLApp.hpp"

#include "../include/ECS/Coordinator.h"
#include "../include/Components/TransformComponent.h"
#include "../include/Components/TextureComponent.h"
#include "../include/Components/MovementComponent.h"
#include "../include/Systems/PhysicsSystem.hpp"
#include "../include/Systems/RenderSystem.hpp"

SDLApp* app;

Coordinator gCoordinator;

void HandleEvents()
{
    SDL_Event event;

    while(SDL_PollEvent(&event)){
        
        if(event.type == SDL_QUIT){
            app->StopAppLoop();
        }
        
    }
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

    // Init Coordinator
    
    gCoordinator.Init();
    gCoordinator.RegisterComponent<TransformComponent>();
    gCoordinator.RegisterComponent<TextureComponent>();
    gCoordinator.RegisterComponent<MovementComponent>();
    
    // Init entity and attach components
    Entity testEntity = gCoordinator.CreateEntity();
    Entity bgEntity = gCoordinator.CreateEntity();
    Entity player = gCoordinator.CreateEntity();
    
    auto physicsSystem = gCoordinator.RegisterSystem<PhysicsSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<TransformComponent>());
        signature.set(gCoordinator.GetComponentType<MovementComponent>());
        gCoordinator.SetSystemSignature<PhysicsSystem>(signature);
        gCoordinator.EntitySignatureChanged(player, signature);
    }
    
    auto renderSystem = gCoordinator.RegisterSystem<RenderSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<TextureComponent>());
        signature.set(gCoordinator.GetComponentType<TransformComponent>());
        gCoordinator.SetSystemSignature<RenderSystem>(signature);
        gCoordinator.EntitySignatureChanged(bgEntity, signature);
        gCoordinator.EntitySignatureChanged(player, signature);
    }
   
    gCoordinator.SetTag(player, "Player");
    printf("%s\n", gCoordinator.GetTag()[player]);
    gCoordinator.AddComponent(testEntity, TransformComponent{});
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
    
    // Init Systems
    

    physicsSystem->Init();
    
    
    
    // System init 
    renderSystem->LoadTexture(bgEntity, app->GetRenderer(), "./SpaceShooter/Assets/bg.png");
    renderSystem->SetRenderRange(bgEntity, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    renderSystem->LoadTexture(player, app->GetRenderer(), "./SpaceShooter/Assets/dot.bmp");
    renderSystem->SetRenderRange(player, 20, 20);
    
    bool quit = false;
    while(!quit){

        SDL_Event event;

        while(SDL_PollEvent(&event)){
            
            if(event.type == SDL_QUIT){
                app->StopAppLoop();
                quit = true;
            }
            physicsSystem->HandleInput(event);
        }
        
        SDL_RenderClear(app->GetRenderer());
        SDL_SetRenderDrawColor(app->GetRenderer(),255,255,255,SDL_ALPHA_OPAQUE);
        
        physicsSystem->Update();
        renderSystem->Render(app->GetRenderer());
        
        SDL_RenderPresent(app->GetRenderer());
        
        // TODO: Eventually set a frame cap
    }
//    app->SetEventCallback(HandleEvents);
//    app->SetUpdateCallback(HandleUpdate);
//    app->SetRenderCallback(HandleRendering);
//    app->RunLoop();
//
    delete app;

    return 0;
}
