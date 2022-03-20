#ifndef INPUT_H
#define INPUT_H

#include "Singleton.h"
#include "IEngine.h"
#include "SDL.h"
#include "Utility/Vector2.h"

namespace MiniEngine
{
    /// <summary>
    /// Input System of MiniEngine. 
    /// Handles keyboard, mouse and window input events
    /// </summary>
    class Input : public Singleton<Input>, public IEngine
    {
    public:
        // This is required for singleton template pattern
        friend class Singleton<Input>;

        bool Init();
        void Terminate() override;
        void FrameStart() override;
        void FrameEnd() override;
        bool GetMouseButton(int mouseButton);     // mouseButton = 1: Left, 2: Middle, 3: Left. Checks is the button currently held down
        bool GetMouseButtonDown(int mouseButton); // mouseButton = 1: Left, 2: Middle, 3: Left. Checks is the button pressed in this frame
        bool GetKey(SDL_KeyCode keyCode);         // Is the key currently held down
        bool GetKeyDown(SDL_KeyCode keyCode);     // Is the key pressed in this frame
        Vector2 GetMousePosition();               // Get position of the mouse
        bool IsQuitEvent();                       // If window close event is detected 

    protected:
        Input();
        ~Input();

    private:
        void PollEvents();            // Polls all events (keyboard, mouse, window...)
        void ClearInputs();           // Clear inputs at the end of the frame

        bool mIsQuitEvent = false;    // If SDL window is closed or user quits the program, this flag is set
        Vector2 mMousePos;            // Mouse position data X, Y
        Uint8 mMouseButton = 0;       // Mouse button pressed this frame
        
        static const int MaxKeys = 5;
        SDL_Keycode mKeys[MaxKeys];   // Keys pressed this frame
    };

}

#endif // INPUT_H

