#ifndef TEXTURE_HPP_
#define TEXTURE_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "Math/Vector2D.hpp"

namespace Game
{
    
namespace Entity
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
	
	int GetWidth() const;
	int GetHeight() const;
	SDL_Texture* GetSDLtexture() const;
	
	void Render(SDL_Renderer* renderer, Math::Vector2D<int> pos, double scale = 1, double angle = 0.00f, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
private:
	SDL_Texture* texture;
	int width, height;
};

}

}

#endif
