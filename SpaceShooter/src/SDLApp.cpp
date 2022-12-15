//
//  SDLApp.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//

#include "SDLApp.hpp"

SDLApp::SDLApp(const char* title,int x, int y, int w, int h)
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        std::cout << "SDL could not be initialized: " << SDL_GetError();
    }
    else{
        std::cout << "SDL video system is ready to go\n";
    }
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    if( TTF_Init() == -1 )
    {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    window = SDL_CreateWindow(title,x,y,w,h,SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDLApp::~SDLApp(){
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

SDL_Renderer* SDLApp::GetRenderer() const{
    return renderer;
}

void SDLApp::EcsInit()
{
    gCoordinator = std::make_shared<Coordinator>();
    gCoordinator->Init();
}

void SDLApp::EcsRegiesterComponents()
{
    gCoordinator->RegisterComponent<TransformComponent>();
    gCoordinator->RegisterComponent<TextureComponent>();
    gCoordinator->RegisterComponent<MovementComponent>();
    gCoordinator->RegisterComponent<UITextComponent>();
    gCoordinator->RegisterComponent<TimerComponnet>();
    gCoordinator->RegisterComponent<InputComponent>();
    gCoordinator->RegisterComponent<BulletComponent>();
}

void SDLApp::EcsRegisterSystems()
{
    movementSystem = gCoordinator->RegisterSystem<MovementSystem>();
    {
        Signature signature;
        signature.set(gCoordinator->GetComponentType<TransformComponent>());
        signature.set(gCoordinator->GetComponentType<MovementComponent>());
        gCoordinator->SetSystemSignature<MovementSystem>(signature);
    }
    
    renderSystem = gCoordinator->RegisterSystem<RenderSystem>();
    {
        Signature signature;
        signature.set(gCoordinator->GetComponentType<TextureComponent>());
        signature.set(gCoordinator->GetComponentType<TransformComponent>());
        gCoordinator->SetSystemSignature<RenderSystem>(signature);
    }
    
    timeSystem = gCoordinator->RegisterSystem<TimeSystem>();
    {
        Signature signature;
        signature.set(gCoordinator->GetComponentType<TimerComponnet>());
        gCoordinator->SetSystemSignature<TimeSystem>(signature);
    }
    
    inputSystem = gCoordinator->RegisterSystem<InputSystem>();
    {
        Signature signature;
        signature.set(gCoordinator->GetComponentType<InputComponent>());
        gCoordinator->SetSystemSignature<InputSystem>(signature);
    }
    
    bulletSystem = gCoordinator->RegisterSystem<BulletSystem>();
    {
        Signature signature;
        signature.set(gCoordinator->GetComponentType<BulletComponent>());
        gCoordinator->SetSystemSignature<BulletSystem>(signature);
    }
}

void SDLApp::EcsCreateInitialEntities()
{
    // Init entity and attach components
    Entity testEntity = gCoordinator->CreateEntity();
    Entity bgEntity = gCoordinator->CreateEntity();
    Entity player = gCoordinator->CreateEntity();
    Entity timer = gCoordinator->CreateEntity();
    
    gCoordinator->SetTag(player, "Player");
    gCoordinator->SetTag(timer, "UI");
    
    gCoordinator->AddComponent(testEntity, TransformComponent{});
    gCoordinator->AddComponent(timer, TransformComponent{
        .x = 5*SCREEN_WIDTH/10,
        .y = 0,
        .z = 0,
    });
    gCoordinator->AddComponent(timer, TextureComponent{});
    gCoordinator->AddComponent(timer, TimerComponnet{});
    
    gCoordinator->AddComponent(bgEntity, TransformComponent{
        .x = 0.f,
        .y = 0.f,
        .z = 0.f,
    });
    gCoordinator->AddComponent(bgEntity, TextureComponent{});
    gCoordinator->AddComponent(player, TransformComponent{
        .x = 0.f,
        .y = 0.f,
        .z = 0.f,
    });
    gCoordinator->AddComponent(player, TextureComponent{});
    gCoordinator->AddComponent(player, MovementComponent{
        .velX = 0.f,
        .velY = 0.f,
        .velValue = 100.f,
        .accer = 0.f,
    });
    gCoordinator->AddComponent(player, InputComponent{});
    
    // TODO: *** should be very event based, add/remove entity for system when there is a change of components in entities
    gCoordinator->SetEntitiesForSystem<RenderSystem>();
    gCoordinator->SetEntitiesForSystem<MovementSystem>();
    gCoordinator->SetEntitiesForSystem<TimeSystem>();
    gCoordinator->SetEntitiesForSystem<InputSystem>();
    gCoordinator->SetEntitiesForSystem<BulletSystem>();
    
    // Init Systems
    movementSystem->Init();
    
    renderSystem->LoadTexture(gCoordinator, bgEntity, GetRenderer(), "./SpaceShooter/Assets/hoton.jpg");
    renderSystem->SetRenderRange(gCoordinator, bgEntity, SCREEN_WIDTH, SCREEN_HEIGHT);
    renderSystem->LoadTexture(gCoordinator, player, GetRenderer(), "./SpaceShooter/Assets/dot.bmp");
    renderSystem->SetRenderRange(gCoordinator, player, 20, 20);
    renderSystem->LoadFromRenderedText(gCoordinator, GetRenderer(), "./SpaceShooter/Assets/pixel.TTF", "here to show time", {100, 100, 100, 255});
    renderSystem->SetRenderRange(gCoordinator, timer, 5 * SCREEN_WIDTH/10, 100);
    
    timeSystem->SetStartTime(gCoordinator);
    timeSystem->StartFps();
    
    gMusic = Mix_LoadMUS("./SpaceShooter/Assets/bgMusic.mp3");
}

void SDLApp::Init()
{
    EcsInit();
    EcsRegiesterComponents();
    EcsRegisterSystems();
    EcsCreateInitialEntities();
}

void SDLApp::Run(){
    while(mGameIsRunning){

        while(SDL_PollEvent(&event)){
            
            if(event.type == SDL_QUIT){
                Stop();
                mGameIsRunning = false;
            }
            // deprecated input method
            timeSystem->HandleInput(event);
        }
        
        if( Mix_PlayingMusic() == 0 )
        {
            Mix_PlayMusic( gMusic, -1 );
        }
       
        float currentTick = SDL_GetTicks();
        float deltaTime = (currentTick - mLastFrameTicks)/1000;
        mLastFrameTicks = currentTick;
        
        // testing UI
        SDL_RenderClear(GetRenderer());
        SDL_SetRenderDrawColor(GetRenderer(),255,255,255,SDL_ALPHA_OPAQUE);
        renderSystem->LoadFromRenderedText(gCoordinator, GetRenderer(), "./SpaceShooter/Assets/pixel.TTF", "here to show time", {100, 100, 100, 255});
        
        timeSystem->ShowFps();
        timeSystem->ShowCurrentTime(gCoordinator);
        
        inputSystem->HandleMovementInput(gCoordinator);
        inputSystem->HandleShootingInput(gCoordinator, renderSystem, GetRenderer(), 100, 100, Up, bulletSystem);
        
        movementSystem->Update(gCoordinator, deltaTime);
        
        renderSystem->Render(gCoordinator, GetRenderer());
        SDL_RenderPresent(GetRenderer());
    }
}

void SDLApp::Stop(){
    mGameIsRunning = false;
}
