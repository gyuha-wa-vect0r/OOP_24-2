#ifndef ADD_H
#define ADD_H

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

/* 공식
#ifndef ADD_H
#define ADD_H

...

#endif
*/