//
//  Components.h
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/5.
//

#ifndef Components_h
#define Components_h

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <sstream>
struct TransformComponent
{
    int x;
    int y;
    int z;
};

struct MovementComponent
{
    int velX = 0;
    int velY = 0;
    int velValue = 5;
    int accer = 0;
};

struct TextureComponent
{
    SDL_Texture *texture;
    SDL_Renderer *renderer;
    TTF_Font *font;
    std::string text;
    int x;
    int y;
    int width;
    int height;
    SDL_Rect dst;
};

struct TimerComponnet
{
    Uint32 startTime;
};

struct UITextComponent
{
    TTF_Font *font;
    std::string text;
    int x;
    int y;
    int width;
    int height;
};
#endif /* Components_h */
