#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <stdio.h>

#include "texture_loader.hpp"
#include "consts.h"

int main( int argc, char* args[] )
{
    // init
    SDL_Window* window = NULL;
    
    SDL_Surface* windowSurface = NULL;

    SDL_Renderer* renderer = NULL;
    
    SDL_Event e;
    
    LTexture bgTexture;
    Mix_Music *bgMusic = NULL;
    
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
            }
        }
    }
   
    // load texture
    bgTexture.loadFromFile(renderer, "./SpaceShooter/Assets/bg.png");
    bgMusic = Mix_LoadMUS("./SpaceShooter/Assets/bgMusic.mp3");
    
    // game loop
    bool quit = false;
    
    bgTexture.setAlpha(50);
    
    while(!quit) {
        
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                quit = true;
            }
        }
        if( Mix_PlayingMusic() == 0 )
        {
            //Play the music
            Mix_PlayMusic( bgMusic, -1 );
        }
        
        SDL_RenderClear(renderer);
        
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        
        bgTexture.render(renderer);
        
        SDL_RenderPresent(renderer);
    }

    // free operations
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    window = NULL;
    renderer = NULL;
    
    IMG_Quit();
    SDL_Quit();

    return 0;
}

