#include <iostream> 
#include <string> 
using namespace std;

// 실습 5-2
class Oval {
public:
	int width, height; // 정수값의 사각형 너비와 높이를 가지는 width, height 변수 멤버
	Oval() { width = 1;	height = 1; } // 너비와 높이를 1로 초기화하는 매개변수 없는 생성자
	Oval(int w, int h) { width = w; height = h; } // 너비와 높이값을 매개변수로 받는 생성자 
	void set(int w, int h) { width = w; height = h; } // 타원의 너비와 높이를 변경하는 set(int w, int h) 함수멤버
	int getWidth() { return width; } // 타원의 너비를 리턴하는 getWidth() 함수멤버
	int getHeight() { return height; } // 타원의 높이를 리턴하는 getHeight() 함수멤버
	void show() { // 타원의 너비와 높이를 화면에 출력하는 show() 함수멤버
		cout << "width = " << width << ", height = " << height << endl;
	}
	double getArea();
	~Oval() {
		cout << "Oval 소멸 : width = " << width << ", height = " << height << endl;
	}
};

double Oval::getArea() { return 3.14 * width * height; } // ? 얘는 뭐에다 쓰는거여?

void ex0930_4() {
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << ", " << b.getHeight() << endl;
}

inline bool isEven(int B) {
	if (B % 2 == 0) { return true; }
	else { return false; }
}

void ex0930_5() {
	int A = 11;
	if (isEven(A) == true) { cout << A << "는 짝수다!!" << endl; } // if(isEven(A) == true)
	else { cout << A << "는 홀수다!!" << endl; }
}

// 실습 5-4
#include "cal.h"

void ex1007_1() {
	Calculator calc; // calc 객체 생성
	calc.run(); // 계산기 시작
}

// 실습 6-1
#include "ram.h"

void ex1007_2() {
	Ram ram;
	ram.write(100, 20); // 100 번지에 20 저장
	ram.write(101, 30); // 101 번지에 30 저장
	char res = ram.read(100) + ram.read(101); // 20 + 30 = 50
	ram.write(102, res); // 102 번지에 50 저장
	cout << "102 번지의 값 = " << (int)ram.read(102) << endl; // 102 번지 메모리 값 출력
}

int B = 200; // 전역 변수

void ex1007_3() {
	// const int A = 100; // const 걸려져있으면 못건들임...
	// A = 200;

	int A = 100; // 지역 변수
	cout << A << " " << B << endl;

	static int C = 300; 
	// 함수 내에 있어도 static 사용으로 인한 전역 변수
}

class Person {
public:
	double money; // 개인 소유의 돈
	void addMoney(int money) {
		this->money += money;
	}
	Person() { money = 0; } // 생성자
	static int sharedMoney; // 공금, 전역 변수
	static void addShared(int n) {
		sharedMoney += n;
	}
};

// static 변수 생성. 전역 공간에 생성
int Person::sharedMoney = 10; // 10으로 초기화

// main() 함수
void main() {
	Person han;
	han.money = 100; // han의 개인 돈=100
	han.sharedMoney = 200; // static 멤버 접근, 공금=200
	Person lee;
	lee.money = 150; // lee의 개인 돈=150
	lee.addMoney(200); // lee의 개인 돈=350
	lee.addShared(200); // static 멤버 접근, 공금=400
	cout << han.money << ' '
		<< lee.money << endl;
	cout << han.sharedMoney << ' '
		<< lee.sharedMoney << endl;
	// static으로 묶여있으면 다른 객체여도 변수를 공유함!
	// 그래서 han이든 lee이든 200으로 출력될 것임...
	// static으로 안 묶여있으면 각자 다른 메모리에 저장됨!
}