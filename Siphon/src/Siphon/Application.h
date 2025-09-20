#pragma once

#include "Core.h"

namespace Siphon {
	class SIPHON_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}