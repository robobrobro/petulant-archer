#include "gfx_entity.hpp"

namespace petarc
{
	namespace gfx
	{
		entity::entity(const std::string & tileset)
		{
			init(tileset, sf::Vector2f(0, 0));
		}

		entity::entity(const std::string & tileset, sf::Vector2f size)
			: size_(size)
		{
			init(tileset, size);
		}

		void entity::init(const std::string & tileset, sf::Vector2f size)
		{
			tileset_.loadFromFile(tileset);
			vertices_.setPrimitiveType(sf::Quads);
			vertices_.resize(4); // one quad (sprite)

			update_vertices();
		}

		void entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
		{
			states.texture = &tileset_;

			target.draw(vertices_, states);
		}

		void entity::update()
		{
		}

		sf::Vector2f entity::get_position() const
		{
			return position_;
		}

		void entity::set_position(sf::Vector2f position)
		{
			position_ = position;

			update_vertices();
		}

		void entity::update_vertices()
		{
			sf::Vertex * quad = &vertices_[0];
			quad[0].position = position_ + sf::Vector2f(0, 0);
			quad[1].position = position_ + sf::Vector2f(size_.x, 0);
			quad[2].position = position_ + sf::Vector2f(size_.x, size_.y);
			quad[3].position = position_ + sf::Vector2f(0, size_.y);

			quad[0].color = sf::Color::White;
			quad[1].color = sf::Color::White;
			quad[2].color = sf::Color::White;
			quad[3].color = sf::Color::White;

            quad[0].texCoords = sf::Vector2f(0.f, 0.f);
			quad[1].texCoords = sf::Vector2f(size_.x, 0.f);
			quad[2].texCoords = sf::Vector2f(size_.x, size_.y);
            quad[3].texCoords = sf::Vector2f(0.f, size_.y);
		}
	}	// namespace gfx
}	// namespace petarc
