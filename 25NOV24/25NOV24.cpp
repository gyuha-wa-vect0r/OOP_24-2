#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <malloc.h>
#include <cmath> // atan2 불러올라면 이게 있어야함

using namespace std;

class Shapeeee {
public:
	virtual void draw() { }
	void paint(Shapeeee*);
};

class Circleee : public Shapeeee {
public:
	virtual void draw() {
		cout << "CIRCLE DRAW" << endl;
		// Circle을 그린다.
	}
};

class Rectttt : public Shapeeee {
public:
	virtual void draw() {
		cout << "RECT DRAW" << endl;
		// Rect을 그린다.
	}
};

class Lineeee : public Shapeeee {
public:
	virtual void draw() {
		cout << "LINE DRAW" << endl;
		// Line을 그린다.
	}
};

void paint(Shapeeee* pShape) {
	pShape->draw();
}

void ex1121_2() {
	paint(new Circleee()); // Circle을 그린다.
	paint(new Rectttt()); // Rect을 그린다.
	paint(new Lineeee()); // Line을 그린다. 
	// -> new 쓰면 객체의 주소를 ...? 알아봐야함
	// Up-Casting
}

void ex1121_3() {
	Circleee C;
	Rectttt R;
	Lineeee L;

	paint(&C);
	paint(&R);
	paint(&L);
}

// 버추얼 여러개 들고있어도 그만큼 다 실행 X


// 실습 11-0
class Shape {
	string name;
public:
	virtual float getArea() { return 0.0; }
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
};
class Oval : public Shape {
	int a, b;
public:
	Oval(string name, int a, int b) {
		setName(name);
		this->a = a;
		this->b = b;
	}
	virtual float getArea() { return 3.14 * a * b; }
};
class Triang : public Shape {
	int a, b;
public:
	Triang(string name, int a, int b) {
		setName(name);
		this->a = a;
		this->b = b;
	}
	virtual float getArea() { return 0.5 * a * b; }
};

void ex1121_4() {
	Oval oval("타원", 10, 20);
	Triang triang("삼각형", 30, 40);

	cout << oval.getName() << "넓이는 " << oval.getArea() << endl;
	cout << triang.getName() << "넓이는 " << triang.getArea() << endl;

	Shape* pShape;
	pShape = &oval; // upcasting
	cout << pShape->getName() << "넓이는 " << pShape->getArea() << endl;
	pShape = &triang; // upcasting
	cout << pShape->getName() << "넓이는 " << pShape->getArea() << endl;
}

/*
void main() {

	// 포인터 쓴거
	Oval_1127* p0;
	Rect_1127* p1;
	Triangular_1127* p2;

	p0 = new Oval_1127("빈대떡", 10, 20);
	p1 = new Rect_1127("찰떡", 30, 40);
	p2 = new Triangular_1127("토스트", 30, 40);

	cout << p0->getName() << " 넓이는 " << p0->getArea() << endl;
	cout << p1->getName() << " 넓이는 " << p1->getArea() << endl;
	cout << p2->getName() << " 넓이는 " << p2->getArea() << endl;

	delete p0; delete p1; delete p2;
}
*/

// 실습 11-0에 포인터로 넘겨버린거
void ex1121_5() {
	Oval* pOval = new Oval("타원", 10, 20);
	// new 를 통해 객체를 만들었기 떄문에 (아래쪽을 봐주세욤)
	Triang* pTriang = new Triang("삼각형", 30, 40);

	cout << pOval->getName() << "넓이는 " << pOval->getArea() << endl;
	cout << pTriang->getName() << "넓이는 " << pTriang->getArea() << endl;


	Shape* pShape;
	pShape = pOval; // upcasting
	cout << pShape->getName() << "넓이는 " << pShape->getArea() << endl;
	pShape = pTriang; // upcasting
	cout << pShape->getName() << "넓이는 " << pShape->getArea() << endl;

	delete pOval;
	delete pTriang;
	// main에서 new으로 만든 두개 delete 걸어주고
	// delete pShape;
	// 얘는 지울게 있나...???? 있으면 안되는 코드입니다.


}

// 실습 11-1
void ex1121_6() {
	Shape* p[5]; // p[0], p[1], p[2], p[3], p[4]
	p[0] = new Oval("타원", 10, 20);
	p[1] = new Triang("삼각형", 30, 40);
	p[2] = new Oval("타원", 10, 20);
	p[3] = new Triang("삼각형", 30, 40);
	p[4] = new Oval("타원", 10, 20);

	for (int i = 0; i < 5; i++) {
		cout << p[i]->getName() << "넓이는 " << p[i]->getArea() << endl;
	}
}

// 강의자료 13주차 11-1 15p

class Base {
public:
	int* data_base; // int data[size]
	int size_base;
	Base() {
		size_base = 0;
		data_base = NULL; // data_base[size]
	}
	Base(int size) {
		size_base = size;
		data_base = new int[size]; // data_base[size]
	}
	virtual void f() { cout << "Base::f() called" << endl; }
	~Base() {
		if(data_base != NULL) delete[] data_base;
		cout << "Base 소멸자" << endl; 
	}
};
class Derived : public Base {
public:
	int* data_der;
	int size_der;
	Derived(int size) {
		size_der = size;
		data_der = new int[size];
	}
	void f() { cout << "Derived::f() called" << endl; }
	~Derived() {
		delete[] data_der;
		cout << "Derived 소멸자" << endl;
	}
};
void ex1125_1() {
	Derived* A = new Derived(1000);
	Base* pBase = A;
	delete pBase;
}

// 실습 11-2
class Calculator1 {
public:
	virtual int add(int a, int b) = 0; // 두 정수의 합 리턴
	virtual int subtract(int a, int b) = 0; // 두 정수의 차 리턴
	virtual double average(int a[], int size) = 0; // 배열 a의 평균 리턴. size는 배열의 크기
};

class GoodCalc : public Calculator1 { // public 안쓰면 프라이빗으로 상속됨 ㅇㅇ
	virtual int add(int a, int b) {
		return a + b;
	}
	virtual int subtract(int a, int b) {
		return a - b;
	}
	virtual double average(int a[], int size) {
		double sum = 0.0;
		for (int i = 0; i < size; i++) {
			sum += a[i];
			return sum / size;
		}
	}
// 위에 함수 세개 퍼블릭 안되어있고 프라이빗으로 걸려있는데 
// 그래서 부모 함수에서만 컨트롤 가능...부모 거쳐서 자식 컨트롤이 된다는말!
};


void ex1125_2() {
	int a[] = { 1,2,3,4,5 };
	Calculator1* p = new GoodCalc();
	cout << p->add(2, 3) << endl;
	cout << p->subtract(2, 3) << endl;
	cout << p->average(a, 5) << endl;
	delete p;
}

// 실습 11-3
class Calculator {
	void input() { // private
		cout << "정수 2 개를 입력하세요>> ";
		cin >> a >> b;
	}
protected: // 자식에게 물려줄 protected
	int a, b;
	virtual int calc(int a, int b) = 0; // 두 정수의 합 리턴
	// 순수 가상함수... 누군가가 정의해줄거다 -> 자식 클래스에서 했음
public:
	void run() {
		input();
		cout << "계산된 값은 " << calc(a, b) << endl;
	}
};

class Adder : public Calculator {
	virtual int calc(int a, int b) {
		return a + b;
	}
};

class Subtractor : public Calculator {
	virtual int calc(int a, int b) {
		return a - b;
	}
};

void main() {
	Adder adder;
	Subtractor subtractor;
	adder.run();
	subtractor.run();
}
