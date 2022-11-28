//
//  TransformComponent.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//

#ifndef TransformComponent_hpp
#define TransformComponent_hpp

#include <SDL2/SDL.h>
#include <stdio.h>

class TransformComponent
{
public:
    
    TransformComponent();
    
    ~TransformComponent();
    
    void SetPosX(int posX);
    void SetPosY(int posY);
    
    int GetPosX();
    int GetPosY();
    
private:
    
    // TODO: make a pos struct
    int mPosX;
    int mPosY;
    
};
#endif /* TransformComponent_hpp */
