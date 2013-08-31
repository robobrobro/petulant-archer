#ifndef __PETARC_GFX_ENGINE_HPP__
#define __PETARC_GFX_ENGINE_HPP__

#include "defs.hpp"

namespace petarc
{
	namespace gfx
	{
		class engine
		{
		public:
			engine(defs::window_ptr window);

			void add_entity(defs::gfx::entity_ptr entity);
			void remove_entity(defs::gfx::entity_ptr entity);

			void add_texture(const std::string & name, defs::gfx::texture_ptr texture);
			defs::gfx::texture_ptr get_texture(const std::string & name) const;
			void remove_texture(const std::string & name);

			void draw();
			void update();

		protected:
			defs::window_ptr window_;
			std::vector<defs::gfx::entity_ptr> entities_; 
			defs::gfx::texture_map textures_;
		};	// class engine
	}	// namespace gfx
}	// namespace petarc

#endif // __PETARC_GFX_ENGINE_HPP__
