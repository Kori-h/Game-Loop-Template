#include "game_state_manager.hpp"

namespace core 
{
	void GameStateManager::GSInitialise(double framerate, GameState& initial_state)
	{
		p_framerate = framerate;
		p_fixed_time_step = 1.0f / framerate;
		p_current_status = p_previous_status = p_next_status = GameStateStatus::STATE_DEFAULT;
		p_current = p_next = &initial_state;
	}

	void GameStateManager::GSSetNextState(GameState& next_state)
	{
		p_next_status = GameStateStatus::STATE_CHANGE;
		p_next = &next_state;
	}

	void GameStateManager::GSRun(void)
	{	
		while (p_current_status != GameStateStatus::STATE_QUIT)
		{
			if (p_current_status == GameStateStatus::STATE_RESTART)
			{
				p_current_status = p_previous_status;
				p_next_status = p_previous_status;
			}
			else
			{
				p_current = p_next;
				p_current->Load();
			}

			p_next_status = GameStateStatus::STATE_DEFAULT;
			p_current->Initialise();

			p_total_time_in_game_state = 0;
			double current_time = GetCurrentTimeViaChrono();
			double accumulator = 0;

			while (p_next_status == GameStateStatus::STATE_DEFAULT)
			{
				double new_time = GetCurrentTimeViaChrono();
				p_delta_time = new_time - current_time;
				current_time = new_time;

				InputHandler::GetInstance().Update();
				p_current->Update();
				p_current->Draw();

				do
				{
					new_time = GetCurrentTimeViaChrono();
					p_delta_time = new_time - current_time;

				} while (p_delta_time < p_fixed_time_step);

				accumulator += p_delta_time;

				while (accumulator >= p_fixed_time_step)
				{
					p_current->FixedUpdate();
					accumulator -= p_fixed_time_step;
				}

				p_total_time_in_game_state += p_delta_time;
				p_total_time += p_delta_time;
			}

			p_current->Free();

			if (p_next_status != GameStateStatus::STATE_RESTART)
			{
				p_current->Unload();
			}

			p_previous_status = p_current_status;
			p_current_status = p_next_status;
		}
	}

	void GameStateManager::GSRestart(void)
	{
		p_next_status = GameStateStatus::STATE_RESTART;
	}

	void GameStateManager::GSQuit(void)
	{
		p_next_status = GameStateStatus::STATE_QUIT;
	}

	double GameStateManager::GetFramerate(void)
	{
		return p_framerate;
	}

	double GameStateManager::GetTime(void)
	{
		return p_total_time;
	}

	double GameStateManager::GetGameStateTime(void)
	{
		return p_total_time_in_game_state;
	}

	double GameStateManager::GetDeltaTime(void)
	{
		return p_delta_time;
	}

	double GameStateManager::GetFixedDeltaTime(void)
	{
		return p_fixed_time_step;
	}

	double GameStateManager::GetCurrentTimeViaChrono(void)
	{
		return std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count();
	}
}