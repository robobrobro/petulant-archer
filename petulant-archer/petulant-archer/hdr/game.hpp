#ifndef __PETARC_GAME_HPP__
#define __PETARC_GAME_HPP__

#include "defs.hpp"

namespace petarc
{
	class game
	{
	public:
		game();

		void run();

	protected:
		defs::window_ptr window_;
		defs::states::state_map states_;
		defs::states::state_id state_id_;
	};	// class game
}	// namespace petarc

#endif //__PETARC_GFX_GAME_HPP__