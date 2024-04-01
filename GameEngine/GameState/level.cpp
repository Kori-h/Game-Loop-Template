#include "level.hpp"
#include "../GameState/menu.hpp"

void LevelGameState::Load(void)
{
	std::cout << "LevelGameState::Load" << std::endl;
}

void LevelGameState::Initialise(void)
{
	std::cout << "LevelGameState::Initialise" << std::endl;
}

void LevelGameState::Update(void)
{
	if (core::InputHandler::GetInstance().GetKeyDown(core::KeyCode::KEYCODE_A))
	{
		core::GameStateManager::GetInstance().GSSetNextState(MenuGameState::GetInstance());
	}
}

void LevelGameState::FixedUpdate(void)
{
	
}

void LevelGameState::Draw(void)
{
	
}

void LevelGameState::Free(void)
{
	std::cout << "LevelGameState::Free" << std::endl;
}

void LevelGameState::Unload(void)
{
	std::cout << "LevelGameState::Unload" << std::endl;
}