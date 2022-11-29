//
//  testComponent.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/29.
//

#ifndef TransformComponentt_hpp
#define TransformComponentt_hpp

#include <stdio.h>
#include "Component.hpp"

class TransformComponent : public Component
{
public:
    
    TransformComponent() { };
    
    TransformComponent(int x, int y)
    {
        posx = x;
        posy = y;
        printf("x: %d, y: %d\n", posx, posy);
    }
    
    virtual ~TransformComponent() {};
    int x() {return posx;}
    int y() {return posy;}
    
    void Init() override
    {
        posx = 0;
        posy = 0;
    }
    
    void Update() override
    {
    }
    
private:
    int posx;
    int posy;
};
#endif /* testComponent_hpp */
