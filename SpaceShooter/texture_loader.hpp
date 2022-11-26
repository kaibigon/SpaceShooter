//
//  texture_loader.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/26.
//

#ifndef texture_loader_hpp
#define texture_loader_hpp

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#endif /* texture_loader_hpp */

class LTexture {
    
public:
    
    LTexture();
    
    ~LTexture();
    
    void loadFromFile(SDL_Renderer *renderer, std::string path);
    
    void free();
    
    SDL_Texture* getTexture();
    
    int getWidth();
    
    int getHeight();
    
private:
    SDL_Texture *texture;
    
    int width;
    int height;
};
