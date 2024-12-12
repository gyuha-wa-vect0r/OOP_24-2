#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <malloc.h>
#include <cmath> // atan2 불러올라면 이게 있어야함

using namespace std;

// 상속.
// 큰 틀안에 기능별로 틀을 더 짜는 느낌!
// -> 상속은 클래스들의 구조적 관계 파악 용이, 클래스 중복 선언 줄임!
// 자식 클래스에서는 부모 클래스의 private 참조 불가... protected 가능!

// 정의는 어떻게?
/*class 파생클래스이름 : 접근변경자 기본클래스이름 {
* 
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
class ColorPoint : public Point { 
		string color;// 점의 색 표현
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};

void ColorPoint::showColorPoint() { 
	cout << color << ":";
	showPoint(); // Point의 showPoint() 호출
}

void sangsok() {
	Point p; // 기본 클래스의 객체 생성
	ColorPoint cp; // 파생 클래스의 객체 생성
	cp.set(3, 4); // 기본 클래스의 멤버 호출 -> colorpoint 타고 point 호출
	cp.setColor("Red"); // 파생 클래스의 멤버 호출
	cp.showColorPoint(); // 파생 클래스의 멤버 호출
}

// 업 캐스팅
// 자식 클래스 주소를 받아서 부모 클래스에 넣어버리고 그걸 포인터 참조 걸어버리면 ㅇㅋㅇㅋ
/*
ColorPoint cp;
ColorPoint* pDer;
Point* pBase = &cp; // 업캐스팅
pBase->set(3, 4);
pBase->showPoint();
*/

// 다운 캐스팅
// 반대의 경우
/*
pDer = (ColorPoint *)pBase; // 다운캐스팅
pDer->setColor("Red"); // 정상 컴파일
pDer->showColorPoint(); // 정상 컴파일
*/

// 실습 10-1
// 다음 코드가 실행되도록 Circle을 상속받은 NamedCircle 클래스를 작성하고
// 전체 프로그램을 완성하라.

class Circle1 {
private:
	int radius;
public:
	Circle1() { radius = 1; }
	Circle1(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	double getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};

class NamedCircle1 : public Circle1 {
public:
	string name;
	// 생성자 만들 때 가급적이면 empty 조건의 생성자도 만들어주자,,,
	NamedCircle1() {
		setRadius(1);
		this->name = "default";
	}
	NamedCircle1(int banjireum, string name) {
		setRadius(banjireum);
		this->name = name;
	}
	void show() {
		cout << "반지름이 " << getRadius() << "인 " << name << endl;
	}
	~NamedCircle1() {

	}
};

void ex10_1() {
	NamedCircle1 waffle(3, "waffle"); // 반지름이 3이고 이름이 waffle인 원
	waffle.show();
}

// 실습 10-2
// 다음과 같은 배열을 선언하여 다음 실행결과가 나오도록 Circle을 상속받은 
// NamedCircle 클래스와 main() 함수 등 필요한 함수를 작성하라.
class Circle2 {
private:
	int radius;
public:
	Circle2() { radius = 1; }
	Circle2(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	double getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};

class NamedCircle2 : public Circle2 {
public:
	string name;
	// 생성자 만들 때 가급적이면 empty 조건의 생성자도 만들어주자,,,
	NamedCircle2() {
		setRadius(1);
		this->name = "default";
	}
	NamedCircle2(int banjireum, string name) {
		setRadius(banjireum);
		this->name = name;
	}
	void setName(string name) {
		this->name = name;
	}
	void show() {
		cout << "반지름이 " << getRadius() << "인 " << name << endl;
	}
	~NamedCircle2() {

	}
};

void ex10_2() {
	NamedCircle2 pizza[5];
	int input;
	string name;
	for (int i = 0; i < 5; i++) {
		cout << "5개의 정수 반지름과 원의 이름을 입력하세요." << endl;
		cout << i + 1 << " >> " << endl;
		cin >> input >> name;
		pizza[i].setRadius(input);
		pizza[i].setName(name);
	}

}

class A {
public:
	A() { cout << "constructor A" << endl; }
	~A() { cout << "destructor A" << endl; }
};

class B : public A {
public:
	B() { cout << "constructor B" << endl; }
	~B() { cout << "destructor B" << endl; }
};

class C : public B {
public:
	C() { cout << "constructor C" << endl; }
	~C() { cout << "destructor C" << endl; }
};

void main() {
	C c;
}

