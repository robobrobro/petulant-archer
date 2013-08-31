#include "gfx_engine.hpp"

#include "gfx_entity.hpp"

namespace petarc
{
	namespace gfx
	{
		engine::engine(defs::window_ptr window)
			: window_(window)
		{
		}

		void engine::add_entity(defs::gfx::entity_ptr entity)
		{
			entities_.push_back(entity);
		}

		void engine::remove_entity(defs::gfx::entity_ptr entity)
		{
			bool found = false;
			for (std::size_t idx = 0; !found && idx < entities_.size(); ++idx)
			{
				if (entities_[idx] == entity)
				{
					entities_.erase(entities_.begin() + idx);
					found = true;
				}
			}
		}

		void engine::add_texture(const std::string & name, defs::gfx::texture_ptr texture)
		{
			if (textures_.count(name) == 0)
			{
				textures_[name] = texture;
			}
		}

		defs::gfx::texture_ptr engine::get_texture(const std::string & name) const
		{
			defs::gfx::texture_ptr texture;
			if (textures_.count(name))
			{
				texture = textures_.at(name);
			}

			return texture;
		}	

		void engine::remove_texture(const std::string & name)
		{
			if (textures_.count(name))
			{
				textures_.erase(name);
			}
		}

		void engine::add_font(const std::string & name, defs::gfx::font_ptr font)
		{
			if (fonts_.count(name) == 0)
			{
				fonts_[name] = font;
			}
		}

		defs::gfx::font_ptr engine::get_font(const std::string & name) const
		{
			defs::gfx::font_ptr font;
			if (fonts_.count(name))
			{
				font = fonts_.at(name);
			}

			return font;
		}	

		void engine::remove_font(const std::string & name)
		{
			if (fonts_.count(name))
			{
				fonts_.erase(name);
			}
		}

		void engine::draw()
		{
			for (std::size_t idx = 0; idx < entities_.size(); ++idx)
			{
				defs::gfx::text_ptr text = entities_[idx]->get_text();
				if (!text)
				{
					window_->draw(*entities_[idx]);
				}
				else
				{
					window_->draw(*text);
				}
			}
		}

		void engine::update()
		{
			for (std::size_t idx = 0; idx < entities_.size(); ++idx)
			{
				entities_[idx]->update();
			}
		}
	}	// namespace gfx
}	// namespace petarc
