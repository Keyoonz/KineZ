#include "DoubleLinkedList.h"

namespace KineZ {
	template<typename T>
	DoubleLinkedList<T>::DoubleLinkedList()
		: m_head(nullptr), m_tail(nullptr), m_size(0)
	{

	}

	template<typename T>
	DoubleLinkedList<T>::~DoubleLinkedList()
	{
		clear();
	}

	template<typename T>
	void DoubleLinkedList<T>::push_back(T data)
	{
		Node* node = new Node(data);



		if (m_head == nullptr)
		{
			m_head = node;
			m_tail = node;
		}
		else
		{
			m_tail->next = node;
			node->prev = m_tail;
			m_tail = node;
		}
		m_size++;
	}

	template<typename T>
	void DoubleLinkedList<T>::push_front(T data)
	{
		Node* node = new Node(data);

		if (m_head == nullptr)
		{
			m_head = node;
			m_tail = node;
		}
		else
		{
			m_head->prev = node;
			node->next = m_head;
			m_head = node;
		}
		m_size++;
	}

	template<typename T>
	void DoubleLinkedList<T>::pop_back()
	{
		if (m_tail == nullptr)
			return;

		Node* node = m_tail;
		m_tail = m_tail->prev;
		m_tail->next = nullptr;
		delete node;
		m_size--;
	}

	template<typename T>
	void DoubleLinkedList<T>::pop_front()
	{
		if (m_head == nullptr)
			return;

		Node* node = m_head;
		m_head = m_head->next;
		m_head->prev = nullptr;
		delete node;
		m_size--;
	}

	template<typename T>
	void DoubleLinkedList<T>::insert(T data, int index)
	{
		if (index < 0 || index > m_size)
			return;

		if (index == 0)
		{
			push_front(data);
			return;
		}

		if (index == m_size)
		{
			push_back(data);
			return;
		}

		Node* node = new Node(data);
		Node* current = m_head;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->next;
		}

		node->next = current->next;
		node->prev = current;
		current->next->prev = node;
		current->next = node;
		m_size++;
	}

	template<typename T>
	void DoubleLinkedList<T>::remove(int index)
	{
		if (index < 0 || index >= m_size)
			return;

		if (index == 0)
		{
			pop_front();
			return;
		}

		if (index == m_size - 1)
		{
			pop_back();
			return;
		}

		Node* current = m_head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}

		current->prev->next = current->next;
		current->next->prev = current->prev;
		delete current;
		m_size--;
	}

	template<typename T>
	void DoubleLinkedList<T>::clear()
	{
		while (m_head != nullptr)
		{
			Node* node = m_head;
			m_head = m_head->next;
			delete node;
		}
		m_size = 0;
	}

	template<typename T>
	int DoubleLinkedList<T>::size()
	{
		return m_size;
	}

	template<typename T>
	T DoubleLinkedList<T>::operator[](const int index)
	{
		if (index < 0 || index >= m_size)
			return T();

		Node* current = m_head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}

		return current->data;
	}
}