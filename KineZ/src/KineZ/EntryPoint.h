#pragma once

#ifdef KZ_PLATFORM_WINDOWS

extern KineZ::Application* KineZ::CreateApplication();
extern KineZ::ShaderPaths KineZ::SetShaderPaths();
extern void KineZ::CreateMeshes();

int main() {
	KineZ::Application* app = KineZ::CreateApplication();
	app->ImplementMeshes = KineZ::CreateMeshes;
	app->shaderPaths = KineZ::SetShaderPaths();
	app->Run();
	delete app;
}


#else
	#error KineZ only supports Windows!
#endif
