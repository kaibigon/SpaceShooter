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

#include "TextureComponent.hpp"
#include "MovementComponent.hpp"
#include "KTimer.hpp"
#include "consts.h"
//#include "Player.hpp"
#include "SDLApp.hpp"
#include "GameEntity.hpp"
#include "TransformComponent.hpp"
#include "EntityManager.hpp"

SDLApp* app;

EntityManager entityManager;

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
    entityManager.Update();
}

void HandleRendering()
{
    entityManager.Render();
//    playerEntity->GetMovementComponent().Update(&playerEntity->GetTransformComponent());
//    bgEntity->Render();
//    playerEntity->Render();
}

int main( int argc, char* args[] )
{
    const char* title = "Boden Hao Leng";
    app = new SDLApp(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT);

    // testing
//    bgEntity = new GameEntity(app->GetRenderer());
//    bgEntity->AddTransformComponent();
//    bgEntity->AddTextureComponent("./SpaceShooter/Assets/bg.png");
//    bgEntity->GetTextureComponent().SetAlpha(50);
//    bgEntity->GetTextureComponent().SetWidth(SCREEN_WIDTH);
//    bgEntity->GetTextureComponent().SetHeight(SCREEN_HEIGHT);
//
//    playerEntity = new GameEntity(app->GetRenderer());
//    playerEntity->AddTransformComponent();
//    playerEntity->GetTransformComponent().SetPosX(SCREEN_WIDTH/2);
//    playerEntity->GetTransformComponent().SetPosY(SCREEN_HEIGHT/2);
//    playerEntity->AddTextureComponent();
//    playerEntity->AddTextureComponent("./SpaceShooter/Assets/dot.bmp");
//    playerEntity->GetTextureComponent().SetWidth(20);
//    playerEntity->GetTextureComponent().SetHeight(20);
//    playerEntity->AddMovementComponent();
//    playerEntity->AddComponent<testComponent>(100,100);
    
    auto& bgEntity = entityManager.AddEntity();
    bgEntity.AddComponent<TextureComponent>();
    bgEntity.GetComponent<TextureComponent>().LoadFromFile(app->GetRenderer(), "./SpaceShooter/Assets/bg.png");
    bgEntity.GetComponent<TextureComponent>().SetAlpha(50);
    bgEntity.GetComponent<TextureComponent>().SetRenderConfig(app->GetRenderer(), 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    auto& testEntity = entityManager.AddEntity();
    testEntity.AddComponent<TransformComponent>(20, 20);
    testEntity.AddComponent<TextureComponent>();
    if(testEntity.HasComponent<TransformComponent>())
    {
        printf("nmysl\n");
    }
    if(!testEntity.HasComponent<TextureComponent>())
    {
        printf("nmxc\n");
    }
   
//    std::vector<std::unique_ptr<Component>>* numOfC =  &testEntity.GetComponents();
//    printf("num of components: %lu\n", numOfC->size());
//    ComponentArray* test2 = &testEntity.GetComponentArray();
//    printf("max size is: %lu\n", (test2)->size());
    
    app->SetEventCallback(HandleEvents);
    app->SetUpdateCallback(HandleUpdate);
    app->SetRenderCallback(HandleRendering);
    app->RunLoop();

    entityManager.Refresh();
    delete app;

    return 0;
}
