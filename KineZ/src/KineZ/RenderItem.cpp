#include "RenderItem.h"

//For KineZ Only
std::vector<KineZ::RenderItem*> k_renderItems;

#include <iostream>

KineZ::RenderItem::RenderItem()
{
	k_renderItems.emplace_back(this);
}
