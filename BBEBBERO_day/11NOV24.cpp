#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <malloc.h>
#include <cmath> // atan2 불러올라면 이게 있어야함

using namespace std;

// 실습 9-3 -> operator를 friend로 ㄱㄱ
class Book {
	char* title; // 제목 문자열
public:
	int price; // 가격
	Book(char* title, int price); // 그냥 자
	Book(Book& obj); // 복사 생성자
	~Book();
	void operator+=(int value) { this->price += value; }
	void operator-=(int value) { this->price -= value; }
	bool operator==(int value) { return this->price == value; }
	bool operator!() {
		if (this->price == 0) return false;
		else return true;
	}
	void set(char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

bool operator==(Book& A, int price) {
	if (A.price == price) {
		return 0;
	}
}

Book::Book(char* title, int price) {
	// 클래스 멤버 명이랑 함수 내 지역변수명이랑 같을때 this 포인터 사용
	//this->title = title;
	//this->price = price;
	// 클래스 멤버   지역변수
	// 근데 이리하는게 바람직하지 않다고...

	int length = strlen(title);
	this->title = new char[length + 1];
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
	this->title = new char[length + 1];
	strcpy(this->title, title);
	this->price = price;
}

/*
void ex1111_1() {
	Book a((char*)"청춘", 20000), b((char*)"미래", 30000);
	if (a == 30000) { cout << "정가 3마넌" << endl; }
	// bool operator==(int price)
	else { cout << "3마넌 아님 ㅋ" << endl; }
}
*/ // -> 코드 빵꾸난거 처리되어야 돌릴 수 있음...

// 실습 9-5
void ex1111_2() {
	Book book((char*)"벼룩시장", 0);
	if (!book) { // book.operator!()
		cout << "공짜다" << endl;
	}
}

/*
상속 선언법

class 파생클래스이름 : 접근변경자 기본클래스이름
{
};

*/

// 2차원 평면에서 한 점을 표현하는 클래스 Point 선언
class Point {
	int x, y; //한 점 (x,y) 좌표값
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

// 2차원 평면에서 컬러점을 표현하는 클래스 ColorPoint.Point를 상속받음
class ColorPoint : public Point { // 콜론 하나 찍어줘야함
	string color;// 점의 색 표현
public:
	void setColor(string color) {
		this->color = color;
	}
	void showColorPoint() {
		cout << color << ":";
		showPoint(); // Point의 showPoint() 호출;
	}
};

// 강의 자료 10-1 p.7
void ex1111_3() { // 업 캐스팅
	Point p; // 기본 클래스의 객체 생성
	ColorPoint cp; // 파생 클래스의 객체 생성
	cp.set(3, 4); // 기본 클래스의 멤버 호출
	cp.setColor("Red"); // 파생 클래스의 멤버 호출
	cp.showColorPoint(); // 파생 클래스의 멤버 호출

	ColorPoint* pDer = &cp;
	pDer->set(30, 40);
	// (*pDer).set(30, 40)이나 cp.set(30, 40) 이랑 같은거임
	pDer->setColor("Blue");
	pDer->showColorPoint();

	Point* pBase = (Point*)pDer;
	pBase->set(300, 400);
	pDer->showColorPoint();
}

void ex1111_4() { // 다운 캐스팅 : 부모의 주소 -> 자식의 주소
	
	ColorPoint cp; 
	ColorPoint* pDer;
	Point* pBase = &cp; // 업캐스팅
	
	pBase->set(3, 4);
	pBase->showPoint();

	pDer = (ColorPoint*)pBase; // 다운캐스팅
	pDer->set(30, 40);
	pDer->setColor("Blue");
	pDer->showColorPoint();
	pDer->showPoint();
}

// 실습 10-1

class Circle {
private:
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	int getRadius() { return radius; } 
	// private이라 상속이 안되기에 함수를 따로 만들어줌
	void setRadius(int radius) { this->radius = radius; }
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle() {
		setRadius(0);
		name = "default";
	}
	NamedCircle(int radius, string name) {
		setRadius(radius);
		this->name = name;
	}
	void show() {
		cout << "반지름이 " << getRadius() << "인 " << name << endl;
		// radius 는 부모 클래스의 private
	}
};

void ex1111_5() {
	NamedCircle waffle(3, "waffle"); // 반지름이 3이고 이름이 waffle인 원
	waffle.show();
}

// 실습 10-2

void FindLargestNamedCircle(NamedCircle* namedcircle, int size) {

}

void main() {
	NamedCircle pizza[5];
	cout << "5개의 정수 반지름과 원의 이름을 입력하세요." << endl;
	for (int i = 1; i <= 5; i++) {

	}
}