#include "Sidebar.h"
#include "../Core/App.h"
#include "../Components/Slider.h"

using namespace Core;

Sidebar::Sidebar()
{
	clearParams();
}
Sidebar::~Sidebar()
{
	if (m_slider != nullptr)
		delete m_slider;

	if (m_title != nullptr)
		delete m_title;

	clearParams();
}
// VIRTUAL FUNCS
void Sidebar::init()
{
	m_slider = new Slider();
	m_slider->setX(getSafeX());
	m_slider->setY(getSafeY() + 50.f);
	m_slider->setWidth(getWidth() - 2.f * m_margin);
	m_slider->setHeight(12.f);
	m_slider->setColor(LIME);
	m_slider->setMultiplier(5.f);
	m_slider->init(0.f);

	m_title = new TextObject();
	m_title->setX(getSafeX());
	m_title->setY(getSafeY());
	m_title->setText("SETTINGS");
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

	if (m_slider != nullptr)
		m_slider->draw();
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
	m_slider = nullptr;
}

