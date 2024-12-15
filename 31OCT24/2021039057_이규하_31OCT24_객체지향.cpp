#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <malloc.h>

using namespace std;

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
	cout << "A: " << A.getRadius() << endl;
	cout << "B: " << B.getRadius() << endl;
}

// 실습 8-2
void readRadius(Circle& cir) {
	cout << "정수 값으로 반지름을 입력하세요 >> ";
	int tmp;
	cin >> tmp;
	cir.setRadius(tmp);
}

void ex1028_5() {
	Circle donut;
	readRadius(donut);
	cout << "donut의 면적 = " << donut.getArea() << endl;
}

void ex1031_1() { // 얕은 복사
	int* A = new int[10];
	int* B;
	
	for (int i = 0; i < 10; i++) {
		A[i] = i * 10;
	}

	B = A; // 얕은 복사, 메모리 주소를 공유

	delete[] A;
}

void ex1031_2() { // 깊은 복사
	int* A = new int[10];
	int* B;

	for (int i = 0; i < 10; i++) {
		A[i] = i * 10;
	}

	B = new int[10]; // 깊은 복사
	for (int i = 0; i < 10; i++) {
		B[i] = A[i]; // 주소 값에 있는 내용물을 직접 복사해줌
	}

	delete[] A;
}


//실습 8-3
class Accumulator {
	int value;
public:
	Accumulator(int value); // 매개변수 value로 멤버 value를 초기화한다.
	Accumulator& add(int n); // value에 n을 더해 값을 누적한다.
	int get(); // 누적된 값 value를 리턴한다.
};

Accumulator::Accumulator(int value) {
	this->value = value;
}

Accumulator& Accumulator::add(int n) {
	this->value += n;
	return *this;
}

int Accumulator::get() {
	return this->value;
}

void ex1031_3() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7); // acc의 value 멤버가 28이 된다.
	cout << acc.get() << endl; // 28 출력
}

// 실습 8-4
class Book {
	char* title; // 제목 문자열
	int price; // 가격
public:
	Book(char* title, int price); // 그냥 자
	Book(Book& obj); // 복사 생성자
	~Book();
	void set(char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(char* title, int price) {
	// 클래스 멤버 명이랑 함수 내 지역변수명이랑 같을때 this 포인터 사용
	//this->title = title;
	//this->price = price;
    // 클래스 멤버   지역변수
	// 근데 이리하는게 바람직하지 않다고...

	int length = strlen(title);
	this->title = new char[length+1];
	this->price = price;
	strcpy(this->title, title);

}
Book::Book(Book& obj) {
	this->price = obj.price;
	int length = strlen(obj.title);
	this->title = new char[length + 1];
	strcpy(this->title, obj.title);
}
Book::~Book() {
	delete[] this->title;
	cout << "소멸자" << endl;
}
void Book::set(char* title, int price) {
	delete[] this->title;
	int length = strlen(title);
	this->title = new char[length+1];
	strcpy(this->title, title);
	this->price = price;
}
void main() {
	// Book cpp("명품C++", 10000); // 글자는 고정된 값이기에(상수라 생각하면 됨), 함수쪽이랑 
	Book cpp((char*) "명품C++", 10000);
	Book java = cpp;
	java.set((char*) "명품자바", 12000);
	cpp.show();
	java.show();
}
