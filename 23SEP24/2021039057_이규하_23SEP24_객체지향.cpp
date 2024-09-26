#include <iostream> 
#include <string> 
using namespace std; 

int sum3(int a, int b = 200, int c = 100) { 
	// 함수에 디폴트값을 지정해두었다. 변수에 초기값 없어야 디폴트값 구동됨!
	// !!!!!!!! 디폴트 인자는 오른쪽부터 차곡차곡 부여해야 한다. !!!!!!!!!!

	return a + b + c;

}

void ex0923_1() {

	int x = 10, y = 20, z = 30;
	int w = sum3(x, y, z);
	int u = sum3(x, y);
	int v = sum3(x);

	cout << w << " " << u << " " << v << endl;

}

// 실습 3-1
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
int ssum(int a, int b, int c) { // 리턴 값 정수요~
	return a + b + c;
}

double ssum(double a, double b, double c) { // 리턴 값 실수요~
	return a + b + c;
}

void ex0923_3() {
	cout << ssum(2, 5, 33) << endl;
	cout << ssum(2.5, 100.6, 10.7) << endl;
	// 함수를 중복해서 사용 할 수 있어요! 
	// 인자값의 특징에 따라 자동으로 알아서 함수랑 이어주는거지요!
}

// 실습 3-2
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
	int x = big(3, 5); // 3과 5중큰값 5는 최대값 100보다 작으므로, 5 리턴
	int y = big(300, 60); // 300과 60중큰값 300이 최대값 100보다 크므로, 100 리턴
	int z = big(30, 60, 50); // 30과 60 중큰값 60이 최대값 50보다 크므로, 50 리턴
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

// 함수나 클래스를 일반화시켰슴.. 위의 두 함수를 하나로 합쳤다고 보면 됩니더
template <class T> void myswap(T& a, T& b) {
	T tmp; // int나 double이나 다 된다는겨~~~ 
	tmp = a;
	a = b;
	b = tmp;
}

void main() {
	int a = 4, b = 5;
	myswap(a, b); // myswap(int& a, int& b) 호출
	cout << a << '\t' << b << endl; // myswap()에 의해 swap된 a b 출력
	double c = 0.3, d = 12.5;
	myswap(c, d); // myswap(double& a, double& b) 호출
	cout << c << '\t' << d << endl;
}