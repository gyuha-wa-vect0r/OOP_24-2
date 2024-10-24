#include <iostream>
#include <string>
using namespace std;

// 5-1
class Rectangle {
public:
	int width;
	int height;
	Rectangle() {
		width = 1;
		height = 1;
	}
	Rectangle(int a, int b) {
		width = a;
		height = b;
	}
	Rectangle(int a) {
		width = a;
		height = a;
	}
	bool isSquare() {
		return width == height; 
		// return때 바로 조건 넣어도 0 or 1로 리턴됨
	}
};

void ex5_1() {
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);
	if (rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
	if (rect2.isSquare()) cout << "rect2는 정사각형이다." << endl;
	if (rect3.isSquare()) cout << "rect3는 정사각형이다." << endl;
}


// 5-2
class Oval {
public:
	int width;
	int height; // 정수값의 사각형 너비와 높이를 가지는 width, height 변수 멤버
	Oval() { // 너비와 높이를 1로 초기화하는 매개변수 없는 생성자
		width = 1;
		height = 1;
	}
	Oval(int w, int h) { // 너비와 높이값을 매개변수로 받는 생성자
		width = w;
		height = h;
	}
	int getWidth() { //타원의 너비를 리턴하는 getWidth() 함수멤버
		return width; // 말 그대로 타원의 너비를 리턴...
	}
	int getHeight() { //타원의 높이를 리턴하는 getHeight() 함수멤버
		return height; // 말 그대로 타원의 높이를 리턴...
	}
	void set(int w, int h) { //타원의 너비와 높이를 변경하는 set(int w, int h) 함수멤버
		width = w;
		height = h;
	}
	void show() { //타원의 너비와 높이를 화면에 출력하는 show() 함수멤버
		cout << "Width = " << width << ", Height = " << height << endl;
	}
	~Oval() { // width와 height를 출력하는 소멸자
		cout << "Oval 소멸 : " << width << ", " << height << endl;
	}
}; // 와 무작정 int나 void로 생각하지 말길... 리턴값 여부 반드시 따지기!!! 그리고 class 끝에 }; 체크 꼭 하시오!!!

void ex5_2() {
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << ", " << b.getHeight() << endl;
}

// 5-3
class Intenger {
public:
	int innnnnt;
	Intenger(int n) {
		innnnnt = n;
	}
	Intenger(string m) {
		innnnnt = stoi(m); //string to int -> s to i -> stoi()
	}
	inline int get() {
		return innnnnt;
	}
	inline void set(int n) {
		innnnnt = n;
	}
	inline bool isEven() {
		return innnnnt % 2 == 0;
	}
};

void ex5_3() {
	Intenger n(30);
	cout << n.get() << ' '; // 30 출력
	n.set(50);
	cout << n.get() << ' '; // 50 출력
	Intenger m("300");
	cout << m.get() << ' '; // 300 출력
	cout << m.isEven(); // true(정수로 1) 출력
}

// 5-4
#include "add.h" // -> 싸제 헤더 긁어올때는 "" 안에 파일명 ㄱㄱ
/* to add.h
class Adder { // 덧셈 모듈 클래스
	int op1, op2;
public:
	Adder(int a, int b);
	int process();
};
*/

/* to cal.cpp
Adder::Adder(int a, int b) {
	op1 = a; op2 = b;
}
int Adder::process() {
	return op1 + op2;
}
*/

/* to add.h
class Calculator { // 계산기 클래스
public:
	void run();
};
*/

/* to cal.cpp
void Calculator::run() {
	cout << "두 개의 수를 입력하세요>>";
	int a, b;
	cin >> a >> b; // 정수 두 개 입력
	Adder adder(a, b); // 덧셈기 생성
	cout << adder.process(); // 덧셈 계산
}
*/

int ex5_4() {
	Calculator calc; // calc 객체 생성
	calc.run(); // 계산기 시작
}