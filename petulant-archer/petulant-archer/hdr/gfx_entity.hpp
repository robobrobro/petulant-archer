#ifndef __PETARC_GFX_ENTITY_HPP__
#define __PETARC_GFX_ENTITY_HPP__

#include <boost/date_time/posix_time/posix_time.hpp>

#include "defs.hpp"

namespace petarc
{
	namespace gfx
	{
		class entity : public sf::Sprite
		{
		public:
			entity();

			virtual void update();
			
			// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			// animation
			// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

			inline bool is_animated() const { return is_animated_; }
			inline void set_animated(bool is_animated) { is_animated_ = is_animated; }

			inline void play_animation() 
			{ 
				if (animation_state_ == stopped)
				{
					frame_idx_ = 0;
					frame_start_time_ = boost::posix_time::microsec_clock::local_time();
				}
				else if (animation_state_ == paused)
				{
					boost::posix_time::time_duration pause_duration = boost::posix_time::microsec_clock::local_time() - frame_pause_time_;
					frame_start_time_ -= pause_duration;
				}

				animation_state_ = playing;
			}
			inline void pause_animation() 
			{ 
				if (animation_state_ != playing)
					return;

				animation_state_ = paused;
				frame_pause_time_ = boost::posix_time::microsec_clock::local_time();
			}
			inline void stop_animation() { animation_state_ = stopped; }

			inline void add_frame(sf::IntRect frame) { frames_.push_back(frame); }
			inline void set_frame_duration(const boost::posix_time::time_duration & duration) { frame_duration_ = duration; }
			
			// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			// text
			// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			inline defs::gfx::text_ptr get_text() const { return text_; }
			inline void set_text(defs::gfx::text_ptr text) { text_ = text; }

		protected:
			virtual void init();

			// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			// animation
			// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

			void animate();

			bool is_animated_;
			enum animation_state
			{
				stopped,
				paused,
				playing,
			};
			animation_state animation_state_;
			std::size_t frame_idx_;
			std::vector<sf::IntRect> frames_;
			boost::posix_time::time_duration frame_duration_;
			boost::posix_time::ptime frame_pause_time_;
			boost::posix_time::ptime frame_start_time_;
			
			// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			// text
			// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			defs::gfx::text_ptr text_;
		};	// class entity
	}	// namespace gfx
}	// namespace petarc

#endif // __PETARC_GFX_ENTITY_HPP__