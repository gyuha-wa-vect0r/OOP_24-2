#ifndef RAM_H
#define RAM_H
// class를 새로운 헤더로 다 빼버림
// 같이 쓰이는 기능들을 뭔가 틀로 만들어버려서 필요할 때 사용하는 느낌
// 실습 6-1

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

#endif
