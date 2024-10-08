/** 
 *  \file Window.hpp
 *  
 *  \brief Header file that Window related class.
 *
 *  \author IndieGameSmith
 *  \date 2024-10-08
 */
 
#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "SDL2/SDL.h"
#include "Math.hpp"

namespace Game
{
namespace Graphics
{

class Window
{
public:
    Window(const char* p_title, int p_w, int p_h)a;
    void Create(const char* p_title, int p_w, int p_h);
    void ResizeWindow(int w, int h);
    void MoveWindowTo(int x, int y);
    void CenterWindow();
    void ToggleWindowVisiblitt();
    void ToggleFullscreen();
    void ToggleBorder();
    void Destroy();
    
    Math::Pair GetWindowCenter();
private:
    SDL_Window* window;
    Math::Point2D windowPos;
};

} // namepace Graphics

} // namespace Game

#endif // WINDOW_HPP_
