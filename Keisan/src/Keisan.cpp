#include "KineZ.h"

class Keisan : public KineZ::Application
{
private:
	
public:
	Keisan() {
	
	}
	~Keisan() {

	}
};

KineZ::Application* KineZ::CreateApplication() {
	return new Keisan();
}
