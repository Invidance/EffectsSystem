#include "Object.h"
#include "App.h"

using namespace Core;

IObject::IObject()
{
	clearParams();
}
IObject::~IObject()
{
	Application::m_instance->unregisterObject(this);
	clearParams();
}
// VIRTUAL FUNCS
Rectangle IObject::getRect()
{
	Rectangle rect = {m_x, m_y, m_width, m_height};
	return rect;
}
Color IObject::getColor()
{
	return m_color;
}
void IObject::setColor(Color in_color)
{
	m_color = in_color;
}
float IObject::getWidth()
{
	return m_width;
}
void IObject::setWidth(float in_value)
{
	m_width = in_value;
}
float IObject::getHeight()
{
	return m_height;
}
void IObject::setHeight(float in_value)
{
	m_height = in_value;
}
float IObject::getX()
{
	return m_x;
}
void IObject::setX(float in_value)
{
	m_x = in_value;
}
float IObject::getY()
{
	return m_y;
}
void IObject::setY(float in_value)
{
	m_y = in_value;
}
void IObject::destroy()
{
	delete this;
}
// FUNCS
void IObject::clearParams()
{
	m_x = 0.f;
	m_y = 0.f;
}

// ============ BaseObject ===========
BasicObject::BasicObject()
{
	clearParams();
}
BasicObject::~BasicObject()
{
	clearParams();
}
// VIRTUAL FUNCS
void BasicObject::draw()
{
	DrawRectangleRec(getRect(), getColor());
	if (m_border_size > 0)
		DrawRectangleLinesEx(getRect(), m_border_size, DARKGRAY);
}
void BasicObject::setBorderSize(float in_value)
{
	m_border_size = in_value;
}
// FUNCS
void BasicObject::clearParams()
{
	m_border_size = 0.f;
}

// ============ TextObject ===========
TextObject::TextObject()
{
	clearParams();
}
TextObject::~TextObject()
{
	clearParams();
}
// VIRTUAL FUNCS
const char* TextObject::getText()
{
	return m_text.c_str();
}
void TextObject::setText(const char* in_value)
{
	m_text = in_value;
}
int TextObject::getFontSize()
{
	return m_font_size;
}
void TextObject::setFontSize(int in_value)
{
	m_font_size = in_value;
}
void TextObject::draw()
{
	if (!m_text.empty())
	{
		DrawText(m_text.c_str(), (int)getX(), (int)getY(), m_font_size, getColor());
	}
}
// FUNCS
void TextObject::clearParams()
{
	m_font_size = 20;
	setColor(DARKGRAY);
}