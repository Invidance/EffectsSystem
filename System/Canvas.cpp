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
	if (m_title != nullptr)
		delete m_title;

	if (m_ctrl != nullptr)
		delete m_ctrl;

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

	m_title = new TextObject();
	m_title->setText("Simulation View");
	m_title->setX(getX() + 10.f);
	m_title->setY(getY() + 10.f);
	m_title->setColor(RAYWHITE);
	m_title->setFontSize(20);

	m_ctrl = new BasicObject();
	m_ctrl->setRadius(15.f);
	m_ctrl->setColor(MAGENTA);
}
void Canvas::draw()
{
	BeginScissorMode((int)getX(), (int)getY(), (int)getWidth(), (int)getHeight());

	ClearBackground(DARKGRAY);

	BeginMode2D(m_camera);

	drawGrid();

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		Vector2 mousePos = GetMousePosition();
		if (CheckCollisionPointRec(mousePos, getRect()))
		{
			Vector2 normalized = { mousePos.x - getX() - getWidth() / 2.f, mousePos.y - getY() - getHeight() / 2.f };

			if (m_ctrl != nullptr)
			{
				m_ctrl->setX(normalized.x);
				m_ctrl->setY(normalized.y);
			}
		}
	}

	if (m_ctrl != nullptr)
		m_ctrl->draw();

	DrawSplineBezierCubic()

	EndMode2D();

	DrawRectangleLinesEx(getRect(), 2, BLACK);
	
	if (m_title != nullptr)
		m_title->draw();

	EndScissorMode();
}
void Canvas::drawGrid()
{
	int step = 50;
	int gridSize = (int)(getWidth() / step) * step;
	
	for (int i = -gridSize; i <= gridSize; i += step)
	{
		if(i == 0)
			continue;

		DrawLine(i, -gridSize, i, gridSize, GRAY);
		DrawLine(-gridSize, i, gridSize, i, GRAY);
	}

	DrawLine(0, -gridSize, 0, gridSize, GREEN);
	DrawLine(-gridSize, 0, gridSize, 0, RED);
}
// FUNCS
void Canvas::clearParams()
{
	m_title = nullptr;
	m_ctrl = nullptr;
}

