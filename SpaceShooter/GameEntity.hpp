//
//  gameEntity.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//

#ifndef GameEntity_hpp
#define GameEntity_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "TextureLoader.hpp"

class GameEntity
{
public:
    
    GameEntity(){
        mTexture = nullptr;
    }
    
    GameEntity(SDL_Renderer *renderer)
    {
        mPosX = 0;
        mPosY = 0;
        mRenderer = renderer;
        mTexture = new LTexture();
    }
    
    ~GameEntity();
    
    void update()
    {
        
    }
    
    void render()
    {
        if ( mTexture != nullptr)
        {
            mTexture->render(mRenderer, mPosX, mPosY, mTexture->getWidth(), mTexture->getHeight());
        }
    }
    
    LTexture& getTexture()
    {
        return *mTexture;
    }
    
    SDL_Renderer* getRenderer()
    {
        return mRenderer;
    }
    
    void setPosX(int posX);
    void setPosY(int posY);
    
    int getPosX();
    int getPosY();
    
private:
    
    LTexture* mTexture;
    SDL_Renderer* mRenderer;
    int mPosX;
    int mPosY;
};
#endif /* gameEntity_hpp */
