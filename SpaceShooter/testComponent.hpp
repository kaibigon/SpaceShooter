//
//  testComponent.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/29.
//

#ifndef testComponent_hpp
#define testComponent_hpp

#include <stdio.h>
#include "Component.hpp"

class testComponent : public Component
{
public:
    
    testComponent() { };
    
    testComponent(int x, int y)
    {
        posx = x;
        posy = y;
        printf("nmsl");
    }
    
    virtual ~testComponent() {};
    int x() {return posx;}
    int y() {return posy;}
    
    void init() override
    {
        posx = 0;
        posy = 0;
    }
    
    void update() override
    {
        printf("nmsl");
    }
    
private:
    int posx;
    int posy;
};
#endif /* testComponent_hpp */
