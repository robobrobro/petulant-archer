#ifndef __PETARC_STATES_TITLESCR_HPP__
#define __PETARC_STATES_TITLESCR_HPP__

#include "defs.hpp"

#include "states.hpp"

namespace petarc
{
	namespace states
	{
		class title_screen : public state
		{
		public:
			title_screen(defs::gfx::engine_ptr gfx_engine);

		protected:
			void init();
		};	// class title_screen
	}	// namespace gfx
}	// namespace petarc

#endif // __PETARC_STATES_TITLESCR_HPP__