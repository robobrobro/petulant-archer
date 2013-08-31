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
			/*defs::gfx::texture_ptr cube_texture = defs::gfx::texture_ptr(new sf::Texture());
			cube_texture->loadFromFile("res/textures/cube-ss.png");
			gfx_engine_->add_texture("cube", cube_texture);*/

			// create fonts and add them to gfx engine
			defs::gfx::font_ptr title_font(new sf::Font());
			title_font->loadFromFile("res/fonts/boisterb.ttf");
			gfx_engine_->add_font("boister", title_font);

			// create entities and add them to gfx engine
			title_ = defs::gfx::entity_ptr(new gfx::entity());
			/*title_->setTexture(*gfx_engine_->get_texture("cube"));
			title_->setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2.0f, sf::VideoMode::getDesktopMode().height / 2.0f));
			title_->add_frame(sf::IntRect(0, 0, 35, 36));
			title_->add_frame(sf::IntRect(35, 0, 35, 36));
			title_->add_frame(sf::IntRect(70, 0, 35, 36));
			title_->add_frame(sf::IntRect(105, 0, 35, 36));
			title_->add_frame(sf::IntRect(140, 0, 35, 36));
			title_->add_frame(sf::IntRect(175, 0, 35, 36));
			boost::posix_time::time_duration frame_duration = boost::posix_time::milliseconds(200);
			title_->set_frame_duration(frame_duration);
			title_->set_animated(true);
			gfx_engine_->add_entity(title_);*/

			// create the title entity, add the font to it, and add it to the gfx engine
			defs::gfx::text_ptr title_text(new sf::Text());
			title_text->setFont(*gfx_engine_->get_font("boister"));
			title_text->setString("petulant archer");
			title_text->setCharacterSize(100);
			title_text->setColor(sf::Color::White);
			sf::FloatRect text_rect = title_text->getLocalBounds();
			title_text->setPosition(sf::VideoMode::getDesktopMode().width / 2.0f - text_rect.width / 2.0f, sf::VideoMode::getDesktopMode().height * 0.15f - text_rect.height / 2.0f);
			title_->set_text(title_text);
			gfx_engine_->add_entity(title_);
		}

		void title_screen::enter()
		{
			title_->play_animation();
		}

		void title_screen::leave()
		{
			title_->pause_animation();
		}
	}
}
