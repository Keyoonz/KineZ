#include "UpdateItem.h"

#include "utils/DoubleLinkedList.h"
//For KineZ Only
KineZ::DoubleLinkedList<KineZ::UpdateItem*> k_updateItems;



KineZ::UpdateItem::UpdateItem()
{
	k_updateItems.push_back(this);
}

void KineZ::UpdateItem::update()
{
}
