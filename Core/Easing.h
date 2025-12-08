#pragma once

namespace Effects
{
	class Easing
	{
	public:
		typedef enum
		{
			LINEAR = 0,
			SINE = 1,
			QUAD = 2,
			CIRC = 3
		}EASING_TYPE;

		typedef enum
		{
			FUNC_IN = 0,
			FUNC_OUT = 1,
			FUNC_IN_OUT = 2,
		}EASING_FUNC;

		static float linear(float in_t);
		static float sineIn(float in_t);
		static float sineOut(float in_t);
		static float sineInOut(float in_t);
	};
}