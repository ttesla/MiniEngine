#include "Graphics.h"

#include <iostream>

using std::cerr;
using std::endl;
using std::cout;

namespace MiniEngine
{
    Graphics::Graphics()
    {
        mClearColor.r = 200;
        mClearColor.g = 100;
        mClearColor.b = 150;
        mClearColor.a = 255;
    }

    Graphics::~Graphics()
    {
        cout << "Graphics terminated." << endl;
    }

    bool Graphics::Init(SDL_Window *window)
    {
        if (mInited)
        {
            cerr << "Graphics is already inited... Ignoring Init call" << endl;
            return false;
        }

        mRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if(mRenderer == nullptr)
        {
            cerr << "Failed to create Renderer: " << SDL_GetError() << endl;
            return false;
        }

        mInited = true;
        cout << "Graphics inited." << endl;
        
        return true;
    }

    void Graphics::Terminate()
    {
        if(mRenderer != nullptr)
        {
            SDL_DestroyRenderer(mRenderer);
            mRenderer = nullptr;
        }

        mInited = false;
        Destroy();
    }

    void Graphics::FrameStart()
    {
        Clear();
    }

    void Graphics::FrameEnd()
    {
        Render();
    }

    void Graphics::SetClearColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
    {
        mClearColor.r = r;
        mClearColor.g = g;
        mClearColor.b = b;
        mClearColor.a = a;
    }

    void Graphics::Clear()
    {
        SDL_SetRenderDrawColor(mRenderer, mClearColor.r, mClearColor.g, mClearColor.b, mClearColor.a);
        SDL_RenderClear(mRenderer);
    }

    void Graphics::Render()
    {
        SDL_RenderPresent(mRenderer);
    }
}
