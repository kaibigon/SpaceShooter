#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
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
    
    LTexture testLoadTexture;
    
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
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
            }
        }
    }
   
    // load texture
    testLoadTexture.loadFromFile(renderer, "./SpaceShooter/Assets/bg.png");
    
    // game loop
    bool quit = false;
    
    testLoadTexture.setAlpha(50);
    
    while(!quit) {
        
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                quit = true;
            }
        }
        
        SDL_RenderClear(renderer);
        
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        
        testLoadTexture.render(renderer);
        
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

