#include <iostream> 
#include <string> 
using namespace std;

/*
void myswap(int& a, int& b) { // a <-> b swap
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
void myswap(double& a, double& b) {
	double tmp;
	tmp = a;
	a = b;
	b = tmp;
}
*/

// 함수나 클래스를 일반화시켰슴.. 위의 두 함수를 하나로 합쳤다고 보면 됩니더
// <class T> 를 쓰던지 <typename T> 를 쓰던지 ㄴ상관
template <class T> void myswap(T& a, T& b) {
	T tmp; // int나 double이나 다 된다는겨~~~ T가 대표로 지정됨
	tmp = a;
	a = b;
	b = tmp;
}

void ex0926_1() {
	int a = 4, b = 5;
	myswap(a, b); // myswap(int& a, int& b) 호출
	cout << a << '\t' << b << endl; // myswap()에 의해 swap된 a b 출력
	double c = 0.3, d = 12.5;
	myswap(c, d); // myswap(double& a, double& b) 호출
	cout << c << '\t' << d << endl;
}

// 실습 3-3
template <class K> K add(K* a, int b) {
	K sum = 0;
	for (int i = 0; i < b; i++) { sum += a[i];}
	return sum;
}

void ex0926_2() {
	int x[] = { 1,2,3,4,5 };
	double d[] = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.7 };
	float y[] = { 1, 2, 3, 4, 5, 6 };

	cout << "sum of x[] = " << add(x, 5) << endl; // 배열 x와 원소 5개의 합을 계산
	cout << "sum of d[] = " << add(d, 6) << endl; // 배열 d와 원소 6개의 합을 계산
	cout << "sum of y[] = " << add(y, 6) << endl; // 배열 d와 원소 6개의 합을 계산
}

class Circle { // 클래스명 과 선언
public:
	int radius; // 같은 클래스 내에서는 전역변수처럼 사용가능, 
	double getArea() { // 함수를 인라인함수로 자동 선언하는 경우
		double area = 3.14 * radius * radius; // class에서 radius 선언 되었으므로 함수 내에서는 안 함
		return area;
	}
private:
	//int radius
};
// class에서 public 안써주면 디폴트는 private임니다.

/*
double Circle::getArea() { // 클래스에 소속된 멤버 함수명과 메개변수
	double area = 3.14 * radius * radius; // class에서 radius 선언 되었으므로 함수 내에서는 안 함
	return area;
}
*/

void ex0926_3() {
	Circle A, B, C; // Circle 클래스의 객체를 A 타입 B 타입 C 타입으로 생성
	A.radius = 10; // A 객체의 반지름 저장
	cout << A.getArea() << endl;

	int a; // 값을 저장
	int* b; // 주소를 저장

	Circle* p = &A; // 64비트 포인터변수 //는 설명 안해주신다고 함...
	cout << (*p).radius << endl; // p 주소의 있는 내용물 클래스의 radius 출력
	cout << p->radius << endl;
	cout << (*p).getArea() << endl;
	cout << p->getArea() << endl;
}

// 실습 4-3
class Rectangle {
public: // 이거 안쓰면 프라이빗이라 말짱도루묵입니더...
	int width, height;
	int getArea();
	/*
	int getArea() { // Class 내에 함수 넣기 (인라인함수)
		int output = width * height;
		return output;
	} // output은 getArea 함수 내의 지역변수!
	*/
};

int Rectangle::getArea() { // Class 외에 함수 넣기 
	int output = width * height;
	return output;
} // output은 getArea 함수 내의 지역변수!

void ex0926_4() {
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	cout << "사각형의 면적은 " << rect.getArea() << endl;
}

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
// 백터랑 스트링은 하지말기!!


class Circle2 {
public:
	int radius;
	Circle2(); // 생성자
	Circle2(int r);
	double getArea();
};

Circle2::Circle2() {

}

Circle2::Circle2(int r) {

}

double Circle2::getArea() {
	return 3.14 * radius * radius;
}
