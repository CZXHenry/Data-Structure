#include <iostream>

enum ErrorCode
{
	success,
	underflow,
	overflow
};

template<typename T>
struct Node
{
	T data;
	Node* next;
};

template<class T>
class LinkedList
{
public:
	LinkedList();//Ĭ�Ϲ��캯��
	LinkedList(const List&);//��ֵ���캯��
	~LinkedList();//��������
	void operator=(const LinkedList<T> &copy)//����������
	bool empty();//�ж������Ƿ�Ϊ��
	int size();//��������ĳ���
	ErrorCode insert_back(const T data);//�������ĩβ����һ��ֵ
	ErrorCode insert(const T data, int position);//������ĳ���ض���λ�ò���һ��ֵ
	ErrorCode remove_back();//ɾ������ĩβ��ֵ
	ErrorCode remove(int position);//ɾ������ĳ���ض�λ���ϵ�ֵ
	ErrorCode retrieve(int position, T& data);//��ȡ����ĳ���ض�λ���ϵ�ֵ
	ErrorCode replace(int position, T& data);//��������ĳ���ض�λ�õ�ֵ����Ϊdata
	Node* traverse();//��������
	void clear()//�������
protected:
	int size;
	Node* head;
};