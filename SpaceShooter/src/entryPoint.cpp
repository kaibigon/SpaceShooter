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
#include "../include/Systems/PhysicsSystem.hpp"

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
    
    gCoordinator.RegisterComponent<TransformComponent>();
    gCoordinator.AddComponent(testEntity, TransformComponent{});
    auto physicsSystem = gCoordinator.RegisterSystem<PhysicsSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<TransformComponent>());
        gCoordinator.SetSystemSignature<PhysicsSystem>(signature);
        gCoordinator.EntitySignatureChanged(testEntity, signature);
    }

    physicsSystem->Init();
    
    while(true){
        
        SDL_RenderClear(app->GetRenderer());

        SDL_SetRenderDrawColor(app->GetRenderer(),0,0,0,SDL_ALPHA_OPAQUE);
        physicsSystem->Update();
        SDL_RenderPresent(app->GetRenderer());
        // TODO: Eventually set a frame cap
    }
//    app->SetEventCallback(HandleEvents);
//    app->SetUpdateCallback(HandleUpdate);
//    app->SetRenderCallback(HandleRendering);
//    app->RunLoop();

    delete app;

    return 0;
}
