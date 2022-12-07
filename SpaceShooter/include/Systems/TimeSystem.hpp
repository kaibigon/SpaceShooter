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

// TODO: show time, pause time, resume time, and show fps
class TimeSystem : public System
{
public:
    void ShowCurrentTime();
    void GetCurrentTime();
    void ShowEclapsedTime();
    void SetStartTime();
    void StartTime();
    void StopTime();
    void PauseTime();
    void ResumeTime();
    Uint32 GetTicks();
    void HandleInput(SDL_Event &e);
private:
    Uint32 mStartTime;
    Uint32 mPauseTime;
    bool mPaused;
    bool mStarted;
    
};

#endif /* TimeSystem_hpp */
