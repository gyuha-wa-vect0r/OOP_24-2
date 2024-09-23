#include <iostream> // 요즘꺼는 .h 안붙임 ㅇㅇ
#include <string> // string 클래스를 사용하기 위한 헤더 파일
using namespace std; // 이걸 쓰면 함수 내에서 std 빼고 그냥 쓰면 됨... like std::cout -> cout

double biggest(double* b, int N) { // 반복문 + 함수화

	double a_max = *(b+0); // 비교대상 기준 생성, 배열의 가장 첫 요소로 지정 // b[0] = *(b+0) -> b+0 주소의 내용물 
	for (int i = 1; i < N; i++) { if (a_max < *(b+i)) { a_max = *(b+i); } } // b[i] =  *(b+i)

	return a_max; // biggest 함수 내 변수 (지역변수)
}

void ex0912_2() {

	double a[7]; // a, a[0], ... , a[6] 에서 a는 배열의 메모리 주소
	int N = 7;

	cout << "7 개의 실수를 입력하라>>";
	for (int n = 0; n < 7; n++) { cin >> a[n]; }

	double a_max = biggest(a, N); // main 함수 내 변수 (지역변수) // a는 배열 시작의 주소를 넘겨줌

	cout << a_max << endl;

	return;
}

void ex0919_1() {
	int K[3] = { 7, 8, 9 }; // K[0], K[1], K[2]
	int M[4] = { 6, 5, 4, 0 };
	int N[2] = { 1, 2 };

	int* p;
	int* q[3]; // q[0], q[1], q[2] (pointer)

	// 포인터 변수는 말그대로 변수 q[i] = 주소 상수는 배열 첫칸의 주소값 K
	q[0] = K; // 배열 K의 주소를 q[0]에 저장
	q[1] = M;
	q[2] = N;

	// K = q[0]; -> 얘는 안먹힘, K는 고정된 주소값이기 때문에 변동이 안됩니더...

	cout << q[0] << endl;
	cout << *(q[0]) << endl; // K의 가장 첫 요소 포인팅 -> 7

	cout << *(q[0] + 0) << " " << *(q[0] + 1) << " " << *(q[0] + 2) << endl;
	cout << q[0][0] << " " << q[0][1] << " " << q[0][2] << endl;

	cout << *(q[1] + 0) << " " << *(q[1] + 1) << " " << *(q[1] + 2) << " " << *(q[1] + 3) << endl;
	cout << q[1][0] << " " << q[1][1] << " " << q[1][2] << " " << q[1][3] << endl;

	cout << *(q[2] + 0) << " " << *(q[2] + 1) << " " << *(q[2] + 2) << endl;
	cout << q[2][0] << " " << q[2][1] << " " << q[2][2] << endl; // 2차원 배열 형식으로 표현
	// q[2] = *(q+2) -> q[2][1] : N배열의 1번째 요소

}

void ex0919_2() {
	
	ex0912_2();

}

void pfunc_1_(int* a, int* b) { // 
	cout << *a << " " << *b << endl;
	*a = 30; // a는 주소 *a는 내용
	*b = 40;
}

void ex0919_3() {
	int a = 10, b = 20;
	pfunc_1_(&a, &b); // a와 b 변수의 주소를 함수로 넘겨줘야 그 함수에서도 link 걸어서 직접 변수를 다룰수 있겠죠..?
	cout << a << " " << b << endl;  // main 함수 내 a와 b랑, pfunc_1_ 함수 내 a와 b는 다른 메모리위치에 할당되므로 '다른 변수' 이다.
}

void pfunc_2_(int& c, int& d) { // 
	cout << c << " " << d << endl;
	c = 30; 
	d = 40;
}

void ex0919_3_1() { // no포인터, 함수에서 참조(&, 레퍼런스) 사용

	int a = 10, b = 20;
	pfunc_2_(a, b); 
	cout << a << " " << b << endl;
}

void ex0919_4() {

	int a = 10;
	int b[5] = { 1, 2, 3, 4, 5 };
	
	int& c = a; 
	// 얘는 포인터와 아무 관련 없음!!!!!!!!!!!, 'a의 또다른 이름 c', 참조를 이용함
	cout << c << endl;

	c = b[3];
	cout << c << endl;

}

bool average(int* a, int size, float& avg) {
	avg = 0.0;
	for (int i = 0; i < size; i++) {
		avg += a[i];
	}
	avg /= size;

	return true;
}

void ex0919_5() {
	int x[] = { 0, 1, 2, 3, 4, 5 };
	float avg;
	if (average(x, sizeof(x)/sizeof(int), avg)) { cout << "평균은 " << avg << endl; }
	else cout << "매개 변수 오류" << endl;
}

// 실습 2-5(과제)
bool bigger(int a, int b, int& big) { 
	if (a == b) { return true; }
	else if (a < b) { big = b; return false; }
	else if (a > b) { big = a; return false; }
}

void main() {
	int x, y, big;
	bool b;
	cout << "두 정수를 입력하세요 >> ";
	cin >> x >> y;
	b = bigger(x, y, big);
	if (b)
		cout << "same" << endl;
	else
		cout << "큰 수는 " << big << endl;
}