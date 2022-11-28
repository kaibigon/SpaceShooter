//#include <SDL2/SDL.h>
//#include <SDL2_image/SDL_image.h>
//#include <SDL2_mixer/SDL_mixer.h>
//#include <SDL2_ttf/SDL_ttf.h>
//#include <stdio.h>
//
//#include "textureLoader.hpp"
//#include "timer.hpp"
//#include "consts.h"
//#include "player.hpp"
//
//void updatePlayer(Player *player, SDL_Renderer *renderer)
//{
//    player->move();
//    player->render(renderer);
//}
//
//void updateTimer(KTimer *timer, KTimer *fpsTimer, TTF_Font *font, SDL_Renderer *renderer, SDL_Color tColor)
//{
//    timer->updateTimeText();
//
//    fpsTimer->updateFpsText();
//    fpsTimer->updateFrames();
//
//    timer->render(font, renderer, tColor, 8.9 * SCREEN_WIDTH / 10, 0,
//                    1 * SCREEN_WIDTH / 10, 1 * SCREEN_HEIGHT / 20);
//    fpsTimer->render(font, renderer, tColor, 8.9 * SCREEN_WIDTH / 10, 1 * SCREEN_HEIGHT / 20,
//                     1 * SCREEN_WIDTH / 10, 1 * SCREEN_HEIGHT / 20);
//}
//
//void updateMusic(Mix_Music *music)
//{
//    if( Mix_PlayingMusic() == 0 )
//    {
//        Mix_PlayMusic( music, -1 );
//    }
//}
//
//
//// TODO: might be a more optimized way to display ui (timer
//int main( int argc, char* args[] )
//{
//    // init SDL
//    SDL_Window* window = NULL;
//    SDL_Surface* windowSurface = NULL;
//    SDL_Renderer* renderer = NULL;
//    SDL_Event e;
//
//    SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO);
//    window = SDL_CreateWindow( "Space Shooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
//    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//    windowSurface = SDL_GetWindowSurface(window);
//    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0xFF);
//
//    // TODO make it into init function???
//    // init assets
//    LTexture bgTexture;
//    Mix_Music *bgMusic = NULL;
//    TTF_Font* gFont = NULL;
//
//    KTimer timer;
//    std::stringstream timerText;
//
//    KTimer fpsTimer;
//    std::stringstream fpsTimerText;
//
//    // init dependencies
//    int image_flag = IMG_INIT_PNG;
//    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
//    TTF_Init();
//
//    // init player
//    Player player;
//    player.getTexture()->loadFromFile(renderer, "./SpaceShooter/Assets/dot.bmp");
//
//    // load assets
//    bgTexture.loadFromFile(renderer, "./SpaceShooter/Assets/bg.png");
//    bgTexture.setAlpha(50);
//
//    bgMusic = Mix_LoadMUS("./SpaceShooter/Assets/bgMusic.mp3");
//
//    SDL_Color tColor = {0, 0, 0};
//    gFont = TTF_OpenFont( "./SpaceShooter/Assets/lazy.ttf", 20 );
//
//    // game loop and timer
//    bool quit = false;
//    timer.start();
//    fpsTimer.start();
//
//    while(!quit)
//    {
//        while(SDL_PollEvent(&e) != 0)
//        {
//            if(e.type == SDL_QUIT)
//            {
//                quit = true;
//            }
//            timer.handleEvent(e);
//            player.handleEvent(e);
//        }
//
//        // render
//        SDL_RenderClear(renderer);
//        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
//        bgTexture.render(renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
//
//        // update timer
//        updateTimer(&timer, &fpsTimer, gFont, renderer, tColor);
//
//        // update music
//        updateMusic(bgMusic);
//
//        // update player
//        updatePlayer(&player, renderer);
//
//        SDL_RenderPresent(renderer);
//    }
//
//    // free operations
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    bgTexture.free();
//
//    TTF_CloseFont(gFont);
//    gFont = NULL;
//    bgMusic = NULL;
//
//    window = NULL;
//    renderer = NULL;
//
//    AssetManager::GetInstance().Free();
//    TTF_Quit();
//    IMG_Quit();
//    SDL_Quit();
//
//    return 0;
//}
//
