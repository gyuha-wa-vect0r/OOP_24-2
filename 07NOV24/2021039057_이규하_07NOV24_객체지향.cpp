#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <malloc.h>
#include <cmath> // atan2 불러올라면 이게 있어야함

using namespace std;
/*
// 실습 9-0 in 04NOV24
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
void ex1104_5() {
	Complex a(2, 3), b(4, -5), c, d;
	c = a + b;
	d = a - b;
	c.show();
	d.show();
}

*/

// 실습 9-0 in 07NOV24

// #define PI 3.1415926535
#define PI (4.0 * atan(1.0))

class Complex {
	float re;
	float im;
public:
	Complex convert2Cartesian(double mag, double angle);
	friend double getMag(Complex A);
	friend double getAngle(Complex A);

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
	Complex operator*(Complex input) {
		double mag = getMag(*this) * getMag(input);
		double angle = getAngle(*this) + getAngle(input);
		return convert2Cartesian(mag, angle);

	}
	Complex operator/(Complex input) {
		double mag = getMag(*this) / getMag(input);
		double angle = getAngle(*this) - getAngle(input);
		return convert2Cartesian(mag, angle);
	}

	void show() {
		cout.precision(5);
		if (im >= 0) cout << re << " + j" << im << endl;
		else cout << re << " - j" << -im << endl;
	}
#if	0
	// 극좌표계로 전환
	double getMag(Complex A) {
		return sqrt(A.re * A.re + A.im * A.im);
	}
	double getAngle(Complex A) {
		if (A.re == 0 && A.im == 0) return 0.0;
		else if (A.re == 0 && A.im > 0) return PI / 2.0;
		else if (A.re == 0 && A.im < 0) return -PI / 2.0;
		else return atan2(A.im, A.re);
	}

	// 극좌표계로 간걸 직각좌표계로 돌려내기
	Complex convert2Cartesian(double mag, double angle) {
		Complex tmp;
		tmp.re = mag * cos(angle);
		tmp.im = mag * sin(angle);
		return tmp;
	}
#endif
};

// 극좌표계로 전환
double getMag(Complex A) {
	return sqrt(A.re * A.re + A.im * A.im);
}
double getAngle(Complex A) {
	if (A.re == 0 && A.im == 0) return 0.0;
	else if (A.re == 0 && A.im > 0) return PI / 2.0;
	else if (A.re == 0 && A.im < 0) return -PI / 2.0;
	else return atan2(A.im, A.re);
}

// 극좌표계로 간걸 직각좌표계로 돌려내기
Complex Complex::convert2Cartesian(double mag, double angle) {
	Complex tmp;
	tmp.re = mag * cos(angle);
	tmp.im = mag * sin(angle);
	return tmp;
}

// 이 상황에서 멈춤...

// 복소수의 사칙연산... 근데 곱하고 나누는거까진 시험에 안나올거같은데..ㅋㅋ
// 곱하고 나누는거 극좌표계 연산하는거는 따로 찾아봐야할듯...
// 믄소린지 모르겠노....
void ex1107_1() {
	Complex a(2, 3), b(4, -5), c, d, e, f;
	c = a + b; // complex a.operator+(b)
	d = a - b;
	e = a * b; // |a|e^{j*theta_a} * |b|e^{j*theta_b} => 크기는 곱하고, 각도는 더하고...
	f = a / b; // 크기는 나누고, 각도는 빼고...
	c.show();
	d.show();
	e.show();
	f.show();
}


// 예제 9-1
class Book2 {
	char* title; // 제목 문자열
	int price; // 가격
public:
	Book2(char* title, int price); // 그냥 자
	Book2(Book2& obj); // 복사 생성자
	~Book2();
	void operator+=(int value) {
		this->price += value;
	}
	void operator-=(int value) {
		this->price -= value;
	}
	void set(char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book2::Book2(char* title, int price) {
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
Book2::Book2(Book2& obj) {
	this->price = obj.price;
	int length = strlen(obj.title);
	this->title = new char[length + 1];
	strcpy(this->title, obj.title);
}
Book2::~Book2() {
	delete[] this->title;
	cout << "소멸자" << endl;
}
void Book2::set(char* title, int price) {
	delete[] this->title;
	int length = strlen(title);
	this->title = new char[length + 1];
	strcpy(this->title, title);
	this->price = price;
}

void ex1107_2() {
	Book2 a((char*)"청춘", 20000), b((char*)"미래", 30000);
	a += 500; // a.operator+=(int value)
	b -= 500; // b.operator-=(int value)
	// ex) c = a + b; -> c = a .+ (b);
	a.show();
	b.show();
}


// 강의자료 9-1 p.9
class Power2 {
	int kick;
	int punch;
public:
	
	Power2(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	friend Power2 operator+(Power2 A, Power2 B);
	friend Power2 operator-(Power2 A, Power2 B);

	void show() {
		cout << "kick = " << kick << ", punch = " << punch << endl;
	}
};

Power2 operator+(Power2 A, Power2 B) { 
	// 리턴 형식이 Power2인거임!!
	Power2 tmp;
	tmp.kick = A.kick + B.kick;
	tmp.punch = A.punch + B.punch;
	return tmp;
}

Power2 operator-(Power2 A, Power2 B) {
	// 리턴 형식이 Power2인거임!!
	Power2 tmp;
	tmp.kick = A.kick - B.kick;
	tmp.punch = A.punch - B.punch;
	return tmp;

}

void ex1107_3() {
	Power2 a(3, 5), b(4, 6), c, d;
	c = a + b; // 파워 객체 + 연산
	// c = operator+(a, b);
	d = a - b;
	// c = operator-(a, b);
	a.show();
	b.show();
	c.show();
	d.show();
}

// 실습 9-3
class Book {
	char* title; // 제목 문자열
	int price; // 가격
public:
	Book(char* title, int price); // 그냥 자
	Book(Book& obj); // 복사 생성자
	~Book();
	void operator+=(int value) { this->price += value; }
	void operator-=(int value) { this->price -= value; }
	bool operator==(int value) { return this->price == value; }
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

void main() {
	Book a((char*)"청춘", 20000), b((char*)"미래", 30000);
	if (a == 30000) { cout << "정가 3마넌" << endl; }
	// bool operator==(int price)
	else { cout << "3마넌 아님 ㅋ" << endl; }
}