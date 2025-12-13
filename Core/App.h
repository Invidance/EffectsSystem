#pragma once
#include <vector>

namespace Core
{
	class IObject;
	class Application
	{
	public:
		Application();
		virtual ~Application();

		static Application* m_instance;

		virtual void draw();

		virtual void registerObject(IObject* in_obj);
		virtual void unregisterObject(IObject* in_obj);
	protected:
		bool m_active;
		std::vector<IObject*> m_objects;

	private:
		void clearParams();
	};
}