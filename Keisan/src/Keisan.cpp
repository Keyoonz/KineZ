#include "KineZ.h"

KineZ::Logger logger("Keisan");

class Cube : KineZ::RenderItem {
public:
	Cube()
		:RenderItem()
	{
		logger.Info("s");
	}
	~Cube()
	{
		
	}
};

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

void KineZ::CreateRenderItems() {
	RenderItem::addRenderItems(new RenderItem());
}

KineZ::ShaderPaths KineZ::SetShaderPaths() {
	return { "res/shaders/vertex.glsl", "res/shaders/fragment.glsl" };
}

KineZ::Application* KineZ::CreateApplication() {
	return new Keisan(1080, 720, "Keisan");
}
