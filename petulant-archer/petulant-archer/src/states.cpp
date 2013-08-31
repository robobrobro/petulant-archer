#include "states.hpp"

#include "gfx_engine.hpp"

namespace petarc
{
	namespace states
	{
		state::state(defs::gfx::engine_ptr gfx_engine)
			: gfx_engine_(gfx_engine)
		{}

		void state::draw()
		{
			gfx_engine_->draw();
		}

		void state::update()
		{
			gfx_engine_->update();
		}
	}	// namespace states
}	// namespace petarc
