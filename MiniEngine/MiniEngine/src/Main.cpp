#include "Engine/Engine.h"
#include <iostream>

using namespace MiniEngine;

using std::cout;
using std::endl;
using std::cerr;


int main(int argc, char* argv[])
{
    Engine* engine = Engine::GetInstance();

    // Init & Start the Engine!
    engine->Init("Game", 1024, 768);
    engine->Start();

    //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Test", "Hello", window);

    return 0;
}
