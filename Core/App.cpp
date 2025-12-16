#include "stdafx.h"
#include "App.h"
#include "Object.h"
#include "../System/Canvas.h"

using namespace Core;

Application* Application::m_instance = nullptr;
Application::Application()
{
	m_instance = this;
	clearParams();
}
Application::~Application()
{
	m_active = false;
	if (m_instance == this)
		m_instance = nullptr;
	
	for (auto v : m_objects)
		v->destroy();
	
	m_objects.clear();

	clearParams();
}
// VIRTUAL FUNCS
void Application::draw()
{
	for (size_t i = 0; i < m_objects.size(); i++)
	{
		m_objects[i]->draw();
	}
}
void Application::registerObject(IObject* in_obj)
{
	m_objects.push_back(in_obj);
}
void Application::unregisterObject(IObject* in_obj)
{
	if (!m_active)
		return;

	auto it = m_objects.begin();
	for (; it != m_objects.end(); ++it)
	{
		if (*it == in_obj)
		{
			m_objects.erase(it);
			return;
		}
	}
}
void Application::init()
{
	Canvas* canvas = new Canvas();
	registerObject(canvas);
	canvas->setWidth(CONSTS::SCREEN_WIDTH * 0.7f);
	canvas->setHeight((float)CONSTS::SCREEN_HEIGHT);
	canvas->init();
}
// FUNCS
void Application::clearParams()
{
	m_active = true;
}