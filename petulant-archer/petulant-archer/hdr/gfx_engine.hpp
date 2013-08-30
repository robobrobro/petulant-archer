#ifndef __PETARC_GFX_ENGINE_HPP__
#define __PETARC_GFX_ENGINE_HPP__

#include "defs.hpp"

namespace petarc
{
	namespace gfx
	{
		class engine
		{
		public:
			engine(defs::window_ptr window);

			void add_entity(defs::gfx::entity_ptr entity);
			void remove_entity(defs::gfx::entity_ptr entity);

			void draw();
			void update();

		protected:
			defs::window_ptr window_;
			std::vector<defs::gfx::entity_ptr> entities_; // TODO change to map <int, entity> where int is unique entity identifier
		};	// class engine
	}	// namespace gfx
}	// namespace petarc

#endif // __PETARC_GFX_ENGINE_HPP__
