#pragma once
#include "../Core/Object.h"

namespace Core
{
	class Slider : public IObject
	{
	public:
		Slider();
		virtual ~Slider();

		virtual float getValue();
		virtual void init(float in_value);
		virtual void setMultiplier(float in_value);

		virtual TextObject* getTextObject();

		virtual void draw();

	protected:
		float m_multiplier;
		float m_value;
		float m_min_value;
		float m_max_value;
		BasicObject* m_knob;
		TextObject* m_text;

	private:
		void clearParams();
	};
}