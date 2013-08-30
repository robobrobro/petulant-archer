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

		void engine::draw()
		{
			for (std::size_t idx = 0; idx < entities_.size(); ++idx)
			{
				window_->draw(*entities_[idx]);
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
