#include <windows.h>
#include "Core/core.hpp"

#include "GameState/menu.hpp"
#include "GameState/level.hpp"

int APIENTRY wWinMain
(
    _In_ HINSTANCE      hInstance,
    _In_opt_ HINSTANCE  hPrevInstance,
    _In_ LPWSTR         lpCmdLine,
    _In_ int            nCmdShow
)
{
    UNREFERENCED_PARAMETER(hInstance);
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    UNREFERENCED_PARAMETER(nCmdShow);

    if (AllocConsole())
    {
        FILE* file;
        freopen_s(&file, "CONOUT$", "wt", stdout);
        freopen_s(&file, "CONOUT$", "wt", stderr);
        freopen_s(&file, "CONOUT$", "wt", stdin);
    }

    core::GameStateManager::GetInstance().GSInitialise(60, MenuGameState::GetInstance());
    core::GameStateManager::GetInstance().GSRun();

    return 0;
}