#include "gfx_entity.hpp"

namespace petarc
{
	namespace gfx
	{
		entity::entity()
			: is_animated_(false)
			, animation_state_(stopped)
			, frame_idx_(-1)
		{
			init();
		}

		void entity::init()
		{
		}

		void entity::update()
		{
			animate();
		}

		void entity::animate()
		{
			if (!is_animated_ || animation_state_ != playing || frames_.empty())
				return;

			boost::posix_time::ptime now = boost::posix_time::microsec_clock::local_time();
			boost::posix_time::time_duration delta = now - frame_start_time_;
			if (delta >= frame_duration_)
			{
				frame_idx_ = (frame_idx_ + 1) % frames_.size();
				frame_start_time_ = now;
			}

			setTextureRect(frames_[frame_idx_]);
		}
	}	// namespace gfx
}	// namespace petarc
