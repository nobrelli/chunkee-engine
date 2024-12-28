#pragma once

#include "../Types.hxx"
#include <functional>
#include <chrono>


namespace Chunkee
{
	namespace Math
	{
		using std::chrono::steady_clock;

		/* Based on my python library Tweener */
		enum class Easing
		{
			LINEAR, SINE, QUAD, CUBIC,
			QUART, QUINT, EXPO, CIRC,
			BACK, ELASTIC, BOUNCE
		};

		enum class EasingMode
		{
			IN, OUT, IN_OUT
		};

		class Tween
		{
		public:
			Tween(const float& begin = 0.f,
				  const float& end = 1.f,
				  const UInt32& duration = 600u,
				  const Easing& easing = Easing::LINEAR,
				  const EasingMode& easingMode = EasingMode::IN,
				  const bool& boomerang = false,
				  const bool& loop = false,
				  const UInt32& reps = 0);
			Tween(const Tween&) = delete;

			void start();
			void pause();
			void resume();
			void update();

			float getValue() const;
			bool isAnimating() const;

		private:
			void _doLoop();

		private:
			float m_origin, m_begin, m_end, m_duration, m_step, m_value;
			bool m_boomerang, m_loop, m_animating, m_paused;
			UInt32 m_reps, m_count;
			steady_clock::duration m_pauseDuration;
			steady_clock::time_point m_startTime, m_pauseStart;
			Func<float(const float&)> ease;
		};
	}
}
