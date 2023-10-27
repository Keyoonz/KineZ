#pragma once

#ifdef KZ_PLATFORM_WINDOWS

extern KineZ::Application* KineZ::CreateApplication();

int main() {
	auto app = KineZ::CreateApplication();
	app->Run();
	delete app;
}


#else
	#error KineZ only supports Windows!
#endif
