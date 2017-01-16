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
	LinkedList();//默认构造函数
	LinkedList(const List&);//赋值构造函数
	~LinkedList();//析构函数
	void operator=(const LinkedList<T> &copy)//操作符重载
	bool empty();//判断链表是否为空
	int size();//计算链表的长度
	ErrorCode insert_back(const T data);//在链表的末尾插上一个值
	ErrorCode insert(const T data, int position);//在链表某个特定的位置插入一个值
	ErrorCode remove_back();//删除链表末尾的值
	ErrorCode remove(int position);//删除链表某个特定位置上的值
	ErrorCode retrieve(int position, T& data);//获取链表某个特定位置上的值
	ErrorCode replace(int position, T& data);//将链表上某个特定位置的值更换为data
	Node* traverse();//将链表倒置
	void clear()//清空链表
protected:
	int size;
	Node* head;
};