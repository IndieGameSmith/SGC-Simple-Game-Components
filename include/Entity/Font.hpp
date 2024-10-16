#ifndef FONT_HPP_
#define FONT_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

namespace Game
{
    
namespace Entity
{

class Font
{
  public:
    Font();
    Font(const char *p_path, int size, bool HAlign, bool VAlign);
    ~Font();

    void OpenFont(const char *p_path, int size, bool HAlign, bool VAlign);
    void Unload();

    TTF_Font *GetFont() const;

    SDL_Texture *CreateTextTexture(SDL_Renderer *renderer, const char *text, SDL_Color color);
    bool GetHAlign() const;
    bool GetVAlign() const;
    
  private:
    TTF_Font *font;
    bool horizontalAlignment, verticalAlignment;
};

} // namespace Game

}

#endif
