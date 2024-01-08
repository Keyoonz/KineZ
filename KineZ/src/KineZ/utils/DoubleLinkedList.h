#pragma once

#include "../Model.h"
#include "../UpdateItem.h"

class Model {

};

namespace KineZ {
	template<class T>
	class DoubleLinkedList {

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

	template class DoubleLinkedList<UpdateItem*>;
	template class DoubleLinkedList<Model*>;
}