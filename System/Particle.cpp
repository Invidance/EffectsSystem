#include "stdafx.h"
#include "Particle.h"
#include "Object.h"

using namespace Core;

// ============ Emmiter ===========
Emmiter::Emmiter()
{
	clearParams();
}
Emmiter::~Emmiter()
{
	clearParams();
}
// VIRTUAL FUNCS
void Emmiter::update(float dt)
{
	if (m_lifetime <= 0.001f)
		return;

	m_time += dt;

	float t = m_time / m_lifetime;
	Easing::interpolate(m_from_pos, m_to_pos, m_pos, t);
	
	if (m_render_target != nullptr)
	{
		m_render_target->setX(m_pos.x);
		m_render_target->setY(m_pos.y);
	}

	if (t >= 1.f)
		finish();
}
void Emmiter::draw()
{
	
}
void Emmiter::start()
{
	m_time = 0.f;
	if (m_render_target == nullptr)
		m_render_target = new BasicObject();

	m_render_target->setX(m_from_pos.x);
	m_render_target->setY(m_from_pos.y);
}
void Emmiter::finish()
{
	m_is_complete = true;
}
// FUNCS
void Emmiter::clearParams()
{
	m_is_complete = false;
	m_render_target = nullptr;
	m_time = 0.f;
	m_lifetime = 0.f;
	m_pos.x = 0.f;
	m_pos.y = 0.f;
	m_from_pos.x = 0.f;
	m_from_pos.y = 0.f;
	m_to_pos.x = 0.f;
	m_to_pos.y = 0.f;
}

// ============ ParticleSystem ===========
ParticleSystem::ParticleSystem()
{
	clearParams();
}
ParticleSystem::~ParticleSystem()
{
	clearParams();
}
// VIRTUAL FUNCS
void ParticleSystem::draw()
{
	if (!m_is_started)
		return;

	float dt = GetFrameTime();
	auto it = m_emiters.begin();
	for (; it != m_emiters.end(); ++it)
	{
		(*it)->update(dt);
		(*it)->draw();
	}

	if (m_delay_between_create_time > 0.f)
	{
		m_delay_between_create_time -= dt;
		createEmmiter();
	}
}
void ParticleSystem::start()
{
	m_is_started = true;
	createEmmiter();
}
void ParticleSystem::finish()
{

}
void ParticleSystem::createEmmiter()
{
	m_delay_between_create_time = m_delay_between_create;

	if (m_emiters.size() <= m_emiters_count)
	{
		Emmiter* emiter = new Emmiter();
		emiter->m_lifetime = m_lifetime;
		emiter->m_from_pos.x = m_create_range.x;
		emiter->m_from_pos.y = m_create_range.y;
		emiter->m_to_pos.x = m_create_range.x;
		emiter->m_to_pos.y = CONSTS::SCREEN_HEIGHT;
		m_emiters.push_back(emiter);
	}
}
// FUNCS
void ParticleSystem::clearParams()
{
	m_is_started = false;
	m_delay_between_create_time = 0.f;
	m_delay_between_create = 1.f;
	m_lifetime = 5.f;
	m_gravity = 0.f;
	m_speed_min = 0.f;
	m_speed_max = 0.f;
	m_create_range.x = 0.f;
	m_create_range.y = 0.f;
	m_emiters_count = 20;
}