#include "KineZ.h"

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

KineZ::Application* KineZ::CreateApplication() {
	return new Keisan(1080, 720, "Keisan");
}
