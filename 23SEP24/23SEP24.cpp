#include <iostream> 
#include <string> 
using namespace std; 

int sum3(int a, int b = 200, int c = 100) { 
	// �Լ��� ����Ʈ���� �����صξ���. ������ �ʱⰪ ����� ����Ʈ�� ������!
	// !!!!!!!! ����Ʈ ���ڴ� �����ʺ��� �������� �ο��ؾ� �Ѵ�. !!!!!!!!!!

	return a + b + c;

}

void ex0923_1() {

	int x = 10, y = 20, z = 30;
	int w = sum3(x, y, z);
	int u = sum3(x, y);
	int v = sum3(x);

	cout << w << " " << u << " " << v << endl;

}

// �ǽ� 3-1
void f(char c = ' ', int line = 1) {
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < 10; j++) {
			cout << c;
		}
		cout << endl;
	}
}

void ex0923_2() {
	f();
	f('%');
	f('@', 5);
}

// Function Overloading
int ssum(int a, int b, int c) { // ���� �� ������~
	return a + b + c;
}

double ssum(double a, double b, double c) { // ���� �� �Ǽ���~
	return a + b + c;
}

void ex0923_3() {
	cout << ssum(2, 5, 33) << endl;
	cout << ssum(2.5, 100.6, 10.7) << endl;
	// �Լ��� �ߺ��ؼ� ��� �� �� �־��! 
	// ���ڰ��� Ư¡�� ���� �ڵ����� �˾Ƽ� �Լ��� �̾��ִ°�����!
}

// �ǽ� 3-2
int big(int a, int b) {
	if (a < b) {
		if (b < 100) { return b; }
		else if (b > 100) { return 100;	}
	}
	if (a > b) {
		if (a < 100) { return a; }
		else if (a > 100) { return 100; }
	}
}

int big(int a, int b, int c) {
	if (a < b) {
		if (b < c) { return b; }
		else if (b > c) { return c; }
	}
	if (a > b) {
		if (a < c) { return a; }
		else if (a > c) { return c; }
	}
}

void ex0923_4() {
	int x = big(3, 5); // 3�� 5��ū�� 5�� �ִ밪 100���� �����Ƿ�, 5 ����
	int y = big(300, 60); // 300�� 60��ū�� 300�� �ִ밪 100���� ũ�Ƿ�, 100 ����
	int z = big(30, 60, 50); // 30�� 60 ��ū�� 60�� �ִ밪 50���� ũ�Ƿ�, 50 ����
	cout << x << ' ' << y << ' ' << z << endl;
}

/*
void myswap(int& a, int& b) { // a <-> b swap
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
void myswap(double& a, double& b) {
	double tmp;
	tmp = a;
	a = b;
	b = tmp;
}
*/

// �Լ��� Ŭ������ �Ϲ�ȭ���׽�.. ���� �� �Լ��� �ϳ��� ���ƴٰ� ���� �˴ϴ�
template <class T> void myswap(T& a, T& b) {
	T tmp; // int�� double�̳� �� �ȴٴ°�~~~ 
	tmp = a;
	a = b;
	b = tmp;
}

void main() {
	int a = 4, b = 5;
	myswap(a, b); // myswap(int& a, int& b) ȣ��
	cout << a << '\t' << b << endl; // myswap()�� ���� swap�� a b ���
	double c = 0.3, d = 12.5;
	myswap(c, d); // myswap(double& a, double& b) ȣ��
	cout << c << '\t' << d << endl;
}