#include "states_title_screen.hpp"

#include "gfx_engine.hpp"
#include "gfx_entity.hpp"
#include "states.hpp"

namespace petarc
{
	namespace states
	{
		title_screen::title_screen(defs::gfx::engine_ptr gfx_engine)
			: state(gfx_engine)
		{
			init();
		}

		void title_screen::init()
		{
			// create textures and add them to gfx engine
			defs::gfx::texture_ptr cube_texture = defs::gfx::texture_ptr(new sf::Texture());
			cube_texture->loadFromFile("res/cube.png");
			gfx_engine_->add_texture("cube", cube_texture);

			// create entities and add them to gfx engine
			defs::gfx::entity_ptr entity = defs::gfx::entity_ptr(new gfx::entity());
			entity->setTexture(*gfx_engine_->get_texture("cube"));
			entity->setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2.0f, sf::VideoMode::getDesktopMode().height / 2.0f));
			gfx_engine_->add_entity(entity);
		}
	}
}
