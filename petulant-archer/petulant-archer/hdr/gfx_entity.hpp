#ifndef __PETARC_GFX_ENTITY_HPP__
#define __PETARC_GFX_ENTITY_HPP__

#include "defs.hpp"

namespace petarc
{
	namespace gfx
	{
		class entity : public sf::Sprite
		{
		public:
			entity();

			virtual void update();

		protected:
			virtual void init();
		};	// class entity
	}	// namespace gfx
}	// namespace petarc

#endif // __PETARC_GFX_ENTITY_HPP__