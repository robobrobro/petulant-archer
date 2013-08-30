#ifndef __PETARC_DEFS_HPP__
#define __PETARC_DEFS_HPP__

#include <SFML/Graphics.hpp>
#include <boost/shared_ptr.hpp>

namespace petarc
{
	namespace gfx
	{
		class engine;
		class entity;
	}	// namespace gfx
	
	namespace defs
	{
		typedef boost::shared_ptr<sf::RenderWindow> window_ptr;

		namespace gfx
		{
			typedef boost::shared_ptr<petarc::gfx::engine> engine_ptr;
			typedef boost::shared_ptr<petarc::gfx::entity> entity_ptr;
		}	// namespace gfx
	}	// namespace defs
}	// namespace petarc

#endif // __PETARC_DEFS_HPP__
