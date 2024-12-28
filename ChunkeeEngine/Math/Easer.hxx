#pragma once


namespace Chunkee
{
	namespace Math
	{
		constexpr float PI = 3.14159f;
		constexpr float TAU = PI * 2;
		constexpr float FBE = 1.70158f; // Fallback effect constant

		class Ease
		{
		public:
			////////////////////////////////////////
			/// LINEAR
			////////////////////////////////////////
			static float linear(const float& step);

			////////////////////////////////////////
			/// SINE
			////////////////////////////////////////
			static float inSine(const float& step);
			static float outSine(const float& step);
			static float inOutSine(const float& step);

			////////////////////////////////////////
			/// QUADRATIC
			////////////////////////////////////////
			static float inQuad(const float& step);
			static float outQuad(const float& step);
			static float inOutQuad(const float& step);

			////////////////////////////////////////
			/// CUBIC
			////////////////////////////////////////
			static float inCubic(const float& step);
			static float outCubic(const float& step);
			static float inOutCubic(const float& step);

			////////////////////////////////////////
			/// QUARTIC
			////////////////////////////////////////
			static float inQuart(const float& step);
			static float outQuart(const float& step);
			static float inOutQuart(const float& step);

			////////////////////////////////////////
			/// QUINTIC
			////////////////////////////////////////
			static float inQuint(const float& step);
			static float outQuint(const float& step);
			static float inOutQuint(const float& step);

			////////////////////////////////////////
			/// EXPONENTIAL
			////////////////////////////////////////
			static float inExpo(const float& step);
			static float outExpo(const float& step);
			static float inOutExpo(const float& step);

			////////////////////////////////////////
			/// CIRCULAR
			////////////////////////////////////////
			static float inCirc(const float& step);
			static float outCirc(const float& step);
			static float inOutCirc(const float& step);

			////////////////////////////////////////
			/// BACK (SPECIAL)
			////////////////////////////////////////
			static float inBack(const float& step);
			static float outBack(const float& step);
			static float inOutBack(const float& step);

			////////////////////////////////////////
			/// ELASTIC (SPECIAL)
			////////////////////////////////////////
			static float inElastic(const float& step);
			static float outElastic(const float& step);
			static float inOutElastic(const float& step);

			////////////////////////////////////////
			/// BOUNCE (SPECIAL)
			////////////////////////////////////////
			static float inBounce(const float& step);
			static float outBounce(const float& step);
			static float inOutBounce(const float& step);
		};
	}
}