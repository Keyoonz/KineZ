#pragma once

#include "Core.h"
#include <vector>

namespace KineZ {


	class KINEZ_API UpdateItem
	{
	public:
		UpdateItem();
		virtual void update() = 0;
	};

}

