#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define Max 100
struct stack {
	int a[Max];
	int top;
};
void init(stack &s) {
	s.top = -1;
}
void push(stack &s,int x) {
	s.a[++s.top] = x;
}
int pop(stack &s) {
	return s.a[s.top--];
}
bool isEmty(stack s) {
	return s.top == -1;
}
void decToBin(int n) {
	stack s;
	init(s);
	while (n != 0) {
		push(s, n % 2);
		n /= 2;
	}
	while (!isEmty(s)) {
		cout << pop(s);
	}
	cout << endl;
}
void balance(char str[]) {
	stack s;
	init(s);
	char *p = strtok(str," ");
	while (p != NULL) {
		if (isdigit(*p)) {
			push(s, atoi(p));
		}else {
			int b = pop(s);
			int a = pop(s);
			int t;
			switch (*p) {
			case '+':
				t = a + b; break;
			case '-':
				t = a - b; break;
			case '*':
				t = a * b; break;
			case '/':
				t = a / b; break;
			}
			push(s,t);
		}
		p= strtok(NULL, " ");
	}
	cout << "ket qua la :" << pop(s) << endl;
}
int main() {
	char str[] = "2 4 6 + * 5 / 1 -";
	//decToBin(13);
	balance(str);
	system("pause");
	return 0;
}