#include "raylib.h"
#include "Slider.h"
#include "../Core/App.h"

using namespace Core;

Slider::Slider()
{
	clearParams();
}
Slider::~Slider()
{
	clearParams();
}
// VIRTUAL FUNCS
float Slider::getValue()
{
	return m_value;
}
void Slider::init(float in_value)
{
	m_value = in_value;

	setWidth(200.f);
	setHeight(16.f);
	setColor(LIME);
	m_knob = new BasicObject();
	Application::m_instance->unregisterObject(m_knob);
	m_knob->setWidth(12.f);
	m_knob->setHeight(20.f);
	m_knob->setColor(ORANGE);

	m_text = new TextObject();
	Application::m_instance->unregisterObject(m_text);
	m_text->setX(getX() + getWidth() * 0.5f);
	m_text->setY(getY() - 20.f);
}
void Slider::draw()
{
	bool valueChanged = false;
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		Vector2 mousePos = GetMousePosition();
		if (CheckCollisionPointRec(mousePos, getRect()))
		{
			float normalized = (mousePos.x - getX()) / getWidth();

			if (normalized < 0.0f) normalized = 0.0f;
			if (normalized > 1.0f) normalized = 1.0f;

			m_value = m_min_value + normalized * (m_max_value - m_min_value);
			valueChanged = true;
		}
	}

	DrawRectangleRec(getRect(), getColor());

	if (m_knob != nullptr)
	{
		m_knob->setX(getX() + (getWidth() * m_value) - m_knob->getWidth() * 0.5f);
		m_knob->setY(getY() + getHeight() * 0.5f - m_knob->getHeight() * 0.5f);

		m_knob->draw();
	}

	if (m_text != nullptr)
	{
		m_text->setX(getX() + getWidth() * 0.5f);
		m_text->setY(getY() - 20.f);

		m_text->setText(std::to_string(m_value).c_str());
		m_text->draw();
	}
}
// FUNCS
void Slider::clearParams()
{
	m_value = 0.f;
	m_min_value = 0.f;
	m_max_value = 1.f;
	m_knob = nullptr;
	m_text = nullptr;
}

