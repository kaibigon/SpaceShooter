//
//  TimeSystem.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/5.
//

#ifndef TimeSystem_hpp
#define TimeSystem_hpp

#include <stdio.h>
#include "../ECS/System.h"
#include "../Components/Components.h"

class TimeSystem : public System
{
public:
    void showCurrentTime();
    void getCurrentTime();
    void showEclapsedTime();
    void setStartTime();
private:
    Uint32 mStartTime;
};

#endif /* TimeSystem_hpp */
