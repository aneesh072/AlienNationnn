#include "Global.h"
Global::Global()
{
}


Global::~Global()
{
}

SDL_Color Global::colorSelect = { 255, 0, 0, 255 };
SDL_Color Global::colorDeselect = { 100, 0, 0, 255 };
SDL_Window* Global::window = NULL;
SDL_Renderer* Global::renderer = NULL;
bool Global::quitGame = false;
bool Global::isDebug = false;
MachineState Global::machineState;
