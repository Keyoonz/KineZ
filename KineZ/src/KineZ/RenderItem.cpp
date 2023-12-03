#include "RenderItem.h"


#include "utils/DoubleLinkedList.h"
//For KineZ Only
KineZ::DoubleLinkedList<KineZ::RenderItem*> k_renderItems;

#include <iostream>

KineZ::RenderItem::RenderItem()
{
	k_renderItems.push_back(this);
}

void KineZ::RenderItem::render()
{
}
