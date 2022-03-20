#include "Input.h"

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

namespace MiniEngine
{
    Input::Input()
    {
        mMousePos.Set(0, 0);
        ClearInputs();
    }

    Input::~Input()
    {
        cout << "Input terminated." << endl;
    }

    bool Input::Init()
    {
        if (mInited)
        {
            cerr << "Input is already inited... Ignoring Init call" << endl;
            return false;
        }

        mInited = true;
        cout << "Input inited." << endl;

        return true;
    }

    void Input::Terminate()
    {
        mInited = false;
        Destroy();
    }

    void Input::FrameStart()
    {
        PollEvents();
    }

    void Input::FrameEnd()
    {
        ClearInputs();
    }

    void Input::PollEvents()
    {
        SDL_Event events;

        int keydownCounter = 0;

        // Poll SDL events
        while (SDL_PollEvent(&events))
        {
            if (events.type == SDL_QUIT)
            {
                mIsQuitEvent = true;
            }
            else if (events.type == SDL_MOUSEMOTION)
            {
                mMousePos.Set(static_cast<float>(events.motion.x), static_cast<float>(events.motion.y));
            }
            else if (events.type == SDL_KEYDOWN)
            {
                if(keydownCounter < MaxKeys)
                {
                    mKeys[keydownCounter] = events.key.keysym.sym;
                }
            }
            else if (events.type == SDL_MOUSEBUTTONDOWN)
            {
                mMouseButton = events.button.button;
            }
        }
    }

    bool Input::IsQuitEvent()
    {
        return mIsQuitEvent;
    }

    bool Input::GetMouseButton(int mouseButton) 
    {
        return (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(mouseButton));
    }

    bool Input::GetMouseButtonDown(int mouseButton) 
    {
        return mMouseButton > 0 && mMouseButton == mouseButton;
    }

    bool Input::GetKey(SDL_KeyCode keyCode) 
    {
        return SDL_GetKeyboardState(NULL)[keyCode] == 1;
    }

    bool Input::GetKeyDown(SDL_KeyCode keyCode)
    {
        bool result = false;

        for (int i = 0; i < MaxKeys; i++)
        {
            if(mKeys[i] == keyCode)
            {
                result = true;
                break;
            }
        }

        return result;
    }

    Vector2 Input::GetMousePosition()
    {
        return mMousePos;
    }

    void Input::ClearInputs()
    {
        mMouseButton = 0;

        for(int i = 0; i < MaxKeys; i++)
        {
            mKeys[i] = SDLK_UNKNOWN;
        }
    }
}
