#pragma once

#ifdef SPN_PLATFORM_WINDOWS

extern Siphon::Application* Siphon::CreateApplication();

int main(int argc, char** argv)
{
	Siphon::Log::Init();

	auto app = Siphon::CreateApplication();
	app->Run();
	delete app;
}

#endif
