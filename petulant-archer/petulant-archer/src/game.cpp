#include "game.hpp"

#include "gfx_engine.hpp"
#include "gfx_entity.hpp"
#include "states.hpp"
#include "states_title_screen.hpp"

namespace petarc
{
	game::game()
		: window_(defs::window_ptr(new sf::RenderWindow()))
		, state_id_(defs::states::title_screen)
	{
		window_->create(sf::VideoMode::getFullscreenModes().front(), "petulant-archer", sf::Style::Fullscreen);
		
		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		// create title screen
		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		
		// create state and gfx engine
		defs::gfx::engine_ptr title_gfx_engine = defs::gfx::engine_ptr(new gfx::engine(window_));
		defs::states::title_screen_ptr title_screen = defs::states::title_screen_ptr(new states::title_screen(title_gfx_engine));

		// add state to states map
		states_[defs::states::title_screen] = title_screen;
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

			if (states_.count(state_id_))
			{
				states_[state_id_]->update();
			}

			window_->clear(sf::Color::Black);
			if (states_.count(state_id_))
			{
				states_[state_id_]->draw();
			}
			window_->display();
		}
	}
}	// namespace petarc
