#include "KineZ.h"

KineZ::Logger logger("Keisan");
#include <filesystem>
class Keisan : public KineZ::Application
{
private:

public:
	Keisan(int width, int height, const char* title)
		:Application(width, height, title)
	{


	}
	~Keisan() {

	}
};

void KineZ::CreateMeshes() {
	Model::AddModel(new KineZ::Model("res/mesh/backpack.obj"));
}

KineZ::ShaderPaths KineZ::SetShaderPaths() {
	return { "res/shaders/vertex.glsl", "res/shaders/fragment.glsl" };
}

KineZ::Application* KineZ::CreateApplication() {
	return new Keisan(1080, 720, "Keisan");
}
