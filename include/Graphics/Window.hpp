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

class Window
{
public:
    Window(const char* p_title, const int p_w, const int p_h);
    Create(const char* p_title, const int p_w, const int p_h);
    
    Resize
private:
    SDL_Window* window;
}

#endif // WINDOW_HPP_
