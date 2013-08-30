#include "game.hpp"

#include "gfx_engine.hpp"

#include "gfx_entity.hpp"

namespace petarc
{
	game::game()
		: window_(defs::window_ptr(new sf::RenderWindow()))
		, gfx_engine_(defs::gfx::engine_ptr(new gfx::engine(window_)))
	{
		window_->create(sf::VideoMode::getFullscreenModes().front(), "petulant-archer", sf::Style::Fullscreen);

		// TODO testing...
		defs::gfx::entity_ptr entity = defs::gfx::entity_ptr(new gfx::entity("res/cube.png", sf::Vector2f(36, 36)));
		entity->set_position(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2.0f, sf::VideoMode::getDesktopMode().height / 2.0f));
		gfx_engine_->add_entity(entity);
	}

	void game::run()
	{
		while (window_->isOpen())
		{
			sf::Event e;
			while (window_->pollEvent(e))
			{
				if (e.type == sf::Event::Closed)
				{
					window_->close();
				}
				else if (e.type == sf::Event::KeyPressed)
				{
					if (e.key.code == sf::Keyboard::Escape)
					{
						window_->close();
					}
				}
			}

			gfx_engine_->update();

			window_->clear(sf::Color::Black);
			gfx_engine_->draw();
			window_->display();
		}
	}
}	// namespace petarc
