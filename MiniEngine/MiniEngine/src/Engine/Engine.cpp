#include "Engine.h"
#include "Graphics.h"
#include "Input.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

namespace MiniEngine
{
    Engine::Engine()
    {

    }

    Engine::~Engine()
    {
        cout << "Engine terminated." << endl;
    }

    bool Engine::Init(const std::string& windowTitle, int screenWidth, int screenHeight)
    {
        if(mInited)
        {
            cerr << "Engine is already inited... Ignoring Init call." << endl;
            return false;
        }

        // SDL Init
        if (SDL_Init(SDL_INIT_VIDEO < 0))
        {
            cerr << "Failed to Init SDL: " << SDL_GetError() << endl;
            return false;
        }

        // Create SDL Window
        mWindow = SDL_CreateWindow("Mini Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

        if(mWindow == nullptr)
        {
            cerr << "Failed to create Window: " << SDL_GetError() << endl;
            return false;
        }

        // Init other subsystems... 
        if (!Graphics::GetInstance()->Init(mWindow))  { return false; } // Graphics
        if (!Input::GetInstance()->Init())            { return false; } // Input

        cout << "Engine inited." << endl;
        mInited = true;

        return true;
    }

    void Engine::Terminate()
    {
        if(mWindow != nullptr)
        {
            SDL_DestroyWindow(mWindow);
            mWindow = nullptr;
        }

        if(mInited)
        {
            SDL_Quit();
        }

        mInited = false;
        
        Graphics::GetInstance()->Terminate();  // Terminate Graphics System
        Input::GetInstance()->Terminate();     // Terminate Input System
        Destroy();                             // Destroy Engine instance
    }

    void Engine::Start()
    {
        CoreLoop();
    }

    void Engine::Stop()
    {
        mStopFlag = true;
    }

    void Engine::CoreLoop()
    {
        while (!mStopFlag)
        {
            FrameStart();
            Update();
            Render();
            FrameEnd();
        }

        // If we are here, terninate the Engine
        Terminate();
    }

    void Engine::FrameStart()
    {
        Input::GetInstance()->FrameStart();
        Graphics::GetInstance()->FrameStart();
    }

    void Engine::FrameEnd()
    {
        Input::GetInstance()->FrameEnd();
        Graphics::GetInstance()->FrameEnd();
    }

    void Engine::Update()
    {
        if (Input::GetInstance()->GetKeyDown(SDLK_ESCAPE) || Input::GetInstance()->IsQuitEvent())
        {
            Stop();
        }

        // TODO: call all game objects update function here...
    }

    void Engine::Render()
    {
        // TODO: call all game objects render function here...
    }
}
