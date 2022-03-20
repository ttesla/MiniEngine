#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Singleton.h"
#include "IEngine.h"
#include "SDL.h"

namespace MiniEngine
{
    /// <summary>
    /// Handles Graphics operations. 
    /// Creating renderer, updating renderer, rendering images and primitive things.
    /// </summary>
    class Graphics : public Singleton<Graphics>, public IEngine
    {
    public:
        // This is required for singleton template pattern
        friend class Singleton<Graphics>;

        bool Init(SDL_Window* window);
        void Terminate() override;
        void FrameStart() override;
        void FrameEnd() override;
        void SetClearColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    protected:
        Graphics();
        ~Graphics();

    private:
        SDL_Renderer* mRenderer = nullptr;
        SDL_Color mClearColor;
        void Clear();
        void Render();
    };
}

#endif // GRAPHICS_H
