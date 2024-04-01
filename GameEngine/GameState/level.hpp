#ifndef __LEVEL__
#define __LEVEL__

#include "../Core/core.hpp"

class LevelGameState : public core::GameState, public core::Singleton<LevelGameState>
{
	void Load(void)			override;
	void Initialise(void)	override;
	void Update(void)		override;
	void FixedUpdate(void)	override;
	void Draw(void)			override;
	void Free(void)			override;
	void Unload(void)		override;
};

#endif // !__LEVEL__