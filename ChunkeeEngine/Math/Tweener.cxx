#include "Tweener.hxx"
#include "Easer.hxx"


namespace Chunkee
{
	namespace Math
	{
		using std::chrono::duration_cast;

		Tween::Tween(const float& begin, 
					 const float& end, 
					 const UInt32& duration, 
					 const Easing& easing, 
					 const EasingMode& easingMode, 
					 const bool& boomerang, 
					 const bool& loop, 
					 const UInt32& reps) :
			m_origin(begin),
			m_begin(begin),
			m_end(end),
			m_duration(duration),
			m_step(0.f), 
			m_value(0.f),
			m_boomerang(boomerang),
			m_loop(loop),
			m_animating(false),
			m_paused(false),
			m_reps(reps),
			m_count(0u)
		{
			switch (easing)
			{
				case Easing::SINE:
					switch (easingMode)
					{
						case EasingMode::IN:
							ease = Ease::inSine;
							break;
						case EasingMode::OUT:
							ease = Ease::outSine;
							break;
						case EasingMode::IN_OUT:
							ease = Ease::inOutSine;
							break;
					}
					break;
				case Easing::QUAD:
					switch (easingMode)
					{
						case EasingMode::IN:
							ease = Ease::inQuad;
							break;
						case EasingMode::OUT:
							ease = Ease::outQuad;
							break;
						case EasingMode::IN_OUT:
							ease = Ease::inOutQuad;
							break;
					}
					break;
				case Easing::CUBIC:
					switch (easingMode)
					{
						case EasingMode::IN:
							ease = Ease::inCubic;
							break;
						case EasingMode::OUT:
							ease = Ease::outCubic;
							break;
						case EasingMode::IN_OUT:
							ease = Ease::inOutCubic;
							break;
					}
					break;
				case Easing::QUART:
					switch (easingMode)
					{
						case EasingMode::IN:
							ease = Ease::inQuart;
							break;
						case EasingMode::OUT:
							ease = Ease::outQuart;
							break;
						case EasingMode::IN_OUT:
							ease = Ease::inOutQuart;
							break;
					}
					break;
				case Easing::QUINT:
					switch (easingMode)
					{
						case EasingMode::IN:
							ease = Ease::inQuint;
							break;
						case EasingMode::OUT:
							ease = Ease::outQuint;
							break;
						case EasingMode::IN_OUT:
							ease = Ease::inOutQuint;
							break;
					}
					break;
				case Easing::EXPO:
					switch (easingMode)
					{
						case EasingMode::IN:
							ease = Ease::inExpo;
							break;
						case EasingMode::OUT:
							ease = Ease::outExpo;
							break;
						case EasingMode::IN_OUT:
							ease = Ease::inOutExpo;
							break;
					}
					break;
				case Easing::CIRC:
					switch (easingMode)
					{
						case EasingMode::IN:
							ease = Ease::inCirc;
							break;
						case EasingMode::OUT:
							ease = Ease::outCirc;
							break;
						case EasingMode::IN_OUT:
							ease = Ease::inOutCirc;
							break;
					}
					break;
				case Easing::BACK:
					switch (easingMode)
					{
						case EasingMode::IN:
							ease = Ease::inBack;
							break;
						case EasingMode::OUT:
							ease = Ease::outBack;
							break;
						case EasingMode::IN_OUT:
							ease = Ease::inOutBack;
							break;
					}
					break;
				case Easing::ELASTIC:
					switch (easingMode)
					{
						case EasingMode::IN:
							ease = Ease::inElastic;
							break;
						case EasingMode::OUT:
							ease = Ease::outElastic;
							break;
						case EasingMode::IN_OUT:
							ease = Ease::inOutElastic;
							break;
					}
					break;
				case Easing::BOUNCE:
					switch (easingMode)
					{
						case EasingMode::IN:
							ease = Ease::inBounce;
							break;
						case EasingMode::OUT:
							ease = Ease::outBounce;
							break;
						case EasingMode::IN_OUT:
							ease = Ease::inOutBounce;
							break;
					}
					break;
				default:
					ease = Ease::linear;
					break;
			}
		}

		void Tween::start()
		{
			if (!m_animating)
			{
				m_startTime = steady_clock::now();
				m_animating = true;
			}
		}

		void Tween::pause()
		{
			if (!m_paused)
			{
				m_paused = true;
				m_pauseStart = steady_clock::now();
			}
		}

		void Tween::resume()
		{
			if (m_paused)
			{
				m_paused = false;
				m_pauseDuration = steady_clock::now() - m_pauseStart;
				m_startTime += m_pauseDuration;
			}
		}

		void Tween::update()
		{
			if (m_animating && !m_paused)
			{
				auto thisTime = steady_clock::now();
				auto elapsed = duration_cast<std::chrono::milliseconds>(thisTime - m_startTime).count();
				m_step = fminf(static_cast<float>(elapsed) / m_duration, 1.0f);
				float delta = m_end - m_begin;

				m_value = ease(m_step) * delta + m_begin;

				if (m_step == 1.0f)
				{
					if (m_boomerang)
					{
						m_startTime = thisTime;
						std::swap(m_begin, m_end);

						if (m_value == m_origin)
						{
							if (m_loop)
								_doLoop();
							else
								m_animating = false;
						}
					}
					else
					{
						if (m_loop)
							_doLoop();
						else
							m_animating = false;
					}
				}
			}
		}

		float Tween::getValue() const
		{
			return m_value;
		}

		bool Tween::isAnimating() const
		{
			return m_animating;
		}

		void Tween::_doLoop()
		{
			if (!m_reps)
			{
				m_animating = false;
				start();
			}
			else
			{
				if (m_count < m_reps)
				{
					++m_count;
					m_animating = false;
					start();
				}
				else
				{
					m_count = 1;
					m_animating = false;
				}
			}
		}
	}
}