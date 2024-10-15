#ifndef CAL_H
#define CAL_H
// class를 새로운 헤더로 다 빼버림
// 같이 쓰이는 기능들을 뭔가 틀로 만들어버려서 필요할 때 사용하는 느낌
// 실습 5-4
class Adder { // 덧셈 모듈 클래스
	int op1, op2;
public:
	Adder(int a, int b);
	int process();
};

class Calculator { // 계산기 클래스
public:
	void run();
};

#endif