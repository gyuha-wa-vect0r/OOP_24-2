#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <malloc.h>

using namespace std;

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
void ex1031() {
	// Book cpp("명품C++", 10000); // 글자는 고정된 값이기에(상수라 생각하면 됨), 함수쪽이랑 
	Book cpp((char*)"명품C++", 10000);
	Book java = cpp;
	java.set((char*)"명품자바", 12000);
	cpp.show();
	java.show();
}


// 실습 8-5
class Book2 {
	char title[100]; // 제목 문자열
	int price; // 가격
public:
	Book2(char* title, int price); // 그냥 자
	Book2(Book2& obj); // 복사 생성자
	~Book2();
	void set(char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book2::Book2(char* title, int price) {
	// 생성자
	strcpy(this->title, title);
	this->price = price;
}
Book2::Book2(Book2& obj) {
	
}
Book2::~Book2() {
	
}
void Book2::set(char* title, int price) {
	strcpy(this->title, title);
	this->price = price;
}
void ex1104_1() {
	// Book2 cpp("명품C++", 10000); // 글자는 고정된 값이기에(상수라 생각하면 됨), 함수쪽이랑 
	Book2 cpp((char*)"명품C++", 10000);
	Book2 java = cpp;
	java.set((char*)"명품자바", 12000);
	cpp.show();
	java.show();
}

// 
class Rect {
	int width, height;
public:
	Rect(int width, int height) {
		this->width = width;
		this->height = height;
	}
	bool equals(Rect s);
};

bool Rect::equals(Rect s) {
	if (this->width == width && this->height == height)
		return true;
	else
		return false;
}

void ex1104_2() {
	Rect a(3, 4), b(4, 5);
	if (a.equals(b))
		// 만약 equals(a, b)로 하고싶다면??
		cout << "같다" << endl;
	else 
		cout << "다르다" << endl;
}

class Rect2 {
	int width, height;
public:
	Rect2(int width, int height) {
		this->width = width;
		this->height = height;
	}

	friend bool equals(Rect2 a, Rect2 b);
};

bool equals(Rect2 a, Rect2 b) {
	if (a.width == b.width && a.height == b.height)
		// -> width와 height는 private이라서 access가 안 됨
		// 해결책 1. 저 두개를 private에서 public에 집어 넣는다.
		// 해결책 2. equal 함수를 Rect2 클래스와 친구라고 해준다.(friend 선언)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void ex1104_3() {
	Rect2 a(2, 3), b(3, 4);
	if(equals(a, b))
		cout << "같다" << endl;
	else
		cout << "다르다" << endl;
}

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	Power operator+(Power input) {
		Power tmp;
		tmp.kick = this->kick + input.kick;
		tmp.punch = this->punch + input.punch;
		return tmp;

	}
	Power operator-(Power input) {
		Power tmp;
		tmp.kick = this->kick - input.kick;
		tmp.punch = this->punch - input.punch;
		return tmp;
	}
	bool operator==(Power input) { 
		return (this->kick == input.kick && this->punch == input.punch);
	}

	void show() {
		cout << "kick = " << kick << ", punch = " << punch << endl;
	}
};

void ex1104_4() {
	Power a(3, 5), b(4, 6), c, d, e;
	c = a + b; // 이건 말이 안되는게 맞기에 빨간줄 뜨는게 마즘 ㅇㅇ
	// a.operator + (b) -> Power operator+(Power b)
	// c = a.operator + (b);
	d = a - b;

	if (a == b)
		cout << "같다" << endl;
	else
		cout << "다르다" << endl;

	a.show();
	b.show();
	c.show();
	d.show();
}

// 실습 9-0
class Complex {
	float re;
	float im;
public:
	Complex(float re = 0, float im = 0) {
		this->re = re; 
		this->im = im;
	}
	Complex operator+(Complex input) {
		Complex tmp;
		tmp.re = this->re + input.re;
		tmp.im = this->im + input.im;
		return tmp;
	}
	Complex operator-(Complex input) {
		Complex tmp;
		tmp.re = this->re - input.re;
		tmp.im = this->im - input.im;
		return tmp;
	}

	void show() {
		cout.precision(5);
		if (im >= 0) cout << re << " + j" << im << endl;
		else cout << re << " - j" << -im << endl;
	}
};

void main() {
	Complex a(2, 3), b(4, -5), c, d;
	c = a + b;
	d = a - b;
	c.show();
	d.show();
}