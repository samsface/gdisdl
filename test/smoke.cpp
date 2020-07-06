#include <catch2/catch.hpp>

#include <windows.h>
#include <wingdi.h>

#include <SDL.h>
#include <stdio.h>

namespace gdisdl
{
    void SetDIBitsToDevice(HDC hdc, int xDest, int yDest, DWORD w, DWORD h, int xSrc,
        int ySrc, UINT StartScan, UINT cLines, void const* lpvBits, BITMAPINFO const* lpbmi, unsigned int ColorUse)
    {

    }
}

TEST_CASE("sdl_sandbox")
{
    SDL_Window* window{};
    SDL_Surface* screenSurface{};

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
        if (window == nullptr)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            screenSurface = SDL_GetWindowSurface(window);
            SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);
            SDL_Delay(2000);
        }   
    }


    ::SetDIBitsToDevice(
        nullptr,            // handle to device context
        0,           // x-coordinate of upper-left corner of 
        0,           // y-coordinate of upper-left corner of 
        16,       // source rectangle width
        16,      // source rectangle height
        0,           // x-coordinate of lower-left corner of 
        0,           // y-coordinate of lower-left corner of 
        0,               // first scan line in array
        0,      // number of scan lines
        nullptr,           // address of array with DIB bits
        nullptr,           // address of structure with bitmap info.
        DIB_RGB_COLORS   // RGB or palette indexes
    );

    SDL_DestroyWindow(window);
    SDL_Quit();
}
