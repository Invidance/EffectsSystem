#pragma once
#include "raylib.h"
#include "Easing.h"
#include "../Core/Object.h"
#include <vector>

namespace Core
{
	class Sidebar;
	class Canvas : public IObject
	{
	public:
		Canvas();
		virtual ~Canvas();

		virtual void draw();
		virtual void init();

	protected:
		struct FlyData
		{
			FlyData();

			Vector2 m_pos;
			float m_scale;
		};

		double m_time;
		double m_duration;
		Easing::EASING_FUNC m_func;
		Easing::EASING_TYPE m_type;
		bool m_is_pressed;
		FlyData m_prev_data;
		FlyData m_next_data;

		Sidebar* m_sidebar;
		BasicObject* m_ctrl;
		TextObject* m_title;
		Camera2D m_camera;
		std::vector<TextObject> m_legends;

		void drawGrid();
		void update();
	private:
		void clearParams();
	};
}
