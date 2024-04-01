#ifndef __GAME_STATE_MANAGER__
#define __GAME_STATE_MANAGER__

#include "../pch.hpp"
#include "../Singleton/singleton.hpp"
#include "../InputSystem/input_handler.hpp"

#include "game_state.hpp"

namespace core
{
	enum class GameStateStatus
	{
		STATE_DEFAULT,
		STATE_CHANGE,
		STATE_RESTART,
		STATE_QUIT,
		STATE_ERROR
	};

	class GameStateManager : public Singleton<GameStateManager>
	{
		public:
			void GSInitialise(double framerate, GameState& initial_state);
			void GSSetNextState(GameState& next_state);
			void GSRun(void);
			void GSRestart(void);
			void GSQuit(void);

			double GetFramerate(void);
			double GetDeltaTime(void);
			double GetFixedDeltaTime(void);
			double GetTime(void);
			double GetGameStateTime(void);

		private:
			double p_framerate;
			double p_total_time;
			double p_total_time_in_game_state;
			double p_delta_time;
			double p_fixed_time_step;

			double GetCurrentTimeViaChrono(void);

			GameStateStatus p_previous_status;
			GameStateStatus p_current_status;
			GameStateStatus p_next_status;

			GameState* p_current;
			GameState* p_next;
	};

} // core
#endif // !__GAME_STATE_MANAGER__