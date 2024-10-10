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
#include "Math/Math.hpp"

namespace Game
{
namespace Graphics
{

using DisplayMode = SDL_DisplayMode;
using WindowHandle = SDL_Window*;

enum class WindowFlags : uint32_t
{
    None = 0,
    Fullscreen = SDL_WINDOW_FULLSCREEN,
    FullscreenDesktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
    OpenGL = SDL_WINDOW_OPENGL,   

    VSync = SDL_WINDOW_VSYNC,
    Resizable = SDL_WINDOW_RESIZABLE,
    Minimized = SDL_WINDOW_MINIMIZED,
    Maximized = SDL_WINDOW_MAXIMIZED,
    InputGrabbed = SDL_WINDOW_INPUT_GRABBED,   

    Borderless = SDL_WINDOW_BORDERLESS,
    Hidden = SDL_WINDOW_HIDDEN,
    Overlapped = SDL_WINDOW_OVERLAPPED,
    AllowHighDPI = SDL_WINDOW_ALLOW_HIGHDPI,
    FullscreenMaximized = SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_MAXIMIZED
};

enum class MessageType
{
    ERROR,
    WARNING,
    INFORMATION
};

class Window
{
public:
    // Constructor
    Window();
    Window(const char* p_title, int p_w, int p_h);
    // Destructor
    ~Window();
    
    // Display mode creation and configuration
    SDL_DisplayMode CreateDisplayMode(int w, int h, int RefreshRate, Uint32 Format);
    void SetDisplayMode(SDL_DisplayMode Mode);
    void Create(const char* p_title, int p_w, int p_h);
    
    // Window resizing and positioning
    void ResizeWindow(int w, int h);
    void MoveWindowTo(int x, int y);
    void CenterWindow();
    void Restore();
    
    // Window properties
    void SetWindowTitle(const char* p_title);
    void SetWindowIcon(SDL_Surface* icon);
    void SetWindowResizable(bool resizable);
    void SetWindowOpacity(float opacity);
    void SetWindowModal(bool modal);
    void ToggleWindowVisiblity();
    void ToggleFullscreen();
    void ToggleBorder();
    void ToggleMaximize();
    void ToggleMinimize();
    void RaiseWindow();
    void ShowMessageBox(const char* p_title, const char* message, MessageType messageType);
    void Update();

    // Window information
    SDL_Window* GetWindow() const;
    Uint32 GetWindowFlags() const;
    Math::Point2D<int> GetWindowCenter() const;
    Math::Pair<int, int> GetWindowSize() const;
    SDL_DisplayMode GetCurrentDisplayMode() const;
    SDL_DisplayMode GetDisplayMode(int DisplayIndex, int ModeIndex) const;
    SDL_DisplayMode GetWindowDisplayMode() const;
    Uint32 GetWindowFormat() const;
    int GetWindowDisplayIndex() const;
    int GetRefreshRate() const;
    bool IsWindowOpen() const;
    bool HasError() const;
    const char* GetLastError() const;
    
    // Window Destruction
    void Destroy();
    
private:
    SDL_Window* window;
    Math::Point2D<int> windowPos;
    SDL_DisplayMode displayMode;
    bool isWindowModal;
};

} // namepace Graphics

} // namespace Game

#endif // WINDOW_HPP_
