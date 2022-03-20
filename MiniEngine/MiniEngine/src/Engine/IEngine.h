#ifndef IENGINE_H
#define IENGINE_H

namespace MiniEngine
{
    /// <summary>
    /// Engine Interface for engine subsystems such as Graphics, Input...
    /// Most 
    /// </summary>
    class IEngine
    {
    public:
        virtual void Terminate() = 0;  // Use it for free allocated things and destroy the object
        virtual void FrameStart() = 0; // Use it for stuff todo at frame start
        virtual void FrameEnd() = 0;   // Use it for stuff todo at frame end
        bool IsInited() const { return mInited; }

    protected:
        bool mInited = false;
    };
}


#endif // IENGINE_H

