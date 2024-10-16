#ifndef FONT_CPP_
#define FONT_CPP_

#include "Font.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

Game::Entity::Font :: Font()
{
	
}

Game::Entity::Font :: Font(const char* p_path, int size, bool HAlign, bool VAlign)
{
	if (TTF_Init() < 0)
	{
		std::cout  << "Can't initialize SDL_ttf. Error: " << SDL_GetError() << '\n';
		font = nullptr;
	}
	font = TTF_OpenFont(p_path, size);
	if (font == nullptr)
	{
		std::cout << "Can't load text. Error: " << TTF_GetError() << '\n';
		font = nullptr;
	}
	horizontalAlignment = HAlign;
	verticalAlignment = VAlign;
}

Game::Entity::Font :: ~Font()
{
	if (font != nullptr)
	{
		TTF_CloseFont(font);
	}
	font = nullptr;
}

void Game::Entity::Font :: OpenFont(const char* p_path, int size, bool HAlign, bool VAlign)
{
	if (TTF_Init() < 0)
	{
		std::cout  << "Can't initialize SDL_ttf. Error: " << SDL_GetError() << '\n';
		font = nullptr;
	}
	font = TTF_OpenFont(p_path, size);
	if (font == nullptr)
	{
		std::cout << "Can't load text. Error: " << TTF_GetError() << '\n';
		font = nullptr;
	}
	horizontalAlignment = HAlign;
	verticalAlignment = VAlign;
}

void Game::Entity::Font :: Unload()
{
	if (font != nullptr)
	{
		TTF_CloseFont(font);
	}
	font = nullptr;
}

SDL_Texture* Game::Entity::Font :: CreateTextTexture(SDL_Renderer* renderer, const char* p_text, SDL_Color color)
{
	if (font == nullptr)
	{
		std::cout << "Font not loaded.\n";
		return nullptr; 
	}
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, p_text, color);
	if (textSurface == nullptr)
	{
		std::cout << "Failded to load Surface: " << SDL_GetError() << '\n';
		return nullptr; 
	}
	
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	if (texture == nullptr)
	{
		std::cout << "Failded to load Texture: " << SDL_GetError() << '\n';
		SDL_FreeSurface(textSurface);
		return nullptr; 
	}
	
	SDL_FreeSurface(textSurface);
	return texture;
}

TTF_Font* Game::Entity::Font :: GetFont() const 
{
    return font;
}

bool Game::Entity::Font :: GetHAlign() const
{
    return horizontalAlignment;
}

bool Game::Entity::Font :: GetVAlign() const
{
    return verticalAlignment;
}

#endif
