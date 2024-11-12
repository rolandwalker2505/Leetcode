#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define max 9
#define Max 100

// Cấu trúc đồ thị
struct node {
	int data;
	int w;
	node *link;
};

void init(node *head[], int n) {
	for (int i = 0; i < n; i++) {
		head[i] = nullptr;
	}
}

node* create(int key, int weight) {
	node *p = new node;
	p->data = key;
	p->w = weight;
	p->link = nullptr;
	return p;
}

void addLast(node* &head, int x, int weight) {
	if (head == nullptr) {
		head = create(x, weight);
	}
	else {
		node *p = head;
		while (p->link != nullptr) {
			p = p->link;
		}
		p->link = create(x, weight);
	}
}
void display(node* head[], int n) {
	for (int i = 0; i < n; i++) {
		node *p = head[i];
		cout << i << ": ";
		while (p != nullptr) {
			cout << p->data << "(" << p->w << ") ";
			p = p->link;
		}
		cout << endl;
	}
}

void docFile(node* head[], int &n) {
	ifstream inF("input_DoThi.txt");
	if (inF.is_open()) {
		inF >> n;
		while (!inF.eof()) {
			int pre, next, weight;
			inF >> pre >> next >> weight;
			addLast(head[pre], next, weight);
			addLast(head[next], pre, weight);
		}
		inF.close();
	}
}

struct E {
	int start;
	int end;
	int w;
};

void prim(node* head[], int n,int st) {
	vector<E> T;
	vector<bool> tree(n,false);
	int Tweight = 0, size = 0;
	tree[st] = true;
	while (size < n - 1) {
		int min_w = INT_MAX,A=-1,B=-1;
		for (int i = 0; i < n ; i++) {
			if (tree[i] == true) {
				node *p = head[i];
				while (p!=NULL) {
					if (tree[p->data] != true && min_w > p->w) {
						A = i;
						B = p->data;
						min_w = p->w;
					}
					p=p->link;
				}
			}
		}
		T.push_back({ A, B, min_w });
		Tweight += min_w;
		tree[B] = true;
		size++;
	}
	for (const auto &t : T) {
		cout << "(" << t.start << " - " << t.end << ") = " << t.w << endl;
	}

	cout << "Minimum spanning tree: " <<Tweight << "!..." << endl;
}

int main() {
	node *head[max];
	int n;
	init(head, max);
	docFile(head, n);
	display(head, n);
	prim(head, n,0);

	for (int i = 0; i < n; i++) {
		node* p = head[i];
		while (p != nullptr) {
			node* temp = p;
			p = p->link;
			delete temp;
		}
	}

	system("pause");
	return 0;
}