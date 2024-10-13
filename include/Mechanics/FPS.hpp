/** 
 *  \file FPS.hpp
 *  
 *  \brief Header for Various FPS.
 *
 *  \author IndieGameSmith
 *  \date 2024-08-23
 */


#ifndef MECHANICS_FPS_HPP_
#define MECHANICS_FPS_HPP_

#include "SDL2/SDL.h"

namespace Game
{

namespace Mechanics
{
    
class FPS
{
public:
    FPS(int p_fps = 30);
    void Init();
    void Stablize();
    void Cap();
    bool UpdateTick();
    int GetFPS() const;
private:
    static const int MAX_FRAME_HISTORY = 10;
    float accumulator;
    float frameTimes[MAX_FRAME_HISTORY];
    int currentFrameIndex;
    int fps;
    Uint64 previousTime;
    Uint64 currentTime;
    float deltaTime;
    float elapsedTime;
    float averageFrameTime;
    int currentFps;
    float alpha;
    float sleepTime;
    
};
    
    
} // Mechanics

} // Game

#endif
