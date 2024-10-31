#include <iostream>
#include <string>
using namespace std;

class A {
public:
	int value;
};

class B {
public:
	int counter;
	A sub;
};


void ex1017_2() {
	B abc;
	abc.sub.value = 100; // B 클래스의 sub, 근데 sub은 A 클래스에 속함.!!
	abc.counter = 200; // B 클래스의 counter
}

void ex1017_3() {
	// int abc = 100;
	int* p = new int; // 포인터배열 1개 선언, 여러개 하고싶다면 new int[10]
	cout << *p << endl;

	delete p; // new와 delete의 관계를 공부해야할 듯... 동적메모리 내용인거같음...
}

class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	double getArea() { return 3.14 * radius * radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};

Circle::Circle() {
	radius = 1;
	cout << "생성자 실행 radius = " << radius << endl;
}
Circle::Circle(int radius) {
	this->radius = radius;
	cout << "생성자 실행 radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "소멸자 실행 radius = " << radius << endl;
}

void increase(Circle c) {
	int r = c.getRadius();
	c.setRadius(r + 1);
}
void ex1028_1() {
	Circle waffle(30);
	increase(waffle);
	cout << waffle.getRadius() << endl;
}

void increase(Circle* c) {
	int r = (*c).getRadius(); // int r = c->getRadius()
	(*c).setRadius(r + 1); // c->setRadius(r + 1)
}
void ex1028_2() {
	Circle waffle(30);
	increase(&waffle); // void increase(Circle* c) 에 waffle 주소를 넘김
	cout << waffle.getRadius() << endl;
}

void increaseREF(Circle& c) {
	int r = c.getRadius(); // int r = c->getRadius()
	c.setRadius(r + 1); // c->setRadius(r + 1)
}
void ex1028_3() {
	Circle waffle(30);
	increaseREF(waffle);
	cout << waffle.getRadius() << endl;
}

// 실습 8-1
// Circle 클래스는 위에꺼 그대로 활용

void Swap(Circle& A, Circle& B) {
	Circle tmp = A;
	A = B;
	B = tmp;
}

void ex8_1() {
	Circle A(30), B(10);
	Swap(A, B);
	cout << "A: " << A.getRadius()<< endl;
	cout << "B: " << B.getRadius() << endl;
}

// 실습 8-2
void readRadius(Circle& cir) {
	cout << "정수 값으로 반지름을 입력하세요 >> ";
	int tmp;
	cin >> tmp;
	cir.setRadius(tmp);
}

void main() {
	Circle donut;
	readRadius(donut);
	cout << "donut의 면적 = " << donut.getArea() << endl;
}