#include <iostream>
using namespace std;
// 실습 5-4
#include "cal.h"
// 클래스에 상속된 다양한 함수를 따로 CPP파일로 분리시킨 것
// 같은 프로젝트 내에 있으니 ㄴ상관!

void Calculator::run() {
	cout << "두 개의 수를 입력하세요>>";
	int a, b;
	cin >> a >> b; // 정수 두 개 입력
	Adder adder(a, b); // 덧셈기 생성
	cout << adder.process(); // 덧셈 계산
}

Adder::Adder(int a, int b) {
	op1 = a; op2 = b;
}
int Adder::process() {
	return op1 + op2;
}