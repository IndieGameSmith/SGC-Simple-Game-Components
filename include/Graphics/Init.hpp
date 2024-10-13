/** 
 *  \file Init.hpp
 *  
 *  \brief Header file that Init related class.
 *
 *  \author IndieGameSmith
 *  \date 2024-10-08
 */
 
#ifndef GRAPHICS_INIT_HPP_
#define GRAPHICS_INIT_HPP_

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

namespace Game
{
    
namespace Graphics
{
    
bool Init()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    // Initialize SDL_image
    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
        std::cerr << "Error initializing SDL_image: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        std::cerr << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return false;
    }

    return true;
}

void Quit()
{
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}

} // Graphics

} // Game

#endif // GRAPHICS_INIT.HPP_
