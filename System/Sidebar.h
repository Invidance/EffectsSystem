#pragma once
#include "raylib.h"
#include "../Core/Object.h"

namespace Core
{
	class Slider;
	class Sidebar : public IObject
	{
	public:
		Sidebar();
		virtual ~Sidebar();

		virtual void draw();
		virtual void init();

	protected:
		float m_margin;
		TextObject* m_title;
		Slider* m_slider;

		virtual Vector2 getSafePos();
		virtual int getSafeX();
		virtual int getSafeY();

	private:
		void clearParams();
	};
}
