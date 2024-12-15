#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <malloc.h>
#include <cmath> // atan2 불러올라면 이게 있어야함

using namespace std;

// 실습 10-3

class BaseArray {
private:
	int capacity; // 동적 할당된 메모리 용량
	int* mem; // 정수 배열을 만들기 위한 메모리 포인터
protected:
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
	void MakeQueue(int capacity) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
public:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
};

class MyQueue : public BaseArray {
	int index;
public:
	MyQueue(int cap) {
		MakeQueue(cap);
		index = 0;
	}
	void enqueue(int n) {
		put(index, n);
		index++;
	}
	int capacity() { return getCapacity(); }
	int length() { return index; }
	int dequeue() {
		int value = get(0); // mem[0]; // (1)
		index--; // (2)
		for (int i = 0; i < index; i++) {
			// mem[i] = mem[i + 1];
			int val = get(i + 1);
			put(i, val);
		}

		return value;
	}

};

void ex1114_2() {
	// BaseArray A(50); // A(50)일때, protected로 묶여있어서 제3자에게는 안 먹힙니다.
	// 생성자 자체가 안보이지요... 상속관계만 사용가능!
	// class에서 생성자 소멸자만 public으로 빼버렸습니다.
	MyQueue mQ(100);
	int n;

	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // 큐에 삽입
	}
	cout << "큐의 용량 : " << mQ.capacity() << ", 큐의 크기 : " << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;

}

// 9페이지 시험 나올거같음 교수님이 언급하셨슴다
// 퍼블릭에 대한거만 빠삭하게 알도록 하세요

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

void ex1118_1() {
	C c;
}

class AAA {
public:
	AAA() { cout << "constructor A" << endl; } // 1
	AAA(int x) { cout << "constructor A(int x)" << endl; } // 2
	~AAA() { cout << "destructor A" << endl; }
};

class BBB : public AAA {
public:
	BBB() { cout << "constructor B" << endl; } // 3
	BBB(int x) { cout << "constructor B(int x)" << endl; } // 4
	~BBB() { cout << "destructor B" << endl; }
};


void ex1118_2() {
	BBB b; // 1 3
	BBB bb(3); // 1 4 <--- aaa의 기본 생성자가 호출됨
}

/*
constructor A
constructor B
constructor A
constructor B(int x)
destructor B
destructor A
destructor B
destructor A
*/

class AAAA {
public:
	AAAA() { cout << "constructor A" << endl; } // 1
	AAAA(int x) { cout << "constructor A(int x) : " << x << endl; } // 2
	~AAAA() { cout << "destructor A" << endl; }
};

class BBBB : public AAAA {
public:
	BBBB() { cout << "constructor B" << endl; } // 3
	BBBB(int x) : AAAA(x) { cout << "constructor B(int x) : " << x << endl; } // 4 BBB(int x) : AAA() 와 동일
	~BBBB() { cout << "destructor B" << endl; }
};


void ex1118_3() {
	BBB b; // 1 3
	BBB bb(5); // 2 4 <--- aaa의 기본 생성자가 호출됨
}

/*
constructor A
constructor B
constructor A
constructor B(int x)
destructor B ... bb
destructor A ... bb
destructor B ... b
destructor A ... b
*/

class Base1 {
public:
	void f() { // 실제 함수
		cout << "Base::f() called" << endl;
	}
};
class Derived1 : public Base1 {
public:
	void f() {
		cout << "Derived::f() called" << endl;
	}
};

void mainnnNoVirtual() {
	Derived1 d, * pDer;
	pDer = &d;
	pDer->f();

	Base1* pBase = pDer;
	pBase->f(); // Base는 가짜라 자식껄로 대체함
}

/*
Derived::f() called
Base::f() called
*/

class Base {
public:
	virtual void f() { // 가상 함수, 실제 함수는 자식들이 정의해줄 것.
		cout << "Base::f() called" << endl;
	}
};
class Derived : public Base {
public:
	virtual void f() { // 자식쪽에서는 virtual 쓰든 말든 동일함
		cout << "Derived::f() called" << endl;
	}
};

void ex1121_1() {
	Derived d, * pDer;
	pDer = &d;
	pDer->f();

	Base* pBase = pDer;
	pBase->f(); // Base는 가짜라 자식껄로 대체함
}

/*
Derived::f() called
Derived::f() called
*/

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

void ex1121_4(){
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
void main() {
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