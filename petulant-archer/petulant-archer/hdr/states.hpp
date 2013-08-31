#ifndef __PETARC_STATES_HPP__
#define __PETARC_STATES_HPP__

#include "defs.hpp"

namespace petarc
{
	namespace states
	{
		class state
		{
		public:
			state(defs::gfx::engine_ptr gfx_engine);

			virtual void draw();
			virtual void update();

		protected:
			virtual void init() = 0;

			defs::gfx::engine_ptr gfx_engine_;
		};	// class state
	} // namespace states
} // namespace petarc

#endif // __PETARC_STATES_HPP__