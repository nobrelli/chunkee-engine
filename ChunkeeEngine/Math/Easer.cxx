#include "Easer.hxx"
#include <cmath>


namespace Chunkee
{
	namespace Math
	{
		////////////////////////////////////////
		/// LINEAR
		////////////////////////////////////////
		float Ease::linear(const float& step)
		{
			return step;
		}

		////////////////////////////////////////
		/// SINE
		////////////////////////////////////////
		float Ease::inSine(const float& step)
		{
			return step == 1.0f ? step : 1 - cos((step * PI) / 2.f);
		}

		float Ease::outSine(const float& step)
		{
			return sin((step * PI) / 2.f);
		}

		float Ease::inOutSine(const float& step)
		{
			return -(cos(PI * step) - 1) / 2.f;
		}

		////////////////////////////////////////
		/// QUADRATIC
		////////////////////////////////////////
		float Ease::inQuad(const float& step)
		{
			return pow(step, 2.f);
		}

		float Ease::outQuad(const float& step)
		{
			return 1 - pow(1 - step, 2.f);
		}

		float Ease::inOutQuad(const float& step)
		{
			return step < .5f ? 2 * pow(step, 2.f) :
				1 - pow(-2 * step + 2, 2.f) / 2.f;
		}

		////////////////////////////////////////
		/// CUBIC
		////////////////////////////////////////
		float Ease::inCubic(const float& step)
		{
			return pow(step, 3.f);
		}

		float Ease::outCubic(const float& step)
		{
			return 1 - pow(1 - step, 3.f);
		}

		float Ease::inOutCubic(const float& step)
		{
			return step < .5f ? 4 * pow(step, 3.f) :
				1 - pow(-2 * step + 2, 3.f) / 2.f;
		}

		////////////////////////////////////////
		/// QUARTIC
		////////////////////////////////////////
		float Ease::inQuart(const float& step)
		{
			return pow(step, 4.f);
		}

		float Ease::outQuart(const float& step)
		{
			return 1 - pow(1 - step, 4.f);
		}

		float Ease::inOutQuart(const float& step)
		{
			return step < .5f ? 8 * pow(step, 4.f) :
				1 - pow(-2 * step + 2, 4.f) / 2.f;
		}

		////////////////////////////////////////
		/// QUINTIC
		////////////////////////////////////////
		float Ease::inQuint(const float& step)
		{
			return pow(step, 5.f);
		}

		float Ease::outQuint(const float& step)
		{
			return 1 - pow(1 - step, 5.f);
		}

		float Ease::inOutQuint(const float& step)
		{
			return step < .5f ? 16 * pow(step, 5.f) :
				1 - pow(-2 * step + 2, 5.f) / 2.f;
		}

		////////////////////////////////////////
		/// EXPONENTIAL
		////////////////////////////////////////
		float Ease::inExpo(const float& step)
		{
			return step == 0.f ? step : pow(2.f, 10 * step - 10);
		}


		float Ease::outExpo(const float& step)
		{
			return step == 1.f ? step : 1 - pow(2.f, -10 * step);
		}

		float Ease::inOutExpo(const float& step)
		{
			if (step == 0.f || step == 1.f)
				return step;
			else if (step < .5f)
				return pow(2.f, 20 * step - 10) / 2.f;
			else
				return (2 - pow(2.f, -20 * step + 10)) / 2.f;
		}

		////////////////////////////////////////
		/// CIRCULAR
		////////////////////////////////////////
		float Ease::inCirc(const float& step)
		{
			return 1 - sqrt(1 - pow(step, 2.f));
		}

		float Ease::outCirc(const float& step)
		{
			return sqrt(1 - pow(step - 1, 2.f));
		}

		float Ease::inOutCirc(const float& step)
		{
			return step < .5f ? (1 - sqrt(1 - pow(2 * step, 2.f))) / 2.f :
				(sqrt(1 - pow(-2 * step + 2, 2.f)) + 1) / 2.f;
		}

		////////////////////////////////////////
		/// BACK
		////////////////////////////////////////
		float Ease::inBack(const float& step)
		{
			return step == 1.f ? step :
				(FBE + 1) * pow(step, 3.f) - FBE * pow(step, 2.f);
		}

		float Ease::outBack(const float& step)
		{
			return step == 0.f ? step :
				1 + (FBE + 1) * pow(step - 1, 3.f) + FBE * pow(step - 1, 2.f);
		}

		float Ease::inOutBack(const float& step)
		{
			const float FBE2 = 2.5949095f;
			return step < .5f ? pow(2 * step, 2.f) * ((FBE2 + 1) * 2 * step - FBE2) / 2.f :
				(pow(2 * step - 2, 2.f) * ((FBE2 + 1) * (step * 2 - 2) + FBE2) + 2) / 2;
		}

		////////////////////////////////////////
		/// ELASTIC
		////////////////////////////////////////
		float Ease::inElastic(const float& step)
		{
			const float ANGLE = TAU / 3.f;
			return step == 0.f || step == 1.f ? step :
				-pow(2.f, 10 * step - 10) * sin((step * 10 - 10.75) * ANGLE);
		}

		float Ease::outElastic(const float& step)
		{
			const float ANGLE = TAU / 3.f;
			return step == 0.f or step == 1.f ? step :
				pow(2.f, -10 * step) * sin((step * 10 - 0.75) * ANGLE) + 1;
		}
		float Ease::inOutElastic(const float& step)
		{
			const float ANGLE = TAU / 4.5f;
			if (step == 0.f or step == 1.f)
				return step;
			else if (step < .5f)
				return -(pow(2.f, 20 * step - 10) * sin((20 * step - 11.125) * ANGLE)) / 2.f;
			else
				return pow(2, -20 * step + 10) * sin((20 * step - 11.125) * ANGLE) / 2.f + 1;
		}

		////////////////////////////////////////
		/// BOUNCE
		////////////////////////////////////////
		float Ease::inBounce(const float& step)
		{
			return 1 - Ease::outBounce(1 - step);
		}

		float Ease::outBounce(const float& step)
		{
			if (step < (1.f / 2.75f))
				return 7.5625f * pow(step, 2.f);
			else if (step < (2.f / 2.75f))
				return 7.5625f * pow(step - 1.5f / 2.75f, 2.f) + .75f;
			else if (step < (2.5f / 2.75f))
				return 7.5625f * pow(step - 2.25f / 2.75f, 2.f) + .9375f;
			else
				return 7.5625f * pow(step - 2.625f / 2.75f, 2.f) + .984375f;
		}

		float Ease::inOutBounce(const float& step)
		{
			return step < .5f ? (1 - Ease::outBounce(1 - 2 * step)) / 2.f :
				(1 + Ease::outBounce(2 * step - 1)) / 2.f;
		}
	}
}