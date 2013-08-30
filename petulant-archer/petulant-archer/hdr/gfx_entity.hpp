#ifndef __PETARC_GFX_ENTITY_HPP__
#define __PETARC_GFX_ENTITY_HPP__

#include <string>

#include "defs.hpp"

namespace petarc
{
	namespace gfx
	{
		class entity : public sf::Drawable
		{
		public:
			entity(const std::string & tileset);
			entity(const std::string & tileset, sf::Vector2f size);

			virtual void update();

			sf::Vector2f get_position() const;
			void         set_position(sf::Vector2f position);

		protected:
			void init(const std::string & tileset, sf::Vector2f size);

			void update_vertices();

			sf::Texture tileset_;
			sf::VertexArray vertices_;
			sf::Vector2f position_;
			sf::Vector2f size_;

		private:
			virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
		};	// class entity
	}	// namespace gfx
}	// namespace petarc

#endif // __PETARC_GFX_ENTITY_HPP__