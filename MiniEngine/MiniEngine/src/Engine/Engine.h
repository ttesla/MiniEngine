#ifndef ENGINE_H
#define ENGINE_H

#include "Singleton.h"
#include "IEngine.h"
#include "SDL.h"

#include <string>

namespace MiniEngine
{
    class Engine : public Singleton<Engine>, public IEngine
    {
    public:
        // This is required for singleton template pattern
        friend class Singleton<Engine>;

        bool Init(const std::string& windowTitle, int screenWidth, int screenHeight);
        void Terminate() override;
        void FrameStart() override;
        void FrameEnd() override;
        void Start(); // Starts the Engine Core Loop
        void Stop();  // Stops the Engine Core Loop

    protected:
        
        Engine();
        ~Engine();

    private:
        void CoreLoop();        // Core loop of the engine
        void Update();          // Update is called first
        void Render();          // Render is called right after
        
        SDL_Window* mWindow = nullptr;
        bool mStopFlag = false; 

    };
}

#endif // ENGINE_H
