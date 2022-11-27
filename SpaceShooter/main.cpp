#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <stdio.h>

#include "texture_loader.hpp"
#include "timer.hpp"
#include "consts.h"
#include "player.hpp"

int main( int argc, char* args[] )
{
    // init
    SDL_Window* window = NULL;
    
    SDL_Surface* windowSurface = NULL;

    SDL_Renderer* renderer = NULL;
    
    SDL_Event e;
    
    LTexture bgTexture;
    LTexture tTexture;
    LTexture playerTexture;
    Mix_Music *bgMusic = NULL;
    TTF_Font* gFont = NULL;

    KTimer timer;
    std::stringstream timerText;
    
    KTimer fpsTimer;
    std::stringstream fpsTimerText;
    
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        window = SDL_CreateWindow( "Space Shooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            windowSurface = SDL_GetWindowSurface(window);
           
            if(renderer == NULL) {
                printf("Renderer could not be initialized! SDL_Error: %s\n", SDL_GetError());
            }else{
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0xFF);
                
                int image_flag = IMG_INIT_PNG;
               
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                }
                
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                }
            }
        }
    }
   
    // load texture
    bgTexture.loadFromFile(renderer, "./SpaceShooter/Assets/bg.png");
    playerTexture.loadFromFile(renderer, "./SpaceShooter/Assets/dot.bmp");
    bgMusic = Mix_LoadMUS("./SpaceShooter/Assets/bgMusic.mp3");
    gFont = TTF_OpenFont( "./SpaceShooter/Assets/lazy.ttf", 20 );
    SDL_Color tColor = {0, 0, 0};
    
    // game loop
    bool quit = false;
    bgTexture.setAlpha(50);
    int frames = 0;
    fpsTimer.start();
    
    // init player
    Player player;
    player.setTexture(playerTexture);
    
    while(!quit)
    {
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN)
            {
                if(e.key.keysym.sym == SDLK_s)
                {
                    if( timer.isStarted())
                    {
                        timer.stop();
                    }
                    else
                    {
                        timer.start();
                    }
                }
                else if (e.key.keysym.sym == SDLK_p)
                {
                    if(timer.isPaused())
                    {
                        timer.resume();
                    }
                    else
                    {
                        timer.pause();
                    }
                }
            }
            player.handleEvent(e);
        }
        
        // play music
        if( Mix_PlayingMusic() == 0 )
        {
            Mix_PlayMusic( bgMusic, -1 );
        }
        
        SDL_RenderClear(renderer);
        
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        
        timerText.str("");
        timerText << "Time: " << round(timer.getTicks() / 1000.f);

        fpsTimerText.str("");
        fpsTimerText << "FPS: " << round(frames / (fpsTimer.getTicks() / 1000.f));
        
        std::string outputTimer = timerText.str() + "*******" + fpsTimerText.str();
        
        tTexture.loadFromRendereredText(gFont, renderer, outputTimer.c_str(), tColor);
        
        tTexture.render(renderer, 0, 100, 1000, 200);
        
        bgTexture.render(renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        
        player.move();
        
        player.render(renderer);
        
        SDL_RenderPresent(renderer);
        
        frames++;
    }

    // free operations
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    tTexture.free();
    
    TTF_CloseFont(gFont);
    gFont = NULL;
    window = NULL;
    renderer = NULL;
    
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    return 0;
}

