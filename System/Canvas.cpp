#include "raylib.h"
#include "Canvas.h"
#include "../Core/App.h"

using namespace Core;

Canvas::Canvas()
{
	clearParams();
}
Canvas::~Canvas()
{
	clearParams();
}
// VIRTUAL FUNCS
void Canvas::init()
{
	m_camera.target.x = 0.f;
	m_camera.target.y = 0.f;
	m_camera.offset.x = getWidth() / 2.f;
	m_camera.offset.y = getHeight() / 2.f;
	m_camera.rotation = 0.f;
	m_camera.zoom = 1.f;
}
void Canvas::draw()
{
	BeginScissorMode((int)getX(), (int)getY(), (int)getWidth(), (int)getHeight());

	ClearBackground(DARKGRAY);

	BeginMode2D(m_camera);

	int gridSize = (int)getWidth();
	int step = 50;
	for (int i = -gridSize; i <= gridSize; i += step)
	{
		DrawLine(i, -gridSize, i, gridSize, GRAY);
		DrawLine(-gridSize, i, gridSize, i, GRAY);
	}

	DrawLine(0, -gridSize, 0, gridSize, GREEN);
	DrawLine(-gridSize, 0, gridSize, 0, RED);

	//for (const auto& p : particles)
	//	DrawCircleV(p.position, 3.0f, p.color);

	EndMode2D();

	DrawRectangleLinesEx(getRect(), 2, BLACK);
	DrawText("Simulation View", 10, 10, 20, RAYWHITE);

	EndScissorMode();
}
// FUNCS
void Canvas::clearParams()
{
}

