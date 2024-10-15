#include <iostream>
using namespace std;
// 실습 6-1
#include "ram.h"

Ram::Ram() {
	// mem을 0으로 초기화하고 size를 100*1024로 초기화
	size = 100 * 1024;
	for (int i = 0; i < size; i++) {
		mem[i] = 0;
	}
}

Ram::~Ram() {
	cout << "메모리 제거됨" << endl;
}

char Ram::read(int address) {
	// address 주소의 메모리를 읽어 리턴
	return mem[address];
	// 가상의 메모리를 만들고 하는거임... & 붙여서 ㄹㅇ 주소 잡지말자 ㅋㅋ
}

void Ram::write(int address, char value) {
	// address 주소에 value 저장
	mem[address] = value;
}