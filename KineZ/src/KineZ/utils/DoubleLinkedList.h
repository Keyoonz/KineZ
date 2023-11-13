#pragma once

#include "../Core.h"
#include "../RenderItem.h"
#include "../UpdateItem.h"

namespace KineZ {
	template<typename T>
	class KINEZ_API DoubleLinkedList {

	public:
		struct Node {
			T data;
			Node* next;
			Node* prev;

			inline Node(T data) {
				this->data = data;
				this->next = nullptr;
				this->prev = nullptr;
			}
		};
		DoubleLinkedList();
		~DoubleLinkedList();

		void push_back(T data);
		void push_front(T data);
		void pop_back();
		void pop_front();
		void insert(T data, int index);
		void remove(int index);
		void clear();
		int size();
		T operator[](const int index);
	private:
		Node* m_head;
		Node* m_tail;
		int m_size;
	};

	template class KINEZ_API DoubleLinkedList<RenderItem*>;
	template class KINEZ_API DoubleLinkedList<UpdateItem*>;
}