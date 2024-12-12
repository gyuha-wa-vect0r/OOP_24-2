#include <iostream> 
#include <string> 
using namespace std;

// 디폴트 인자 -> 새로 만든 함수의 선언부에 지정, 단 우측부터 차곡차곡
int sum3(int a, int b = 200, int c = 100) {
	return a + b + c;
}

void ex0923_1() {

	int x = 10, y = 20, z = 30;
	int w = sum3(x, y, z);
	int u = sum3(x, y);
	int v = sum3(x);

	cout << w << " " << u << " " << v << endl;
}

// 함수 오버로딩 -> 똑같은 이름의 함수를 인자나 데이터형을 다르게 해서 지정
int ssum(int a, int b, int c) { // 리턴 값 정수요~
	return a + b + c;
}

double ssum(double a, double b, double c) { // 리턴 값 실수요~
	return a + b + c;
}

void ex0923_3() {
	cout << ssum(2, 5, 33) << endl; // 정수 인자값
	cout << ssum(2.5, 100.6, 10.7) << endl; // 실수 인자값
	// 함수를 중복해서 사용 할 수 있어요! 
	// 인자값의 특징에 따라 자동으로 알아서 함수랑 이어주는거지요!
	// !!!!! 단순 리턴타입만 보고는 판단 X !!!!!
	// !!!!! 리턴타입 다른데 인자 이름만 바꾸면 인식 XXXXX !!!!!

}

// 함수 일반화
// template           <class T>       int funcName  (T& a, T& b)
// 템플릿을 만들어요   제네릭타입키워드  실제 함수 선언  T는 제네릭타입-> 인자타입에따라 유동적인데 a랑 b의 타입이 같아야됨.
// 함수나 클래스를 일반화시켰슴.. 위의 두 함수를 하나로 합쳤다고 보면 됩니더
template <class T> void myswap(T& a, T& b) {
	T tmp; // int나 double이나 다 된다는겨~~~ 
	tmp = a;
	a = b;
	b = tmp;
}

void generic() {
	int a = 4, b = 5;
	myswap(a, b); // myswap(int& a, int& b) 호출
	cout << a << '\t' << b << endl; // myswap()에 의해 swap된 a b 출력
	double c = 0.3, d = 12.5;
	myswap(c, d); // myswap(double& a, double& b) 호출
	cout << c << '\t' << d << endl;
}

// 3-1
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

// 3-2
int big(int a, int b, int c = 50) {
	if (a < b) {
		if (b < c) { return b; }
		else if (b > c) { return c; }
	}
	if (a > b) {
		if (a < c) { return a; }
		else if (a > c) { return c; }
	}
}

void ex3_2() {
	int x = big(3, 5); // 3과 5중큰값 5는 최대값 100보다 작으므로, 5 리턴
	int y = big(300, 60); // 300과 60중큰값 300이 최대값 100보다 크므로, 100 리턴
	int z = big(30, 60, 50); // 30과 60 중큰값 60이 최대값 50보다 크므로, 50 리턴
	cout << x << ' ' << y << ' ' << z << endl;
}

// 3-3
template <class T> T add(T* a, int b) {
	T sum = 0;
	for (int i = 0; i < b ; i++) {
		sum += *(a + i);
	}
	return sum;
}

void ex3_3() {
	int x[] = { 1,2,3,4,5 };
	double d[] = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.7 };
	cout << "sum of x[] = " << add(x, 5) << endl; // 배열 x와 원소 5개의 합을 계산
	cout << "sum of d[] = " << add(d, 6) << endl; // 배열 d와 원소 6개의 합을 계산
}

// 3-4
template <class T> void reverseArray(T x[], int num) {
	T* reverse_x = new T[num]; // 동적메모리 할당
	// 아 결론은 이거 동적아니고는 답이 없었구나...
	// 기출 문제 보고 알았네 ㅋㅋ
	int j = 0;
	for (int i = num - 1; i >= 0; i--) {
		reverse_x[j] = x[i];
		j++;
	}
	for (int i = 0; i < num; i++) {
		x[i] = reverse_x[i];
	}

	delete[] reverse_x;
}
int main() {
	int x[] = { 1, 10, 100, 5, 4 };
	reverseArray(x, 5);
	for (int i = 0; i < 5; i++)
		cout << x[i] << ' '; // 4 5 100 10 1 이 출력된다.
	cout << endl;
}
