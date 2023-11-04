#pragma once

#include "Core.h"
#include <vector>


namespace KineZ {
	class KINEZ_API RenderItem
	{
	public:
		RenderItem();
		virtual void render() = 0;
	};
}