#pragma once
#include "raylib.h"
#include "../Core/Object.h"

namespace Core
{
	class Canvas : public IObject
	{
	public:
		Canvas();
		virtual ~Canvas();

		virtual void draw();
		virtual void init();

	protected:
		Camera2D m_camera;

	private:
		void clearParams();
	};
}
