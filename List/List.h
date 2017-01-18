#include <iostream>

enum ErrorCode
{
	success,
	underflow,
	overflow,
	out_of_subscript_range
};

template<typename T>
struct Node
{
	T data;
	Node<T>* next;
};

template<class T>
class LinkedList
{
public:
	LinkedList();//默认构造函数
	LinkedList(const LinkedList& copy);//复制构造函数
	~LinkedList();//析构函数
	void operator=(const LinkedList<T> &copy);//操作符重载
	bool empty();//判断链表是否为空
	int list_size();//计算链表的长度
	ErrorCode insert_back(const T data);//在链表的末尾插上一个值
	ErrorCode insert(int position, const T data);//在链表某个特定的位置插入一个值
	ErrorCode remove_back();//删除链表末尾的值
	ErrorCode remove(int position);//删除链表某个特定位置上的值
	ErrorCode retrieve(int position, T& data);//获取链表某个特定位置上的值
	ErrorCode replace(int position, T data);//将链表上某个特定位置的值更换为data
	Node<T>* reverse();//将链表倒置
	void traverse(void(*visit)(int));
	void clear();//清空链表
protected:
	int size;
	Node<T>* head;
};



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
		Node<T>* temp = new Node<T>;
		Node<T>* temp_copy = copy.head;
		head = temp;
		temp->data = temp_copy->data;
		while (temp_copy->next != NULL)
		{
			temp_copy = temp_copy->next;
			temp->next = new Node<T>;
			temp = temp->next;
			temp->data = temp_copy->data;
		}
		temp->next= NULL;
		size = copy.size;
	}
}


template<class T>
LinkedList<T>::~LinkedList()
{
	clear();
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
		Node<T>* temp = new Node<T>;
		Node<T>* temp_copy = copy.head;
		head = temp;
		temp->data = temp_copy->data;
		while (temp_copy->next != NULL)
		{
			temp_copy = temp_copy->next;
			temp->next = new Node<T>;
			temp = temp->next;
			temp->data = temp_copy->data;
		}
		temp->next = NULL;
		size = copy.size;
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
	if (size == 0)
	{
		head = new Node<T>;
		if (head == NULL)
		{
			return overflow;
		}
		else
		{
			head->data = data;
			head->next = NULL;
			size++;
			return success;
		}
	}
	else
	{
		int i;
		Node<T>* temp;
		temp = head;
		for (i = 0; i < size - 1; i++)
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
}

template<class T>
ErrorCode LinkedList<T>::insert(int position,const T data)
{
	int i;
	Node<T>* temp, *new_node;
	temp = head;
	new_node = new Node<T>;
	new_node->data = data;
	if (empty())
	{
		return underflow;
	}
	if (position < 0 || position > size)
	{
		return out_of_subscript_range;
	}
	else if (position == 0)
	{
		new_node->next = head;
		head = new_node;
		size++;
		return success;
	}
	else if (position == size)
	{
		return insert_back(data);
	}
	else
	{
		for (i = 0; i < position - 1; i++)
		{
			temp = temp->next;
		}
		Node<T>* temp_next = temp->next;
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
	if (size == 1)
	{
		delete head;
		head = NULL;
		size--;
		return success;
	}
	else
	{
		int i;
		Node<T>* temp = head;
		for (i = 0; i < size - 2; i++)
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
		return out_of_subscript_range;
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
		return out_of_subscript_range;
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
ErrorCode LinkedList<T>::replace(int position, T data)
{
	int i;
	Node<T>* temp;
	if (empty())
	{
		return underflow;
	}
	else if (position < 0 || position >= size)
	{
		return out_of_subscript_range;
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
		Node<T>* temp = new Node<T>;
		Node<T>* del_node, *temp_next, *head_next;
		temp->next = head;
		head_next = head->next;
		head->next = NULL;
		head = head_next;
		while (head!=NULL)
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




