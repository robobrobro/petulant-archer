#ifndef __PETARC_DEFS_HPP__
#define __PETARC_DEFS_HPP__

#include <SFML/Graphics.hpp>
#include <boost/shared_ptr.hpp>
#include <map>
#include <string>

namespace petarc
{
	namespace gfx
	{
		class engine;
		class entity;
	}	// namespace gfx

	namespace states
	{
		class state;
		class title_screen;
	}	// namespace states
	
	namespace defs
	{
		typedef boost::shared_ptr<sf::RenderWindow> window_ptr;

		namespace gfx
		{
			typedef boost::shared_ptr<petarc::gfx::engine> engine_ptr;
			typedef boost::shared_ptr<petarc::gfx::entity> entity_ptr;

			typedef boost::shared_ptr<sf::Texture> texture_ptr;
			typedef std::map<std::string, defs::gfx::texture_ptr> texture_map;
		}	// namespace gfx

		namespace states
		{
			enum state_e
			{
				title_screen,
				playing,
				paused,
			};

			typedef unsigned short state_id;
			typedef boost::shared_ptr<petarc::states::state> state_ptr;

			typedef std::map<state_id, state_ptr> state_map;

			typedef boost::shared_ptr<petarc::states::title_screen> title_screen_ptr;
		}	// namespace states
	}	// namespace defs
}	// namespace petarc

#endif // __PETARC_DEFS_HPP__
