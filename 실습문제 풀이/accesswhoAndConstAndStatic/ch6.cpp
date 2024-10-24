#include <iostream>
#include <string>
using namespace std;

/* to ram.h
class Ram {
	char mem[100 * 1024]; // 100KB 메모리
	int size;
public:
	Ram(); // mem을 0으로 초기화하고 size를 100*1024로 초기화
	~Ram(); // "메모리 제거됨" 문자열 출력
	char read(int address); // address 주소의 메모리를 읽어 리턴
	void write(int address, char value); // address 주소에 value 저장
	// 주소가 범위를 벗어나는 오류 발생하면 에러메시지 출력함.
};
*/

/* to func.cpp
Ram::Ram() {
	size = 100 * 1024;
	for (int i = 0; i < size; i++) {
		mem[i] = 0;
	}
}
Ram::~Ram() {
	cout << "메모리 제거됨" << endl;
}

char Ram::read(int address) {
	return mem[address];
}

void Ram::write(int address, char value) {
	mem[address] = value;
}
*/

//#include "ram.h"
/*
int ex6-1() {
	Ram ram;
	ram.write(100, 20); // 100 번지에 20 저장
	ram.write(101, 30); // 101 번지에 30 저장
	char res = ram.read(100) + ram.read(101); // 20 + 30 = 50
	ram.write(102, res); // 102 번지에 50 저장
	cout << "102 번지의 값 = " << (int)ram.read(102) << endl; // 102 번지 메모리 값 출력
}
*/ 

// 6-2
class Math {
public:
	static int abs(int a);
	static int max(int a, int b);
	static int min(int a, int b);
};

int Math::abs(int a) {
	return ((a > 0) ? a : -a);
}
int Math::max(int a, int b) {
	return ((a > b) ? a : b);
}
 int Math::min(int a, int b) {
	return ((a > b) ? b : a);
}

void ex6_2() {
	Math a;
	cout << a.abs(-5) << endl;
	cout << a.max(10, 8) << endl;
	cout << a.min(-3, -8) << endl;
}

// 6-3
class Person {
public:
	int money;
	string name;
	static int sharedMoney;
	Person() { money = 0; }
	Person(string name_in) { money = 0; name = name_in; }
	~Person() { cout << name << "'s money = " << money << endl; }
	void addMoney(int money_in) { money += money_in; }
	static void addShared(int sharedmoney_in) { sharedMoney += sharedmoney_in;  }
	
};
int Person::sharedMoney = 0;

void main() {
	Person A("KANG"), B("KIM");
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
	cout << "공금 = " << Person::sharedMoney << endl;
	Person::addShared(100);
	cout << "공금 = " << Person::sharedMoney << endl;
}