#pragma once
#include "raylib.h"
#include "../Core/Object.h"
#include <map>

namespace Core
{
	class Slider;
	class Dropdown;
	class Sidebar : public IObject
	{
	public:
		Sidebar();
		virtual ~Sidebar();

		virtual void draw();
		virtual void init();

		virtual void getParameter(unsigned int, double& out_value);
		virtual void updateParameter(unsigned int, double out_value);

	protected:
		float m_margin;
		TextObject* m_title;
		Slider* m_duration_slider;
		Dropdown* m_type_dropdown;
		Dropdown* m_func_dropdown;
		std::map<unsigned int, double> m_parameters;

		virtual Vector2 getSafePos();
		virtual int getSafeX();
		virtual int getSafeY();

	private:
		void clearParams();
	};
}
