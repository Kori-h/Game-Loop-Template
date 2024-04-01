#include "menu.hpp"
#include "../Core/core.hpp"
#include "../GameState/level.hpp"

void MenuGameState::Load(void)
{
	std::cout << "MenuGameState::Load" << std::endl;
}

void MenuGameState::Initialise(void)
{
	std::cout << "MenuGameState::Initialise" << std::endl;
}

void MenuGameState::Update(void)
{
	if (core::InputHandler::GetInstance().GetKeyTriggered(core::KeyCode::KEYCODE_A))
	{
		core::GameStateManager::GetInstance().GSSetNextState(LevelGameState::GetInstance());
	}
}

void MenuGameState::FixedUpdate(void)
{
	
}

void MenuGameState::Draw(void)
{
	
}

void MenuGameState::Free(void)
{
	std::cout << "MenuGameState::Free" << std::endl;
}

void MenuGameState::Unload(void)
{
	std::cout << "MenuGameState::Unload" << std::endl;
}