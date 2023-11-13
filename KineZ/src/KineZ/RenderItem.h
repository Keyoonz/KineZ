#pragma once

#include "Core.h"
#include "Camera.h"


namespace KineZ {
	class KINEZ_API RenderItem
	{
	public:
		RenderItem();
		virtual void render(Camera camera);
	};
}