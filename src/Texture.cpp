#ifndef TEXTURE_CPP_
#define TEXTURE_CPP_

#include "Texture.hpp"
#include "Vector2D.cpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

Game::Graphics::Texture :: Texture(){}

Game::Graphics::Texture :: Texture(SDL_Renderer* p_renderer, const char* p_path)
{
	SDL_Surface* textureSurface = IMG_Load(p_path);
	if (textureSurface == nullptr)
	{
		std::cout << "Failded to load surface: " << SDL_GetError() << '\n';
		texture = nullptr;
	}
	
	texture = SDL_CreateTextureFromSurface(p_renderer, textureSurface);
	if (texture == nullptr)
	{
		std::cout << "Failded to load surface: " << SDL_GetError() << '\n';
		SDL_FreeSurface(textureSurface);
		texture = nullptr;
	}
	
	if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) != 0)
	{
        std::cerr << "Failed to query texture dimensions: " << SDL_GetError() << std::endl;
        texture = nullptr;
        return;
    }
}

Game::Graphics::Texture :: Texture(SDL_Texture* p_tex)
{
	texture = p_tex;
	if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) != 0)
	{
        std::cerr << "Failed to query texture dimensions: " << SDL_GetError() << std::endl;
        return;
    }
}

Game::Graphics::Texture :: ~Texture()
{
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
	}
	texture = nullptr;
}

void Game::Graphics::Texture :: LoadFromFile(SDL_Renderer* p_renderer, const char* p_path)
{
	SDL_Surface* textureSurface = IMG_Load(p_path);
	if (textureSurface == nullptr)
	{
		std::cout << "Failded to load surface: " << SDL_GetError() << '\n';
		texture = nullptr;
	}
	
	texture = SDL_CreateTextureFromSurface(p_renderer, textureSurface);
	if (texture == nullptr)
	{
		std::cout << "Failded to load surface: " << SDL_GetError() << '\n';
		SDL_FreeSurface(textureSurface);
		texture = nullptr;
	}
	
	if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) != 0)
	{
        std::cerr << "Failed to query texture dimensions: " << SDL_GetError() << std::endl;
        texture = nullptr;
        return;
    }
}

void Game::Graphics::Texture :: LoadTexture(SDL_Texture* p_tex)
{
	texture = p_tex;
	if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) != 0)
	{
        std::cerr << "Failed to query texture dimensions: " << SDL_GetError() << std::endl;
        return;
    }
}

void Game::Graphics::Texture :: Unload()
{
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
	}
	texture = nullptr;
}

SDL_Texture* Game::Graphics::Texture :: LoadTextureFromFile(SDL_Renderer* p_renderer, const char* p_path)
{
	SDL_Surface* textureSurface = IMG_Load(p_path);
	if (textureSurface == nullptr)
	{
		std::cout << "Failded to load surface: " << SDL_GetError() << '\n';
		texture = nullptr;
	}
	
	SDL_Texture* tex = SDL_CreateTextureFromSurface(p_renderer, textureSurface);
	if (tex == nullptr)
	{
		std::cout << "Failded to load surface: " << SDL_GetError() << '\n';
		SDL_FreeSurface(textureSurface);
		texture = nullptr;
	}
	
	return tex;
}

int Game::Graphics::Texture :: GetWidth()
{
	return width;
}

int Game::Graphics::Texture :: GetHeight()
{
	return height;
}

SDL_Texture* Game::Graphics::Texture :: GetSDLtexture()
{
	return texture;
}

#endif
