#ifndef __MAIN_MENU__
#define __MAIN_MENU__

#include "../Core/core.hpp"

class MenuGameState : public core::GameState, public core::Singleton<MenuGameState>
{
	public:
		void Load(void)			override;
		void Initialise(void)	override;
		void Update(void)		override;
		void FixedUpdate(void)	override;
		void Draw(void)			override;
		void Free(void)			override;
		void Unload(void)		override;
};

#endif // !__MAIN_MENU__