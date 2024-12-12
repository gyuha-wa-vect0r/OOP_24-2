#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

// friend 함수?
// 클래스 멤버함수가 아니라 외부 함수인데...
// 클래스의 멤버로 선언하기에는 무리가 있고, 
// 클래스의 모든 멤버를 자유롭게 접근할 수 있는 일부 외부 함수 작성 시 사용!
// 쉽게 말하면 외부 선언된 함수를 그냥 클래스에서 쓰려고 할 때 하는듯?
// case 1: 외부에 완전 동떨어진 함수를 클래스 friend로 선언할 때
// friend bool equals(Rect r, Rect s);
// case 2: 타 클래스의 함수를 클래스 friend로 선언할 때
// friend bool (타 클래스명)::equals(Rect r, Rect s);
// case 3: 타 클래스 내의 모든 멤버 함수를 싹다 클래스 friend로 선언할 때
// friend (타 클래스명); 
// 위 세 cases를 friend로 묶고싶은 class 내에 작성

class Rect; // 선언문!!!!
// equals(Rect r, Rect s) 함수는 Rect 클래스를 매개변수로 받기 때문에, 
// 컴파일러는 Rect 클래스의 존재를 알아야 합니다. 
// 그러나 Rect 클래스의 정의가 나중에 등장하므로, 
// 컴파일러는 아직 Rect 클래스가 무엇인지 모르는 상태입니다. 
// 이 문제를 해결하기 위해 선언문을 사용하여 컴파일러에게 "Rect라는 클래스가 존재한다"고 알려줍니다.
bool equals(Rect r, Rect s); // equals() 함수 선언

class Rect1 { // Rect 클래스 선언
	int width, height;
public:
	Rect1(int width, int height) { this->width = width; this->height = height; }
	friend bool equals(Rect1 r, Rect1 s);
	// equals() 함수는 private 속성을 가진 Rect의 width, height에 접근할 수 있다.
};
bool equals(Rect1 r, Rect1 s) { // 외부 함수
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

void friendExternalFunction() {
	Rect1 a(3, 4), b(4, 5);
	if (equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}
#if 0
class RectManager { // RectManager 클래스 선언
public:
	bool equals(Rect2 r, Rect2 s);
};
class Rect2 { // Rect 클래스 선언
	int width, height;
public:
	Rect2(int width, int height) { this->width = width; this->height = height; }
	friend bool RectManager::equals(Rect2 r, Rect2 s);
	// Rect2에 RectManager class 소속 함수 땡겨옴!
	// RectManager에서 Rect2 private 변수 조회 가능
};

bool RectManager::equals(Rect2 r, Rect2 s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}
int friendOtherClass() {
	Rect2 a(3, 4), b(3, 4);
	RectManager man;
	if (man.equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}
#endif // 0


// 연산자 중복
// 이건 왜쓰는건데 ㄹㅇ -> 클래스 간 연산에 써먹을라고!!
// 연산자는 함수 형태로 구현 - 연산자 함수(operator function)
// 반드시 클래스와 관계를 가짐
// 리턴타입 operator연산자(매개변수리스트); 형식으로 작성...
// 객체 두개가 연산자로 묶이면 쓰는거같아요!

// 클래스의 멤버함수로 작성되면
// 자료형[리턴값이 클래스면 클래스명] operator[연산자](클래스명 op2) 
// -> 함수 인자 둘 중에 뒤에꺼만 땡겨오고 앞에꺼는 this-> 로 퉁칠거임
// 클래스 외 함수로 작성되어 클래스쪽에서 friend로 땡길때
// 자료형[리턴값이 클래스면 클래스명] operator[연산자](클래스명 op1, 클래스명 op2) 
// -> 함수 인자 둘 다 땡겨옴


class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	// Power operator+(Power op2);
	friend Power operator+(Power op1, Power op2); // + 연산자 함수 선언
};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

#if 0
// 동일 클래스 전역 선언 버전
Power Power::operator+(Power op2) { // this쪽이 a, op2가 b
	Power tmp; // 임시 객체 생성
	tmp.kick = this->kick + op2.kick; // kick 더하기
	tmp.punch = this->punch + op2.punch; // punch 더하기
	return tmp; // 더한 결과 리턴, 객체를 리턴하기에 power 자료형 ㅇㅇ
}
#endif

Power operator+(Power op1, Power op2) {
	Power tmp; // 임시 객체 생성
	tmp.kick = op1.kick + op2.kick; // kick 더하기
	tmp.punch = op1.punch + op2.punch; // punch 더하기
	return tmp; // 임시 객체 리턴
}

void operator_pre() {
	Power a(3, 5), b(4, 6), c;
	c = a + b; // 파워 객체 + 연산 , operator 함수 호출
	// -> 객체 두개 더하고싶어요!!
	a.show();
	b.show();
	c.show();
}


// 실습 9-0
// +, - 연산자 함수를 Complex 클래스 멤버 함수로 구현하라.
class Complex1 {
	float re, im;
public:
	Complex1() { re = im = 0; }
	Complex1(float im, float re) { this->re = re; this->im = im; }
	Complex1 operator+(Complex1 in) {
		Complex1 tmp;
		tmp.re = this->re + in.re;
		tmp.im = this->im + in.im;
		return tmp;
	}
	Complex1 operator-(Complex1 in) {
		Complex1 tmp;
		tmp.re = this->re - in.re;
		tmp.im = this->im - in.im;
		return tmp;
	}
	void show()
	{
		cout.precision(5);
		if (im >= 0)
			cout << re << " + j" << im << endl;
		else
			cout << re << " - j" << -im << endl;
	}
};

void ex9_0() {
	Complex1 X(2, 3), Y(3, 4), Z;
	Z = X + Y;
	Z.show();
	Z = X - Y;
	Z.show();
}

// 실습 9-0 추가
//  +, - 연산자 함수를 Complex 클래스 외부 함수로 구현하라.
class Complex {
	float re, im;
public:
	Complex() { re = im = 0; }
	Complex(float im, float re) { this->re = re; this->im = im; }
	Complex operator+(Complex in);
	friend Complex operator-(Complex ii, Complex in); // 외부함수 friend 받을 때
	void show()
	{
		cout.precision(5);
		if (im >= 0)
			cout << re << " + j" << im << endl;
		else
			cout << re << " - j" << -im << endl;
	}
};

// 자료형 소속클래스명::operator(연산자)(인자) { ... }
Complex Complex::operator+(Complex in) {
	Complex tmp;
	tmp.re = this->re + in.re;
	tmp.im = this->im + in.im;
	return tmp;
}

Complex operator-(Complex ii, Complex in) {
	Complex tmp;
	tmp.re = ii.re - in.re;
	tmp.im = ii.im - in.im;
	return tmp;
}

void ex9_0_chuga() {
	Complex X(2, 3), Y(3, 4), Z;
	Z = X + Y;
	Z.show();
	Z = X - Y;
	Z.show();
}

// 실습 9-1  +=, -= 연산자 함수를 Book 클래스 멤버 함수로 구현하라.
class Book1 {
	string title;
	int price;
	int pages;
public:
	Book1(string title = "", int price = 0) {
		this->title = title; this->price = price; 
	}
	void show() {
		cout << title << ' ' << price << "원 " << endl;
	}
	string getTitle() {
		return title;
	}
	Book1 operator+=(int b2) { // 받는 인자 스타일이 정수니까 int로...
		this->price += b2;
		return *this;
	}
	Book1 operator-=(int b2) {
		price = price - b2;
		return *this;
	}
};

void ex9_1() {
	Book1 a("청춘", 20000), b("미래", 30000);
	a += 500; // 책 a의 가격 500원 증가
	b -= 500; // 책 b의 가격 500원 감소
	a.show();
	b.show();
}

// 실습 9-2  +=, -= 연산자 함수를 Book 클래스 외부 함수로 구현하라.
class Book {
	string title;
	int price;
	int pages;
public:
	Book(string title = "", int price = 0) {
		this->title = title; this->price = price;
	}
	void show() {
		cout << title << ' ' << price << "원 " << endl;
	}
	string getTitle() {
		return title;
	}
	Book operator+=(int b2);
	Book operator-=(int b2); 
	friend bool operator==(Book a, int price);
	friend bool operator==(Book a, string name);
	friend bool operator==(Book a, Book bkbk);
};

Book Book::operator+=(int b2) {
	this->price += b2;
	return *this;
}
Book Book::operator-=(int b2) {
	price = price - b2;
	return *this;
}
#if 0
bool Book::operator==(int price){ // 가격 비교, 인자로 구분
	return this->price == price;
}
bool Book::operator==(string name) { // 제목 비교, 인자로 구분
	return this->title == name;
}
bool Book::operator==(Book& bkbk) { // 모든 필드 구분
	return(this->title == bkbk.title && this->price == bkbk.price);
}
#endif
bool operator==(Book a, int price) { // 가격 비교, 인자로 구분
	return a.price == price;
}
bool operator==(Book a, string name) { // 제목 비교, 인자로 구분
	return a.title == name;
}
bool operator==(Book a, Book bkbk) { // 모든 필드 구분
	return(a.title == bkbk.title && a.price == bkbk.price);
}

void ex9_2() {
	Book a("청춘", 20000), b("미래", 30000);
	a += 500; // 책 a의 가격 500원 증가
	b -= 500; // 책 b의 가격 500원 감소
	a.show();
	b.show();
}

// 실습 9-3  3개의 == 연산자 함수를 가진 Book 클래스를 작성하라.
// 실습 9-4  3개의 == 연산자를 friend 함수로 작성하라.
void main() {
	Book a("명품 C++", 30000), b("고품 C++", 30000);
	// price 비교
	if (a == 30000) cout << "정가 30000원" << endl;
	// 책 title 비교
	if (a == "명품 C++") cout << "명품 C++ 입니다." << endl;
	// title, price, pages 모두 비교
	if (a == b) cout << "두 책이 같은 책입니다." << endl;
}