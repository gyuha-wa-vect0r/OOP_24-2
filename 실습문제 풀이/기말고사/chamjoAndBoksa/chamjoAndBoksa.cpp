#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class CirclE {
private:
	int radius;
public:
	CirclE();
	CirclE(int r);
	~CirclE();
	double getArea() { return 3.14 * radius * radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) {
		this->radius = radius;
	}
};

CirclE::CirclE() {
	radius = 1;
	cout << "생성자 실행 radius = " << radius << endl;
}
CirclE::CirclE(int radius) {
	this->radius = radius;
	cout << "생성자 실행 radius = " << radius << endl;
}
CirclE::~CirclE() {
	cout << "소멸자 실행 radius = " << radius << endl;
}

void increase(CirclE c) {
	int r = c.getRadius(); 
	// waffle.getRadius(); 인 느낌이지만 실제로는 waffle이 아님
	// 또 다른 객체 c 라 생각을 해야됨
	// 하지만 생성자 생성은 X, 소멸자만 생성함
	c.setRadius(r + 1); // waffle.SetRadius(); radius = 31
	// c는 여기서 끝나니까 소멸자 실행하면서 함수 종료
}
void hochulByValue() {
	CirclE waffle(30); // waffle 이라는 클래스, 생성자 초기값 30으로 시작 -> radius = 30
	increase(waffle); // waffle 클래스를 increase 함수로 호출 -> 값에 의한 호출 방식의 객체 '복사'
	cout << waffle.getRadius() << endl; 
	// increase 함수쪽 관련 없이 오로지 waffle 객체만 관여 -> 30
	// main 끝나면 소멸자 생성
}

// 값 대신에 주소로 넘길 수 있나여?
// 네

void increase_addr(CirclE* ptr) {
	// 주소를 받았기에 ptr 만의 클래스 생성자 및 소멸자 등장 XXXX
	// main에서 클래스 열었을 때 그거 그대로 ㄱㄱ
	int r = (*ptr).getRadius(); // ptr->getRadius();
	ptr->setRadius(r + 1); // radius 값만 바꿔주고 끝
}

void hochulByAddress() {
	CirclE waffle(30); // waffle 이라는 클래스, 생성자 초기값 30으로 시작 -> radius = 30
	increase_addr(&waffle); // waffle 클래스 주소를 increase 함수로 호출 -> 주소에 의한 호출 방식의 객체 '복사'
	cout << waffle.getRadius() << endl; // 함수에서 바뀐 radius 그대로 ㄱㄱ
}

// 객체 치환
void classchwihwan() {
	CirclE c1(5);
	CirclE c2(30);
	// 각 클래스에 초기값 주고 오픈
	// 클래스를 따로 열었기 때문에 메모리 주소 또한 따로 각각 할당됨
	c1 = c2; // 객체 치환, c2 -> c1으로 오버롸이팅!! 값 동일해짐
}

// 객체 리턴
CirclE getCircle() { 
	// 클래스 자체를 자료형으로 두는건 리턴 value가 객체라서 그래요
	CirclE tmp(30);
	return tmp; // 객체 tmp을 리턴한다.
}
void classreturn() {
	CirclE c; // 객체가 생성된다. radius=1로 초기화된다.
	cout << c.getArea() << endl;
	c = getCircle();
	cout << c.getArea() << endl;
}

// 객체 참조
// & 써서 별칭으로 하는거
// 그래서 복사가 아니라가지고 
// 함수 내에서 굴리면 굴린 그대로 값 바뀜



// 복사 생성자
/*
얕은 복사 vs 깊은 복사
이게 뭐고
얕은 복사는 수박 겉핧기식이죠 니 맛본거 내도 맛본다 이런 느낌?
-> 사본은 원본 객체가 할당 받은 메모리를 공유하는 너낌
-> 메모리에 공유 링크 걸어서 같이 써먹는거같아요
깊은 복사는 수박까서 그냥 그대로 유전자복사하고 똑같이 만드는 느낌?
-> 복사한거 붙여넣을 메모리를 따로 파서 복붙
-> 온전히 독립된거기 때문에 공유 문제 ㄴㄴ
*/
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

	B = new int[10]; // 깊은 복사, new 메모리 공간 할당
	for (int i = 0; i < 10; i++) {
		B[i] = A[i]; // 주소 값에 있는 내용물을 직접 복사해줌
	}

	delete[] A;
}


/*
복사 생성자(copy constructor)?
복사 생성시 호출되는 생성자
일반 생성자 형태처럼 클래스 명을 함수로 쓰되
Circle(Circle& c);
처럼 사용, 한 클래스에 단 한개만 선언
*/

class Circle {
private:
	int radius;
public:
	Circle() { radius = 1; 
	cout << "생성자 실행 radius = " << radius << endl;
	}
	Circle(int radius) { this->radius = radius;
	cout << "생성자 실행 radius = " << radius << endl;
	}
	Circle(Circle& c); // 복사 생성자 선언
	double getArea() { return 3.14 * radius * radius; }
};
Circle::Circle(Circle& c) { 
	// 복사 생성자 구현, Circle& c, 객체를 받았기에 객체 자료형 ㅇㅇ
	this->radius = c.radius;
	cout << "복사 생성자 실행 radius = " << radius << endl;
	// 이 생성자 없어도 main에서 dest(src) 걸어줘도 자동 생성 ㅇㅇ
}
void copyConstructor() {
	Circle src(30); // src 객체의 보통 생성자 호출
	Circle dest(src); 
	// dest 객체의 복사 생성자 호출 -> dest에 src(30)을 덮어 씌우겠다 그말이여
	cout << "원본의 면적 = " << src.getArea() << endl;
	cout << "사본의 면적 = " << dest.getArea() << endl;
}

// 실습 8-1
// 2개의 Circle 객체를 교환하는 swap 함수를 ‘참조에 의한 호출’이 되도록
// 작성하고 호출하는 프로그램을 작성하라.
class Circlee {
private:
	int radius;
public:
	Circlee() { radius = 1; }
	Circlee(int radius) { this->radius = radius; }
	int getArea() { return 3.14 * radius * radius; }
};

void swap(Circlee& aa, Circlee& bb) {
	Circlee tmp = aa;
	aa = bb;
	bb = tmp;
}

void ex8_1() {
	Circlee A(30), B(20);
	swap(A, B);
	cout << "A: " << A.getArea() << endl;
	cout << "B: " << B.getArea() << endl;
}

// 실습 8-2
// 키보드로부터 반지름 값을 읽어 Circle 객체에 반지름을 설정하는 
// 전역함수인 readRadius() 함수를 구현하여 전체 프로그램을 완성하시오. 

class Circlle {
	int radius;
public:
	Circlle() { radius = 1; }
	Circlle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

void readRadius(Circlle& cir) { 
	// 참조 걸어서 main함수쪽 클래스 그대로 사용
	cout << "정수 값으로 반지름을 입력하세요 >> ";
	int tmp;
	cin >> tmp;
	cir.setRadius(tmp); // dount 클래스에 tmp값 setRadius 로 넣음
}

void ex8_2() {
	Circlle donut;
	readRadius(donut);
	cout << "donut의 면적 = " << donut.getArea() << endl;
}

// 실습 8-3
// 클래스 Accumulator는 add() 함수를 통해 계속 값을 누적하는 클래스로서, 
// 다음과 같이 선언된다.Accumulator 클래스를 구현하여 전체 프로그램을 완성하시오.
class Accumulator {
	int value;
public:
	Accumulator(int value) {
		this->value = value;
	}// 매개변수 value로 멤버 value를 초기화한다.
	Accumulator& add(int n) {
		this->value = this->value + n;
		return *this; // 계산값 리턴해야 다음 add 에 써먹음!!
	}// value에 n을 더해 값을 누적한다.
	int get() {
		return value;
	} // 누적된 값 value를 리턴한다.
};
// 만약 Accumulator& add(int n)에서 & 없이 한다면?
// Accumulator add(int n) 값 복사를 반환하기에 독립적으로 사용해서 10 + 5로 고정

void ex8_3() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7); // acc의 value 멤버가 28이 된다.
	// acc.add(5) 하고 반환된 값에 .add(6) 하고 그거의 반환 값에 .add(7)
	// 메서드 체이닝(Method Chaining)
	cout << acc.get() << endl; // 28 출력
}

// 실습 8-4
// 책의 이름과 가격을 저장하는 다음 Book 클래스이다. 
// Book 클래스의 생성자, 소멸자, set() 함수를 구현하고, 
// 실행 결과를 참조하여 깊은 복사생성자를 작성하라.
// 
// -> 깊은 복사 생성자면 새로운 메모리를 할당! 
//
// 실행 결과 
// 명품C++ 10000원
// 명품자바 12000원

class Book {
	char* title; // 제목 문자열, point 변수이므로 동적 할당 바로 가능
	int price; // 가격
public:
	Book(char* title, int price) {
		//title에 제목 저장
		int length = strlen(title);
		this->title = new char[length + 1]; // 0부터라 1 더해줌
		strcpy(this->title, title); // title을 this->title로 복붙
	}
	Book(Book& obj) { // 복사 생성자! 깊은 복사로 복사뜬거 저장할 곳 만들어줌
		// Book java = cpp; 에서 작동되는 생성자임!
		this->price = obj.price;
		int length = strlen(obj.title);
		this->title = new char[length + 1];
		strcpy(this->title, obj.title);
	}
	~Book() {
		delete[] this->title;
	}
	void set(char* title, int price) {
		delete[] this->title; // 기존 메모리 제거
		int length = strlen(title);
		this->title = new char[length + 1];
		strcpy(this->title, title); // title을 this->title로 복붙
		this->price = price;
	}
	void show() { cout << title << ' ' << price << "원" << endl; }
};

void main() {
	Book cpp((char*)"명품C++", 10000); // ("명품C++", 10000) 처럼 되어있던데 이건 ㄴㄴ, (char*)"명품C++"로 해줘야됨
	Book java = cpp;
	java.set((char*)"명품자바", 12000);
	cpp.show();
	java.show();
}