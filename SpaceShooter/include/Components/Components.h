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
    float x;
    float y;
    float z;
};

struct MovementComponent
{
    float velX = 0;
    float velY = 0;
    float velValue = 0;
    float accer = 0;
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

struct BulletComponent
{
    int id;
};

struct InputComponent
{
    bool w;
    bool a;
    bool s;
    bool d;
    bool up;
    bool down;
    bool left;
    bool right;
};
#endif /* Components_h */
