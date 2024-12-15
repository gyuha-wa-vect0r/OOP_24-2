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


void main() {
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