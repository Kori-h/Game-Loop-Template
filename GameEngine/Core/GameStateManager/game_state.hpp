#ifndef __GAME_STATE__
#define __GAME_STATE__

namespace core
{
	class GameState
	{
		public:
			void virtual Load(void)			= 0;
			void virtual Initialise(void)	= 0;
			void virtual Update(void)		= 0;
			void virtual FixedUpdate(void)	= 0;
			void virtual Draw(void)			= 0;
			void virtual Free(void)			= 0;
			void virtual Unload(void)		= 0;
	};
}

#endif //!__GAME_STATE__