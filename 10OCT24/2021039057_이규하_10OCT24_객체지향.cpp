#include <iostream> 
#include <string> 
using namespace std;

class Person {
public:
	double money; // 개인 소유의 돈
	void addMoney(int money) {
		this->money += money;
	}
	Person() { money = 0; } // 생성자
	static int sharedMoney; // 공금, 전역 변수
	static void addShared(int n) {
		sharedMoney += n;
	}
};

// static 변수 생성. 전역 공간에 생성
int Person::sharedMoney = 10; // 10으로 초기화

// main() 함수
void ex1007_4() {
	Person han;
	han.money = 100; // han의 개인 돈=100
	han.sharedMoney = 200; // static 멤버 접근, 공금=200

	Person lee;
	lee.money = 150; // lee의 개인 돈=150
	lee.addMoney(200); // lee의 개인 돈=350
	lee.addShared(200); // static 멤버 접근, 공금=400
	cout << han.money << ' '
		<< lee.money << endl;
	cout << han.sharedMoney << ' '
		<< lee.sharedMoney << endl;
	// static으로 묶여있으면 다른 객체여도 변수를 공유함!
	// 그래서 han이든 lee이든 200으로 출력될 것임...
	// static으로 안 묶여있으면 각자 다른 메모리에 저장됨!
}

// 실습 6-2
class Math {
public:
	static int abs(int a) { return a > 0 ? a : -a; }
	static int max(int a, int b) { return (a > b) ? a : b; }
	static int min(int a, int b) { return (a > b) ? b : a; }
	// 하나의 메모리에 다 사용하게 됩니다!
};

void ex1010_1() {
	// 객체를 안 만들고 static 함수를 호출
	cout << Math::abs(-5) << endl;
	cout << Math::max(10, 8) << endl;
	cout << Math::min(-3, -8) << endl;

	// 객체 A를 만들어서 static 함수를 호출
	Math A;
	cout << A.abs(-5) << endl;
	cout << A.max(10, 8) << endl;
	cout << A.min(-3, -8) << endl;
}

// 실습 6-3
class Person2 { // 클래스 : Person
public:
	int money;
	string name; 
	// 멤버변수 : int money; string name;
	// static int sharedmoney = 0; 얘는 뭐죠?
	Person2() { money = 0; } 
	// Default 생성자 : money = 0으로 초기화
	Person2(string name_in) { money = 0; name = name_in; } 
	// 생성자: Person(string name_in) : money = 0; name = name_in으로 초기화
	~Person2() { cout << name << "의 money는: " << money << endl; }
	// 파괴자 : name과 money 를 출력
	void addMoney(int money_in) { money += money_in; } 
	// addMoney(int money_in) : money_in을 money에 누적
	static int sharedMoney; 
	// 정적변수 : sharedMoney
	static void addShared(int sharedmoney_in) { sharedMoney += sharedmoney_in; }
	//정적멤버함수 : addShared(int sharedmoney_in) : sharedmoney_in를 sharedMoney에 누적
};

int Person2::sharedMoney = 0; 
// !!!!!!!!!static 변수 공간 할당. 프로그램의 전역 공간에 선언!!!!!!!!!!
// 클래스 내에서 static 멤버 함수 선언을 해주고 외부 선언이 없으면 링크 오류뜸니다....!!!!!
// [오류코드]
// LNK2001	확인할 수 없는 외부 기호 "public: static int Person2::sharedMoney" (? sharedMoney@Person2@@2HA)


void ex1010_3() {
	Person2 A("KANG"), B("KIM");
	// 3월
	A.addMoney(100);
	A.addShared(5);
	B.addMoney(200);
	B.addShared(5);
	// 4월
	A.addMoney(100);
	A.addShared(5);
	B.addMoney(200);
	B.addShared(5);
	cout << "공금 = " << Person2::sharedMoney << endl;
	Person2::addShared(100);
	cout << "공금 = " << Person2::sharedMoney << endl;
}

void ex1010_2() {
	Person2 A("KANG");
	A.addMoney(100);
	A.addShared(5);

	Person2* p = &A; // 제일 첫 멤버의 메모리 주소를 pㅇㅔ 저장
	// 변수명에 * 붙어있으면 주소가 들어가는 변수라는 것!
	// p: 주소
	// &A: A의 주소
	// A: 객체
	// *p: 객체(p가 가리키고 있는 객체인 A)

	cout << A.money << " " << (*p).money << " " << p->money << endl;
}

class Circle{ 
public:
	int radius; 
	double getArea() { 
		double area = 3.14 * radius * radius; 
		return area;
	}
};

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

void main() {
	Circle circleArray[3]; 
	// Circle circleArray[0], circleArray[1], circleArray[2];
	circleArray[0].radius = 100;
	circleArray[1].radius = 50;
	circleArray[1].radius = 70;

	Circle* p = &circleArray[1];
	cout << (*p).radius << ' ' << p->radius << endl;

	// 객체배열 초기화 방법
	Circle2 carray[3] = { Circle2(20), Circle2(10), Circle2() };
	Circle2* q;
	q = carray;
	cout << carray[0].radius << " " << q[0].radius << endl;

	q = &carray[1];
	cout << q[-1].radius << " " << q[0].radius << " " << q[1].radius << endl;

}