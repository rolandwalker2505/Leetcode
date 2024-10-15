#include <iostream>
#include <fstream>
using namespace std;
#include<time.h>
void docFile(long *&a, int& n) {
	ifstream myFile("DaySo.txt");
	if (myFile.is_open()) {
		myFile >> n;
		a = new long[n];
		for (int i = 0; i < n; i++) {
			myFile >> a[i];
		}
		myFile.close();
	}
}
void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}
void selectionSort(long*& a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int pos = i;
		for (int j = i + 1; j < n; j++) {
			if (a[pos] > a[j])
				pos = j;
		}
		swap(a[i], a[pos]);
	}
}
void interchangeSort(long *&a, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}
void bubbleSort(long *&a, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}
void insertionSort(long *&a, int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > x) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void quickSort(long *&a, int left, int right) {
	int x = a[(left + right) / 2];
	int l = left; int r = right;
	while (l <= r) {
		while (a[l] < x)
			l++;
		while (a[r] > x)
			r--;
		if (l <= r) {
			swap(a[l], a[r]);
			l++; r--;
		}
		if (left < r)
			quickSort(a, left, r);
		if (l < right)
			quickSort(a, l, right);
	}
}
void heapify(long *&a, int n, int i) {
	int left = 2 * i + 1;
	int right = left + 1;
	int maxpos = i;
	if (left <n && a[left] > a[maxpos])
		maxpos = left;
	if (right <n && a[right] > a[maxpos])
		maxpos = right;
	if (maxpos == i)
		return;
	swap(a[i], a[maxpos]);
	heapify(a, n, maxpos);
}
void heapSort(long *&a, int n) {
	int i = n / 2 - 1;
	while (i >= 0) {
		heapify(a, n, i);
		i--;
	}
	for (int right = n - 1; right > 0; right--) {
		swap(a[0], a[right]);
		heapify(a, right, 0);
	}
}
void output(long *a, int n) {
	ofstream outFile("OutDaySo.txt");
	if (outFile.is_open()) {
		for (int i = 0; i < n; i++) {
			outFile << a[i] << endl;
		}
		//outFile << "1" << endl;
		outFile.close();
		cout << "Done" << endl;
	}
}

int main() {
	long *a = NULL;
	int n;
	clock_t s1, e1;
	docFile(a, n);
	s1 = clock();
	heapSort(a, n);
	e1 = clock();
	output(a, n);
	delete[]a;
	a = NULL;
	double d = (e1 - s1)*1.0 / CLOCKS_PER_SEC;
	cout << "Time:" << d << endl;
	system("pause");
	return 1;
}