#include<iostream>
using namespace std;
#define max 100
#include<time.h>
#include<fstream>
void nhapmang(int a[], int &n) {
	do {
		cout << "Nhap so phan tu n:\n"; cin >> n;
		if (n > 100 || n < 0)
			cout << "ban nhap sai, moi nhap lai";
	} while (n > 100 || n < 0);
	for (int i = 0; i < n; i++) {
		cout << "nhap phan tu thu " << i + 1 << ":\n";
		cin >> a[i];
	}
}

void xuatmang(int a[], int n) {
	cout << "Mang A:\n";
	for (int i = 0; i < n; i++) {
		cout << "a[" << i + 1 << "]:" << a[i] << endl;
	}
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int a[], int n) {
	int min;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n - 1; j++) {
			if (a[j] < min)
				min = j;
		}
		if (i != min)
			swap(a[min], a[i]);
	}
}

void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			if (a[j] < a[i])
				swap(a[j], a[i]);
		}
	}
}

void BubbleSort(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = n-1; j >i; j--) {
			if (a[j] < a[i])
				swap(a[j], a[i]);
		}
	}
}

void docFile(int a[], int &n) {
	ifstream inF("DaySo.txt");
	if (inF.is_open()) {
		inF >> n;
		for (int i = 0; i < n; i++) {
			inF >> a[i];
		}
		inF.close();
	}
}
int main() {
	clock_t s1, e1;
	int a[100], n;
	nhapmang(a, n);
	xuatmang(a, n);
	BubbleSort(a, n);
	system("pause");
	return 1;
}