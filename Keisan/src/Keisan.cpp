#include "KineZ.h"

KineZ::Logger logger("Keisan");

class Card : KineZ::UpdateItem, KineZ::RenderItem
{
public:
	void update()
	{
		logger.Info("Updating Card");
	};
	void render(KineZ::Camera camera)
	{
		logger.Info("Rendering Card");
	}
};

class Keisan : public KineZ::Application
{
private:
	Card exempleCard;
public:
	Keisan(int width, int height, const char* title)
		:Application(width, height, title), exempleCard()
	{


	}
	~Keisan() {

	}
};

KineZ::Application* KineZ::CreateApplication() {
	return new Keisan(1080, 720, "Keisan");
}
