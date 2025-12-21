#pragma once
#include <vector>

namespace Core
{
	class BasicObject;
	class ParticleSystem;

	class Emmiter
	{
	public:
		friend class ParticleSystem;

		Emmiter();
		virtual ~Emmiter();

		virtual void update(float dt);
		virtual void draw();
		virtual void start();
		virtual void finish();

	protected:
		bool m_is_complete;
		float m_time;
		float m_lifetime;
		Vector2 m_pos;
		Vector2 m_from_pos;
		Vector2 m_to_pos;
		BasicObject* m_render_target;

	private:
		void clearParams();
	};

	class ParticleSystem
	{
	public:
		bool m_is_started;
		float m_delay_between_create_time;
		float m_delay_between_create;
		float m_lifetime;
		float m_gravity;
		float m_speed_min;
		float m_speed_max;
		int m_emiters_count;
		Vector2 m_create_range;

		ParticleSystem();
		virtual ~ParticleSystem();

		virtual void draw();
		virtual void start();
		virtual void finish();

	protected:
		std::vector<Emmiter*> m_emiters;

		virtual void createEmmiter();
	private:
		void clearParams();
	};
}