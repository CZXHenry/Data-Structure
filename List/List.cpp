#include <iostream>
#include "List.h"

template<class T>
LinkedList<T>::LinkedList()
{
	size = 0;
	head = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList& copy)
{
	if (copy.size == 0)
	{
		size = 0;
		head = NULL;
	}
	else
	{
		int i;
		Node<T>* temp = new Node<T>;
		Node<T>* temp_copy = copy.head;
		head = temp;
		while (temp_copy != NULL)
		{
			temp->data = temp_copy->data;
			temp_copy = temp_copy->next;
			temp->next=new Node<T>;
			temp = temp->next;
		}
		temp = NULL;
		size = copy->size;
	}
}


template<class T>
LinkedList<T>::~LinkedList()
{
	int i;
	Node<T>* temp,*temp_next;
	temp = head;
	for (i = 0; i < size; i++)
	{
		temp_next = temp->next;
		delete temp;
		temp = temp_next;
	}
}

template<class T>
void LinkedList<T>::operator=(const LinkedList<T>& copy)
{
	if (copy.size == 0)
	{
		size = 0;
		head = NULL;
	}
	else
	{
		int i;
		Node<T>* temp = new Node<T>;
		Node<T>* temp_copy = copy.head;
		head = temp;
		while (temp_copy != NULL)
		{
			temp->data = temp_copy->data;
			temp_copy = temp_copy->next;
			temp->next = new Node<T>;
			temp = temp->next;
		}
		temp = NULL;
		size = copy->size;
	}
}

template<class T>
bool LinkedList<T>::empty()
{
	return size == 0;
}

template<class T>
int LinkedList<T>::list_size()
{
	return size;
}

template<class T>
ErrorCode LinkedList<T>::insert_back(const T data)
{
	int i;
	Node<T>* temp;
	temp = head;
	for (i = 0; i < size; i++)
	{
		temp = temp->next;
	}
	temp->next = new Node<T>;
	if (temp->next == NULL)
	{
		return overflow;
	}
	else
	{
		temp->next->data = data;
		temp->next->next = NULL;
		size++;
		return success;
	}
}

template<class T>
ErrorCode LinkedList<T>::insert(const T data, int position)
{
	int i;
	Node<T>* temp,*new_node;
	temp = head;
	new_node = new Node<T>;
	new_node->data = data;
	if (empty())
	{
		return underflow;
	}
	if (position < 0 || position >= size)
	{
		return out_of_range;
	}
	else if (position == 0)
	{
		new_node->next = head;
		head = new_node;
	}
	else
	{
		for (i = 0; i < position - 1; i++)
		{
			temp = temp->next;
		}
		Node<T>* temp_next=temp->next;
		temp->next = new_node;
		new_node->next = temp_next;
		size++;
		return success;
	}
}

template<class T>
ErrorCode LinkedList<T>::remove_back()
{
	if (empty())
	{
		return underflow;
	}
	else
	{
		int i;
		Node<T>* temp = head;
		for (i = 0; i < size - 1; i++)
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;
		size--;
		return success;
	}
}

template<class T>
ErrorCode LinkedList<T>::remove(int position)
{
	int i;
	Node<T>* temp;
	temp = head;
	if (empty())
	{
		return underflow;
	}
	if (position < 0 || position >= size)
	{
		return out_of_range;
	}
	else if (position == 0)
	{
		head = head->next;
		size--;
		delete temp;
		return success;
	}
	else
	{
		for (i = 0; i < position - 1; i++)
		{
			temp = temp->next;
		}
		Node<T>* temp_next = temp->next;
		temp->next = temp_next->next;
		delete temp_next;
		size--;
		return success;
	}
}

template<class T>
ErrorCode LinkedList<T>::retrieve(int position, T& data)
{
	int i;
	Node<T>* temp = head;
	if (empty())
	{
		return underflow;
	}
	if (position < 0 || position >= size)
	{
		return out_of_range;
	}
	else
	{
		for (i = 0; i < position; i++)
		{
			temp = temp->next;
		}
		data = temp->data;
		return success;
	}
}

template<class T>
ErrorCode LinkedList<T>::replace(int position, T& data)
{
	int i;
	Node<T>* temp;
	if (empty())
	{
		return underflow;
	}
	else if (position < 0 || position >= size)
	{
		return out_of_range;
	}
	else
	{
		temp = head;
		for (i = 0; i < position; i++)
		{
			temp = temp->next;
		}
		temp->data = data;
		return success;
	}
}

template<class T>
Node<T>* LinkedList<T>::reverse()
{
	if (empty())
	{
		return head;
	}
	else
	{
		Node<T>* temp=new Node<T>;
		Node<T>* del_node,*temp_next,*head_next;
		temp->next = new Node<T>;
		temp->next= head;
		head = head->next;
		while (empty())
		{
			temp_next = temp->next;
			temp->next = head;
			head_next = head->next;
			head->next = temp_next;
			head = head_next;
		}
		head = temp->next;
		return head;
	}
}

template<class T>
void LinkedList<T>::traverse(void(*visit)(int))
{
	Node<T>* temp = head;
	while (temp != NULL)
	{
		visit(temp->data);
		temp = temp->next;
	}
}

template<class T>
void LinkedList<T>::clear()
{
	while (!empty())
	{
		remove_back();
	}
}