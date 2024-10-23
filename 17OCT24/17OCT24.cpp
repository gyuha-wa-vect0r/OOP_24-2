#include <iostream> 
#include <string> 
using namespace std;

/*
class Circle2 {
public:
	int radius;
	Circle2(); // 생성자
	Circle2(int r);
	~Circle2(); // 소멸자, 반드시 한 개만 가능
	double getArea(); // 멤버함수 == 메소드

};

void ex1014_6() {
	Circle2 pizza;

	Circle2* p;
	Circle2* q;
	p = new Circle2;
	q = new Circle2(30);

	p = &pizza;

	cout << p->getArea() << endl; //(*p).getArea()와 동일
	cout << q->getArea() << endl; //(*q).getArea()와 동일


	delete p;
	delete q;
}

void ex1014_7() {
	Circle2* p = new Circle2[3];
	cout << p[0].getArea() << endl;
	cout << p[1].getArea() << endl;
	cout << p[2].getArea() << endl;

	Circle2* q = p;
	cout << q[0].getArea() << endl;
	cout << q[1].getArea() << endl;
	cout << q[2].getArea() << endl;

	cout << (*(q + 0)).getArea() << endl; 
	cout << (*(q + 1)).getArea() << endl;
	cout << (*(q + 2)).getArea() << endl;

	cout << (q + 0)->getArea() << endl;
	cout << (q + 1)->getArea() << endl;
	cout << (q + 2)->getArea() << endl;

	delete[] p;
}
*/

// 실습 7-3
class PERSON {
	string name;
public:
	PERSON() { name = ""; }
	PERSON(string name_in) { name = name_in; }
	string getName() { return name; }
	void setName(string name_in) {name = name_in; }
};
class Family {
	string name;
	PERSON* p; // PERSON 배열 포인터, 배열의 주소를 나타낸다
	int size; // PERSON 배열의 크기. 가족 구성원 수
public:
	Family(string name, int size_in);
	void setName(int index, string name);
	void show(); // 모든 가족 구성원 출력
	~Family();
};

Family::Family(string name_in, int size_in) {
	name = name_in;
	size = size_in;
	p = new PERSON[size]; // new? 
}

void Family::setName(int index, string name) {
	p[index].setName(name);
}

void Family::show(){
	cout << name << " 가족은 다음과 같이 " << size << "명 입니다." << endl;
	for (int i = 0; i < 3; i++) {
		cout << p[i].getName() << endl;
	}
}

Family::~Family() {
	delete[] p; // new -> delete
}

void ex1017_1() {
	Family simpson("Simpson", 3); // 3명으로 구성된 Simpson 가족
	simpson.setName(0, "Mr. Simpson");
	simpson.setName(1, "Mrs. Simpson");
	simpson.setName(2, "Bart Simpson");
	simpson.show();
}

// ?
class A {
public:
	int value;
};

class B {
public:
	int counter;
	A sub;
};


void ex1017_2() {
	B abc;
	abc.sub.value = 100; // B 클래스의 sub, 근데 sub은 A 클래스에 속함.!!
	abc.counter = 200; // B 클래스의 counter
}

void main() {
	// int abc = 100;
	int* p = new int; // 포인터배열 1개 선언, 여러개 하고싶다면 new int[10]
	cout << *p << endl;

	delete p; // new와 delete의 관계를 공부해야할 듯... 동적메모리 내용인거같음...
}

// 실습 7-4같은 스타일(클래스의 포인터)는 안 나온다 봄...
// 단 new와 delete에 대해서는 나옴
// int *pInt = new int; // int 타입의 메모리 동적 할당
// delete pInt; // 할당 받은 정수 공간 반환

