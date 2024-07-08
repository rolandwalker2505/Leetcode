#include<iostream>
using namespace std;
struct node {
	int gt;
	node *next;
};
struct cirList {
	node *head;
	//node *tail;
};
void init(cirList &l) {
	l.head = NULL;
	//l.tail = NULL;
}
node* cre(int x) {
	node *p = new node;
	p->gt = x;
	p->next = NULL;
	return p;
}
void insertFirst(cirList &l, int x) {
	node *p = cre(x);
	if (l.head == NULL) {
		p->next = p;
		l.head = p;
	}
	else {
		node *Last = l.head;
		while (Last->next!= l.head) {
			Last = Last->next;
		}
		Last->next = p;
		p->next = l.head;
		l.head = p;
	}
}
void insertLast(cirList &l, int x) {
	node *p = cre(x);
	if (l.head == NULL) {
		p->next = p;
		l.head = p;
	}
	else {
		node *Last = l.head;
		while (Last->next!= l.head)
			Last = Last->next;
		Last->next = p;
		p->next = l.head;
	}
}
void deFirst(cirList &l) {
	if (l.head != NULL)
	{
		if (l.head->next == l.head) {
			l.head= NULL;
			delete l.head;
		}
		else {
			node *p = l.head;
			while (p->next!= l.head)
			{
				p = p->next;
			}
			node *de = l.head;
			p->next = l.head->next;
			l.head = l.head->next;
			de->next = NULL;
			delete de;
		}
	}
}
void deLast(cirList &l) {
	if (l.head != NULL)
	{
		if (l.head->next == l.head) {
			l.head= NULL;
			delete l.head;
		}else {
			node *de = l.head;
			node *prede=NULL;
			while (de->next!= l.head)
			{
				prede = de;
				de = de->next;
			}
			prede->next = l.head;
			de->next = NULL;
			delete de;
		}
		
	}
}
node* findNode(cirList l,int key) {
	node *p = l.head;
	do {
		if (p->gt == key) {
			return p;
		}
		p = p->next;
	} while (p != l.head);
	return NULL;
}
void print(cirList l) {
	if (l.head != NULL) {
		node *p = l.head;
		do {
			cout << p->gt << " ";
			p = p->next;
		} while (p!= l.head);
	}
}
void clear(cirList &l) {
	while (l.head != NULL) {
		deFirst(l);
	}
}
int main() {
	cirList l;
	init(l);
	insertFirst(l, 6);
	insertFirst(l, 4);
	insertLast(l, 7);
	insertLast(l, 5);
	print(l);
	system("pause");
	return 1;
}