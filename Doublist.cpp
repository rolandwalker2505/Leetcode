#include <iostream>
using namespace std;
struct node
{
	int gt;
	node *next;
	node *pre;
	node() : pre(NULL), next(NULL) {}
};
class DS
{
private:
	node *head;
	node *tail;

public:
	DS() : head(NULL), tail(NULL) {}
	void creatDSNull()
	{
		head = NULL;
		tail = NULL;
	}
	node *creatNode(int x)
	{
		node *p = new node;
		p->gt = x;
		p->next = NULL;
		p->pre = NULL;
		return p;
	}
	void printDS()
	{
		node *p = head;
		while (p != NULL)
		{
			cout << p->gt << " ";
			p = p->next;
		}
		cout << endl;
	}
	void insertFist(int x)
	{
		node *newNode = creatNode(x);
		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->pre = newNode;
			head = newNode;
		}
	}
	void insertLast(int x)
	{
		node *newNode = creatNode(x);
		if (tail == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->pre = tail;
			tail->next = newNode;
			tail = newNode;
		}
	}
	void deleteFist()
	{
		if (head != NULL)
		{
			node *p = head;
			if (head->next == NULL)
			{
				head = tail = NULL;
			}
			else
			{
				head = head->next;
				head->pre = NULL;
				p->next = NULL;
			}
			delete p;
		}
	}
	void deleteLast()
	{
		if (head != NULL)
		{
			node *p = tail;
			if (tail->pre == NULL)
			{
				head = tail = NULL;
			}
			else
			{
				tail = tail->pre;
				tail->next = NULL;
				p->pre = NULL;
			}
			delete p;
		}
	}
	node *findNode(int index)
	{
		node *p = head;
		while (p != NULL)
		{
			if (p->gt == index)
				return p;
			p = p->next;
		}
		return NULL;
	}
	void deleteNode(int x)
	{
		node *p = findNode(x);
		if (p == NULL)
		{
			cout << "khong tim thay!" << endl;
			return;
		}
		if (p->pre != NULL)
		{
			p->pre->next = p->next;
		}
		else
		{
			head = p->next;
		}
		if (p->next != NULL)
		{
			p->next->pre = p->pre;
		}
		else
		{
			tail = p->pre;
		}
		delete p;
	}
};
int main()
{
	DS list;
	list.creatDSNull();
	list.insertFist(5);
	list.insertLast(6);
	list.insertLast(6);
	list.printDS();
	list.deleteLast();
	list.printDS();
	list.deleteFist();
	list.printDS();
	list.deleteNode(6);
	list.printDS();
	return 0;
}
