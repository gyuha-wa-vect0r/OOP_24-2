#include <iostream> 
#include <string> 
using namespace std;

class Rectangle2 {
private: // 외부 접근 금지
	int width, height;

public:
	int getArea() {
		int output = width * height;
		return output;
	}
	bool setWidth(int input) {
		if (input < 0) return false;
		else {
			width = input;
			return true;
		}
	}
	bool setHeight(int input) {
		if (input < 0) return false;
		else {
			height = input;
			return true;
		}
	}
	// void setWidth(int input) { width = input; }
	// void setHeight(int input) { height = input; }
	int getWidth() { return width; }
	int getHeight() { return height; }
	// 클래스 선언 내에서는 프라이빗과 퍼블릭 관계없이 다 사용 가능!
};

void ex0926_5() {
	Rectangle2 rect;
	// rect.setWidth(3); // width = 3
	if (rect.setWidth(3) == false) {
		cout << "width error" << endl; return;
	}
	//rect.setHeight(5); // height = 5
	if (rect.setHeight(5) == false) {
		cout << "height error" << endl; return;
	}
	cout << "너비 " << rect.getWidth() << endl;
	cout << "높이 " << rect.getHeight() << endl;
	cout << "사각형의 면적은 " << rect.getArea() << endl;
}

class Circle2 {
public:
	int radius;
	Circle2(); // 생성자
	Circle2(int r);
	~Circle2(); // 소멸자, 반드시 한 개만 가능
	double getArea(); // 멤버함수 == 메소드
	
};

Circle2::Circle2() {
	radius = 1;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle2::Circle2(int r) {
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle2::~Circle2() {
	cout << "반지름 " << radius << " 원 소멸" << endl;
}

double Circle2::getArea() {
	return 3.14 * radius * radius;
}

void ex0930_1() { 
	Circle2 donut; // 매개 변수 없는 생성자 호출, 생성 순서 1, 소멸 순서 2
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	Circle2 pizza(30); // 매개 변수 있는 생성자 호출, 생성 순서 2, 소멸 순서 1
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}

void func0930(){
	Circle2 donut; // 매개 변수 없는 생성자 호출, 생성 순서 1, 소멸 순서 2
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;
}

void ex0930_2() {
	func0930();

	Circle2 pizza(30); // 매개 변수 있는 생성자 호출, 생성 순서 2, 소멸 순서 1
	double area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}
// 생성한 순서의 역순으로 소멸된다!!

// 실습 5-1
class Rectangle1 {
public:
	int width, height, length;
	Rectangle1();
	Rectangle1(int width, int height);
	Rectangle1(int length);
	bool isSquare();

	~Rectangle1() { // 소멸자
		cout << "소멸 " << width << " " << height << endl;
	}
};

Rectangle1::Rectangle1() {
	width = 1; height = 1;
}

Rectangle1::Rectangle1(int widthIn, int heightIn) {
	width = widthIn;
	height = heightIn;
}

Rectangle1::Rectangle1(int length) {
	width = height = length;
}

bool Rectangle1::isSquare() {
	if (width == height) { return true; }
	else { return false; }
}

void ex0930_3() {
	Rectangle1 rect1;
	Rectangle1 rect2(3, 5);
	Rectangle1 rect3(3);
	if (rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
	if (rect2.isSquare()) cout << "rect2는 정사각형이다." << endl;
	if (rect3.isSquare()) cout << "rect3는 정사각형이다." << endl;
}

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

void main() {
	int A = 11;
	if (isEven(A) == true) { cout << A << "는 짝수다!!" << endl; } // if(isEven(A) == true)
	else { cout << A << "는 홀수다!!" << endl; }
}