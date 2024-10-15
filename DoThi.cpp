#include<iostream>
#include<fstream>
using namespace std;
#define max 20

struct node
{
	int data;
	node* link;
};

void init(node* head[],int n)
{
	for (int i = 0; i < n; i++)
		head[i] = NULL;
}

node* newNode(int key) {
	node *p = new node;
	p->data = key;
	p->link = NULL;
	return p;
}

void addLast(node* &head, int x) {
	node *p = newNode(x);
	if (head == NULL)
		head = p;
	else {
		node *q = head;
		while (q ->link!= NULL)
			q = q->link;
		q->link = p;
	}
}

void MatrixToList(node *head[], int n,int a[][max]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				addLast(head[i], j+1);
			}
		}
	}
}

void docFile(int a[][max],int &n) {
	ifstream inF("DoThi.txt");
	if (inF.is_open()) {
		inF >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				inF >> a[i][j];
			}
		}
		inF.close();
	}
}

void xuatmang(int a[][max], int n) {
	for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < n; j++) {
			cout<< a[i][j]<<" ";
		}
	}
	cout << endl;
}

void display(node* head[],int n) {
	for (int i = 0; i < n; i++) {
		node *p = head[i];
		cout << i + 1 << ":";
		while (p != NULL) {
			cout << p->data << " ";
			p = p->link;
		}
		cout << endl;
	}
}
void createMatrix(int a[][max]) {
	ifstream inF("input.txt");
	if (inF.is_open()) {
		int n;
		inF >> n;
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				a[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			int r, c;
			inF >> r>> c;
			a[r][c] = 1;
			a[c][r] = 1;
		}
		inF.close();
	}
}
void input(node* head[], int n)
{
	int d, x, m;
	cout << "nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nnhap dinh thu " << i + 1 << ": ";
		cin >> d; addLast(head[i], d); cout << "nhap vao so dinh ke cua " << d << ": ";
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> x;
			addLast(head[i], x);
		}
	}
}
int main() {
	int a[max][max],n=7;
	node* head[max];
	/*docFile(a, n);*/
	createMatrix(a);
	xuatmang(a, n);
	init(head, n);
	MatrixToList(head, n, a);
	display(head, n);
	system("pause");
}