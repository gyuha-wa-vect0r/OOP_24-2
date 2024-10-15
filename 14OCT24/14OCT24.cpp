#include <iostream> 
#include <string> 
using namespace std;

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

void ex1010_4() {
	Circle2 circleArray[3];
	// Circle circleArray[0], circleArray[1], circleArray[2];
	circleArray[0].radius = 100;
	circleArray[1].radius = 50;
	circleArray[1].radius = 70;

	Circle2* p = &circleArray[1];
	cout << (*p).radius << ' ' << p->radius << endl;

	// 객체배열 초기화 방법
	Circle2 carray[3] = { Circle2(20), Circle2(10), Circle2() };
	Circle2* q;
	q = carray;
	cout << carray[0].radius << " " << q[0].radius << endl;

	q = &carray[1];
	cout << q[-1].radius << " " << q[0].radius << " " << q[1].radius << endl;

}

// 실습 7-2
class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
};

void ex1014_1() {
	Color screenColor(255, 0, 0); // 빨간색의 screenColor 객체 생성
	Color* p; // Color 타입의 포인터 변수 p 선언
	p = &screenColor; // (1) p가 screenColor의 주소를 가지도록 코드 작성
	p[0].show(); // (2) p와 show()를 이용하여 screenColor 색 출력
	Color colors[3]; // (3) Color의 일차원 배열 colors 선언. 원소는 3개
	p = colors; // (4) p가 colors 배열을 가리키도록 코드 작성, p도 주소이고 colors 그 자체도 배열의 머릿부분이기 때문에 주소이다.
	// (5) p와 setColor()를 이용하여 colors[0], colors[1], colors[2]가
	// 각각 빨강, 초록, 파랑색을 가지도록 코드 작성
	p[0].setColor(255, 0, 0); // colors[0]
	p[1].setColor(0, 255, 0); // colors[1]
	p[2].setColor(0, 0, 255); // colors[2] = p[2] = *(p+2)
	// (6) p와 show()를 이용하여 colors 배열의 모든 객체의 색 출력. for 문 이용
	for (int i = 0; i < 3; i++) {
		p[i].show();
	}
	
}

// 실습 7-3
class Person {
	string name;
public:
	Person() { name = ""; }
	Person(string name) { this->name = name; }
	string getName() { return name; }
	void setName(string name) { this->name = name; }
};
class Family {
	string name;
	Person* p; // Person 배열 포인터
	int size; // Person 배열의 크기. 가족 구성원 수
public:
	Family(string name, int size); // size 개수만큼 Person 배열 동적 생성
	void setName(int index, string name);
	void show(); // 모든 가족 구성원 출력
	~Family();
};

void ex1014_2() {
	int A[5];
	A[0] = 100;	A[1] = 200;	A[2] = 300;	A[3] = 400;	A[4] = 500;	
	for (int i = 0; i < 5; i++) {
		printf("%d \n", A[i]);
	}
}

void ex1014_3(int number) {
	int* A = (int*)malloc(number * sizeof(int));
	A[0] = 100;	A[1] = 200;	A[2] = 300;	A[3] = 400;	A[4] = 500;
	for (int i = 0; i < 5; i++) {
		printf("%d \n", A[i]);
	}
}

void ex1014_4(int number) {
	int* A = new int[number];
	// int* A = (int*)malloc(5 * sizeof(int)); // int형 동적메모리 선언, 공식으로 생각해랍니다...
	A[0] = 100;	A[1] = 200;	A[2] = 300;	A[3] = 400;	A[4] = 500;
	for (int i = 0; i < 5; i++) {
		printf("%d, %d \n", A[i], *(A + i));
	}

	delete[] A;
	// free(A); // 동적 걸어주면 꼭 메모리 해제를 해줘야한다...
}

void ex1014_5() {
	ex1014_2();
	ex1014_3(5);
	ex1014_4(5);
}

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

void main() {
	Circle2* p = new Circle2[3];
	cout << p[0].getArea() << endl;
	cout << p[1].getArea() << endl;
	cout << p[2].getArea() << endl;

	Circle2* q = p;
	cout << q[0].getArea() << endl;
	cout << q[1].getArea() << endl;
	cout << q[2].getArea() << endl;

	cout << (*(q + 0)).getArea() << endl; // (q+0)->
	cout << (*(q + 1)).getArea() << endl;
	cout << (*(q + 2)).getArea() << endl;

	cout << (q + 0)->getArea() << endl;
	cout << (q + 1)->getArea() << endl;
	cout << (q + 2)->getArea() << endl;

	delete[] p;
}