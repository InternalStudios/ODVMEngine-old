#pragma once

#ifdef ODVM_PLATFORM_WINDOWS

extern ODVM::Application* ODVM::CreateApplication();

int main(int argc, char** argv)
{

	ODVM::Log::Init("Game");
	ODVM_CORE_INFO("Initilized Logs");

	ODVM_CORE_INFO("Welcome to the ODVM Engine!");
	auto app = ODVM::CreateApplication();
	app->run();
	delete app;

	return 1;
}
#else
#error Doesn't support platform

#endif // HAZEL_PLATFORM_WINDOWS
