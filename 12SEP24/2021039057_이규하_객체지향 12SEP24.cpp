#include <iostream> // 요즘꺼는 .h 안붙임 ㅇㅇ
#include <string> // string 클래스를 사용하기 위한 헤더 파일
using namespace std; // 이걸 쓰면 함수 내에서 std 빼고 그냥 쓰면 됨... like std::cout -> cout

void ex0912_1() {
	double a[5];
	cout << "5 개의 실수를 입력하라>>";
	for (int n = 0; n < 5; n++) {
		cin >> a[n];
	}

	double a_max = a[0]; // 비교대상 기준 생성, 배열의 가장 첫 요소로 지정
	if (a_max < a[1]) { a_max = a[1]; }
	if (a_max < a[2]) { a_max = a[2]; }
	if (a_max < a[3]) { a_max = a[3]; }
	if (a_max < a[4]) { a_max = a[4]; }
	
	/* // 반복문을 써보자면,,,
	for (int i = 1; i < 5; i++) {
		if (a_max < a[i]) {a_max = a[i];}
	}
	*/
	cout << a_max << endl;

	// for (int n = 0; n < 5; n++) { cout << a[n] << endl; } // 입력받은 내용 다 출력

	return;
}


double biggest(double b[], int N) { // 반복문 + 함수화

	double a_max = b[0]; // 비교대상 기준 생성, 배열의 가장 첫 요소로 지정
	for (int i = 1; i < N; i++) { if (a_max < b[i]) { a_max = b[i]; } }

	return a_max; // biggest 함수 내 변수 (지역변수)
}


void ex0912_2() {

	double a[7]; // a, a[0], ... , a[6] 에서 a는 배열의 메모리 주소
	int N = 7;

	cout << "7 개의 실수를 입력하라>>";
	for (int n = 0; n < 7; n++) { cin >> a[n]; }
	
	double a_max = biggest(a, N); // main 함수 내 변수 (지역변수)
	
	cout << a_max << endl;

	return;
}

void main() {
	int K[3] = { 7, 8, 9 };
	int M[3] = { 6, 5, 4 };
	cout << K << " " << &K[0] << " " << &K[1] << " " << &K[2] << endl; // &K[i]는 K배열 내 i번째 칸의 주소값
	// K는 배열 처음의 주소 = &K[0] 또한 첫 칸의 주소

	int* p = K; // k의 주소 값을 p에 저장, 이때 * 는 이 변수가 주소를 저장하는 변수임을 나타내고
	cout << p << " " << p[0] << " " << p[1] << " " << p[2] << endl;
	cout << *p << " " << *(p + 1) << " " << *(p + 2) << endl;
	// 여기서의 *는 그 주소의 내용물을 참조하겠다는...
	// 주소 p에 i를 더하면 현 위치에서 i번째 이후의 방 위치를 나타냄

	p = &K[2];
	cout << *p << " " << *(p - 1) << " " << *(p - 2) << endl; // 9  8  7
	cout << p[0] << " " << p[-1] << " " << p[-2] << endl; // 9  8  7 -> 음수 ㄴ상관인건 배열에 확실히 요소를 잡고있기 때문...

}