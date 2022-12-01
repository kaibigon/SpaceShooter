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

    // test code
    gCoordinator.Init();
    Entity testEntity = gCoordinator.CreateEntity();
    Entity bgEntity = gCoordinator.CreateEntity();
    
    gCoordinator.RegisterComponent<TransformComponent>();
    gCoordinator.RegisterComponent<TextureComponent>();
    
    gCoordinator.AddComponent(testEntity, TransformComponent{});
    gCoordinator.AddComponent(bgEntity, TextureComponent{});
    
    auto physicsSystem = gCoordinator.RegisterSystem<PhysicsSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<TransformComponent>());
        gCoordinator.SetSystemSignature<PhysicsSystem>(signature);
        gCoordinator.EntitySignatureChanged(testEntity, signature);
    }

    physicsSystem->Init();
    
    auto renderSystem = gCoordinator.RegisterSystem<RenderSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<TextureComponent>());
        gCoordinator.SetSystemSignature<RenderSystem>(signature);
        gCoordinator.EntitySignatureChanged(bgEntity, signature);
    }
    
    renderSystem->LoadTexture(bgEntity, app->GetRenderer(), "./SpaceShooter/Assets/bg.png");
    renderSystem->SetRenderRange(bgEntity, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    bool quit = false;
    while(!quit){

        SDL_Event event;

        while(SDL_PollEvent(&event)){
            
            if(event.type == SDL_QUIT){
                app->StopAppLoop();
                quit = true;
            }
            
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
