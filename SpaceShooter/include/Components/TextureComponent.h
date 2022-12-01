//
//  TextureComponent.h
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/1.
//

#ifndef TextureComponent_h
#define TextureComponent_h
#include <SDL2/SDL.h>"

struct TextureComponent
{
    SDL_Texture *texture;
    SDL_Renderer *renderer;
    int x;
    int y;
    int width;
    int height;
    SDL_Rect dst;
};
#endif /* TextureComponent_h */
