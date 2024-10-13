#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "Vector2D.hpp"

namespace Game
{
    
namespace Graphics
{
    
class Texture
{
public:
	Texture();
	Texture(SDL_Renderer* p_renderer, const char* p_path);
	Texture(SDL_Texture* p_tex);
	~Texture();
	
	void LoadFromFile(SDL_Renderer* p_renderer, const char* p_path);
	void LoadTexture(SDL_Texture* p_tex);
	void Unload();
	
	SDL_Texture* LoadTextureFromFile(SDL_Renderer* p_renderer, const char* p_path);
	
	int GetWidth();
	int GetHeight();
	SDL_Texture* GetSDLtexture();
	
private:
	SDL_Texture* texture;
	int width, height;
};

}

}

#endif
