#include "UpdateItem.h"

//for KineZ Only
std::vector<KineZ::UpdateItem*> k_updateItems;

#include <iostream>

KineZ::UpdateItem::UpdateItem()
{
	k_updateItems.emplace_back(this);
}
