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
#include "../ECS/Coordinator.h"

// Just a testing system
class TimeSystem : public System
{
public:
    void ShowCurrentTime(std::shared_ptr<Coordinator>& gCoordinator);
    void GetCurrentTime();
    void ShowEclapsedTime();
    void SetStartTime(std::shared_ptr<Coordinator>& gCoordinator);
    void StartTime();
    void StopTime();
    void PauseTime();
    void ResumeTime();
    Uint32 GetTicks();
    void CalFps();
    void StartFps();
    void ShowFps();
    Uint32 GetFpsTicks();
    void SetFpsTicks(Uint32 ticks);
    void HandleInput(SDL_Event &e);
private:
    Uint32 mStartTime;
    Uint32 mPauseTime;
    Uint32 mFpsStartTicks;
    Uint32 mFpsTicks;
    Uint32 mFps;
    bool mPaused;
    bool mStarted;
    int mFrames;
};

#endif /* TimeSystem_hpp */
