#include "stdafx.h"
#include "Sidebar.h"
#include "../Core/App.h"
#include "../Components/Slider.h"
#include "../Components/Dropdown.h"

using namespace Core;

Sidebar::Sidebar()
{
	clearParams();
}
Sidebar::~Sidebar()
{
	if (m_duration_slider != nullptr)
		delete m_duration_slider;

	if (m_title != nullptr)
		delete m_title;

	clearParams();
}
// VIRTUAL FUNCS
void Sidebar::getParameter(unsigned int in_key, double& out_value)
{
	auto res = m_parameters.find(in_key);
	if (res != m_parameters.end())
		out_value = res->second;
}
void Sidebar::updateParameter(unsigned int in_key, double out_value)
{
	m_parameters[in_key] = out_value;
}
void Sidebar::init()
{
	m_duration_slider = new Slider();
	m_duration_slider->setX((float)getSafeX());
	m_duration_slider->setY((float)getSafeY() + 50.f);
	m_duration_slider->setWidth(getWidth() - 2.f * m_margin);
	m_duration_slider->setHeight(12.f);
	m_duration_slider->setColor(LIME);
	m_duration_slider->setMultiplier(5.f);
	m_duration_slider->init(0.3f);

	m_duration_slider->setDesc("Duration");

	m_type_dropdown = new Dropdown();
	m_type_dropdown->setX((float)getSafeX());
	m_type_dropdown->setY((float)getSafeY() + 90.f);
	m_type_dropdown->setWidth((getWidth() * 0.5f) - 2.f * m_margin);
	m_type_dropdown->setHeight(22.f);
	m_type_dropdown->setColor(SKYBLUE);
	m_type_dropdown->init();

	m_type_dropdown->updateOption(Easing::LINEAR, "Linear");
	m_type_dropdown->updateOption(Easing::SINE, "Sine");
	m_type_dropdown->updateOption(Easing::QUINT, "Quint");
	m_type_dropdown->updateOption(Easing::QUART, "Quart");
	m_type_dropdown->updateOption(Easing::QUAD, "Quad");
	m_type_dropdown->updateOption(Easing::EXPO, "Expo");
	m_type_dropdown->updateOption(Easing::ELASTIC, "Elastic");
	m_type_dropdown->updateOption(Easing::CUBIC, "Cubic");
	m_type_dropdown->updateOption(Easing::CIRC, "Circ");
	m_type_dropdown->updateOption(Easing::BOUNCE, "Bounce");
	m_type_dropdown->updateOption(Easing::BACK, "Back");

	m_type_dropdown->setDesc("Tween type");

	m_func_dropdown = new Dropdown();
	m_func_dropdown->setX((float)getSafeX() + (getWidth() * 0.5f));
	m_func_dropdown->setY((float)getSafeY() + 90.f);
	m_func_dropdown->setWidth((getWidth() * 0.5f) - 2.f * m_margin);
	m_func_dropdown->setHeight(22.f);
	m_func_dropdown->setColor(SKYBLUE);
	m_func_dropdown->init();

	m_func_dropdown->updateOption(Easing::FUNC_IN, "Func in");
	m_func_dropdown->updateOption(Easing::FUNC_OUT, "Func out");
	m_func_dropdown->updateOption(Easing::FUNC_IN_OUT, "Func in-out");

	m_func_dropdown->setDesc("Tween func");

	m_title = new TextObject();
	m_title->setX((float)getSafeX());
	m_title->setY((float)getSafeY());
	m_title->setText("Settings");
	m_title->setColor(DARKGRAY);
	m_title->setFontSize(20);
	m_title->setWidth(getWidth() - 2.f * m_margin);
}
void Sidebar::draw()
{
	DrawRectangleRec(getRect(), LIGHTGRAY);
	DrawRectangleLinesEx(getRect(), 1, DARKGRAY);

	if (m_title != nullptr)
		m_title->draw();

	if (m_duration_slider != nullptr)
	{
		m_duration_slider->draw();
		updateParameter(CONSTS::PARAMETER_DURATION, double(m_duration_slider->getValue() * m_duration_slider->getMultiplier()));
	}

	if (m_type_dropdown != nullptr)
	{
		m_type_dropdown->draw();
		updateParameter(CONSTS::PARAMETER_TWEEN_TYPE, Easing::EASING_TYPE(m_type_dropdown->getOption()));
	}

	if (m_func_dropdown != nullptr)
	{
		m_func_dropdown->draw();
		updateParameter(CONSTS::PARAMETER_TWEEN_FUNC, Easing::EASING_FUNC(m_func_dropdown->getOption()));
	}
}
Vector2 Sidebar::getSafePos()
{
	return { (float)getSafeX(), (float)getSafeY() };
}
int Sidebar::getSafeX()
{
	return int(getX() + m_margin);
}
int Sidebar::getSafeY()
{
	return int(getY() + m_margin);
}
// FUNCS
void Sidebar::clearParams()
{
	m_margin = 20.f;
	m_duration_slider = nullptr;
}

