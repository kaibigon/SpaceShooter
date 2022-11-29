//
//  SDLApp.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//

#include "SDLApp.hpp"

SDLApp::SDLApp(const char* title,int x, int y, int w, int h)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not be initialized: " << SDL_GetError();
    }
    else{
        std::cout << "SDL video system is ready to go\n";
    }
    window = SDL_CreateWindow(title,x,y,w,h,SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDLApp::~SDLApp(){
    // Destroy our m_window
    SDL_DestroyWindow(window);
    // Quit our SDL application
    IMG_Quit();
    SDL_Quit();
}

// Handle Events
void SDLApp::SetEventCallback(std::function<void(void)> func){
    mEventCallback = func;
}

// Handle Render
void SDLApp::SetRenderCallback(std::function<void(void)> func){
    mRenderCallback = func;
    
}

void SDLApp::SetUpdateCallback(std::function<void(void)> func){
    mUpdateCallback = func;
}

void SDLApp::RunLoop(){
    while(mGameIsRunning){
        Uint32 buttons;
        buttons = SDL_GetMouseState(&mMouseX,&mMouseY);
        
        mEventCallback();

        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
        
        mUpdateCallback();
        
        mRenderCallback();
        
        SDL_RenderPresent(renderer);
        // TODO: Eventually set a frame cap
//        SDL_Delay(100);
    }
}

SDL_Renderer* SDLApp::GetRenderer() const{
    return renderer;
}

int SDLApp::GetMouseX(){
    return mMouseX;
}
int SDLApp::GetMouseY(){
    return mMouseY;
}

void SDLApp::StopAppLoop(){
    mGameIsRunning = false;
}
