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
		Vector2 m_velocity;
		BasicObject* m_render_target;
		ParticleSystem* m_ref_particle;

	private:
		void clearParams();
	};

	class ParticleSystem
	{
	public:
		bool m_is_started;
		int m_start_emiter_count;
		float m_timer;
		float m_spawn_rate;
		float m_lifetime;
		float m_random_force_prc;
		float m_vibration_dt;
		float m_vibration_speed;
		Vector2 m_gravity;
		Vector2 m_initial_force;
		Rectangle m_create_range;
		std::vector<Color> m_colors;

		ParticleSystem();
		virtual ~ParticleSystem();

		virtual void draw();
		virtual void start();
		virtual void finish();

	protected:
		std::vector<Emmiter*> m_emiters;
		std::vector<Emmiter*> m_emiters_pool;

		virtual void createEmmiter(bool in_is_simulated = false);
	private:
		void clearParams();
	};
}