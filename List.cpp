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
		Node* temp = new Node;
		Node* temp_copy = copy.head;
		head = temp;
		while (temp_copy != NULL)
		{
			temp->data = temp_copy->data;
			temp_copy = temp_copy->next;
			temp->next=new Node;
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
	Node* temp,*temp_next;
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
		Node* temp = new Node;
		Node* temp_copy = copy.head;
		head = temp;
		while (temp_copy != NULL)
		{
			temp->data = temp_copy->data;
			temp_copy = temp_copy->next;
			temp->next = new Node;
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
int LinkedList<T>::size()
{
	return size;
}

template<class T>
ErrorCode LinkedList<T>::insert_back(const T data)
{
	int i;
	Node* temp;
	temp = head;
	for (i = 0; i < size; i++)
	{
		temp = temp->next;
	}
	temp->next = new Node;
	if (temp->next == NULL)
	{
		return overflow;
	}
	else
	{
		temp->next->data = data;
		temp->next->next = NULL;
		return success;
	}
}

template<class T>
ErrorCode 