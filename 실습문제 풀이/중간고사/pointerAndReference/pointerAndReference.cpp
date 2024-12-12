/*
포인터는 변수의 주소를 나타냄 *(변수명) 
변수의 주소는 변수에 할당된 제일 첫번째 바이트의 주소 &(변수명)
ex: int k; int* a = &k; a는 일반적인 값을 받지 않고, k 변수의 주소를 저장하겠다!

b[4] 라는 배열이 선언되었을 때, 배열명 b는 배열에 할당된 제일 첫번째 바이트 주소
int* a = b; 라고 하면, a에는 b[0]의 주소가 저장된다.


*/

#include <iostream>
#include <string> 
using namespace std;

void lecture2_1_3p() {
	int arr[6] = { 1,2,3,4,5,6 };
	int *chr_ptr; // 1) int에 대한 포인터 변수 chr_ptr을 선언하는 문장 작성
	// chr_ptr이 arr 배열이 저장되어 있는 메모리 주소값을 갖도록 초기화.
	chr_ptr = arr;
	chr_ptr++; // chr_ptr의 값을 하나 증가
	cout << chr_ptr << "\n"; // 3) 옆 문장이 실행되었을 때의 결과는?  arr[1]의 주소 O
	cout << *chr_ptr << "\n"; // 4) 옆 문장이 실행되었을 때의 결과는? 2 O
	cout << arr << "\n"; // 5) 옆 문장이 실행되었을 때의 결과는? arr[0]의 주소 O
	cout << arr + 4 << "\n"; // 6) 옆 문장이 실행되었을 때의 결과는? 5 X -> arr[4]의 주소를 나타냄!!
	cout << &arr[3] << "\n"; // 7) 옆 문장이 실행되었을 때의 결과는? arr[3]의 주소 O
	cout << arr[4] << "\n"; // 5
	// arr[3]의 값을 chr_ptr을 이용하여 프린트 
	cout << *chr_ptr + 2 << endl; // *chr_ptr + 3 X -> 이미 chr_ptr++; 을 위에서 했기(arr[1]인 상태) 때문에... +2이어야 arr[4]를 참조함

}

void sep12() {
	int K[3] = { 7, 8, 9 };
	int M[3] = { 6, 5, 4 };
	cout << K << " " << &K[0] << " " << &K[1] << " " << &K[2] << endl; // &K[i]는 K배열 내 i번째 칸의 주소값
	// K는 배열 처음의 주소 = &K[0] 또한 첫 칸의 주소

	int* p = K; // k에 저장된 주소 값을 p에 저장, 이때 * 는 이 변수가 주소를 저장하는 변수임을 나타내고
	cout << p << " " << p[0] << " " << p[1] << " " << p[2] << endl;
	// K 자체도 이미 주소인 변수이고 p 또한 동일하기에 p에 [] 붙여서 참조하는거 가능
	cout << *p << " " << *(p + 1) << " " << *(p + 2) << endl;
	// 여기서의 *는 그 주소의 내용물을 참조하겠다는...
	// 주소 p에 i를 더하면 현 위치에서 i번째 이후의 방 위치 주소를 나타냄

	p = &K[2]; // p에는 k배열의 3번째 칸 주소를 저장
	cout << *p << " " << *(p - 1) << " " << *(p - 2) << endl; // 9(세번째)  8(두번째)  7(첫번째)
	cout << p[0] << " " << p[-1] << " " << p[-2] << endl; // 9  8  7 -> 음수 ㄴ상관인건 배열에 확실히 요소를 잡고있기 때문...
	
	// &nArray[i] == nArray+2
	// int* p = nArray, nArray[i] == p[i] 
}

// 2차원 배열
void secondchawon() {
	const char* ptr_ary[5]; // ptr_ary만 선언하면 1차원 배열, 거기에 5칸짜리 배열을 더 팠으니까 2차원배열~
	int i;

	ptr_ary[0] = "dog";
	ptr_ary[1] = "elephant";
	ptr_ary[2] = "horse";
	ptr_ary[3] = "tiger";
	ptr_ary[4] = "lion";

	for (i = 0; i < 5; i++) {
		cout << ptr_ary[i] << "\n";
	}
}

/*
포인터랑은 다른 레퍼런스 Reference!
포인터에서는 int* a 라고 했으면
레퍼런스에서는 int& a = ??? 라고 해야된다.
단독 선언만은 할 수 없으며 뒤에 초기화를 해야하는데, 기존 변수에 대해 별칭을 정한다 생각하면 될 듯~.


*/
void pfunc_2_(int& c, int& d) { // 
	cout << c << " " << d << endl;
	c = 30;
	d = 40;
}

void reference1() { // no포인터, 함수에서 참조(&, 레퍼런스) 사용

	int a = 10, b = 20;
	pfunc_2_(a, b);
	cout << a << " " << b << endl;
}

//다음 프로그램을 실행시켜, 실행 결과를 통해 배열의 이름 및 주소, 
//배열 포인터 등의 쓰임에 대해 분석해본다. ㅇㅋ
void ex2_1() {
	int K[3] = { 7, 8, 9 }; // 크기 3짜리 배열 선언
	int M[3] = { 6, 5, 4 }; // 크기 3짜리 배열 선언
	int* p; int* q[2]; // 주소를 저장할 포인터 변수 p와 포인터 배열 q[2] 선언 
	cout << K << " " << &K[0] << " " << &K[1] << " " << &K[2] << endl;
	// 출력: K[0]주소 K[0]주소 K[1]주소 K[2]주소
	p = K; // p는 K[0]의 주소를 저장함
	cout << p[0] << " " << p[1] << " " << p[2] << endl;
	// 출력: K[0]주소 K[1]주소 K[2]주소
	cout << *(p + 0) << " " << *(p + 1) << " " << *(p + 2) << endl;
	// 출력: K[0]값 K[1]값 K[2]값
	p = M; // p는 M[0]의 주소를 저장함
	cout << p[0] << " " << p[1] << " " << p[2] << endl;
	// 출력: M[0]주소 M[1]주소 M[2]주소
	cout << *(p + 0) << " " << *(p + 1) << " " << *(p + 2) << endl;
	// 출력: M[0]값 M[1]값 M[2]값
	q[0] = K; q[1] = M; // q[0]에 K[0] 주소를 저장, q[1]에 M[0] 주소를 저장
	cout << q[0][0] << " " << q[0][1] << " " << q[0][2] << endl;
	// 출력: K[0]값 K[1]값 K[2]값
	cout << *(q[0] + 0) << " " << *(q[0] + 1) << " " << *(q[0] + 2) << endl;
	// 출력: K[0]값 K[1]값 K[2]값
	cout << q[1][0] << " " << q[1][1] << " " << q[1][2] << endl;
	// 출력: M[0]값 M[1]값 M[2]값
	cout << *(q[1] + 0) << " " << *(q[1] + 1) << " " << *(q[1] + 2) << endl;
	// 출력: M[0]값 M[1]값 M[2]값
}

//2-2
// 기존 결과
// 10 20
// 10 20
void pfunc_1_(int &a, int &b)
{
	cout << a << " " << b << endl;
	a = 30; b = 40;
}

void ex2_2() {
	int a = 10, b = 20;
	pfunc_1_(a, b);
	cout << a << " " << b << endl;

}

//2-3
/*
결과
000000175F3FFB98 000000175F3FFB98
000000175F3FFBA4 000000175F3FFBA4
000000175F3FFBA4 000000175F3FFBA4 000000175F3FFBA4 000000175F3FFBA4
4 4 4 4
000000175F3FFB98 000000175F3FFB98 000000175F3FFB98
000000175F3FFB9C 000000175F3FFB9C 000000175F3FFB9C
2 2 2
000000175F3FFB98 000000175F3FFB98
1 1
*/
void ex2_3() {
	int M[3][3] = { {1,2,3},{4,5,6},{7,8,9} }; // 3*3 2차원 배열 선언 및 초기화
	int (*ptr)[3]; int* p; int** pt; 
	// 크기 ?*3짜리 배열의 주소를 저장할 포인터변수 ptr, 변수의 주소를 저장할 포인터 변수 p, 
	// 변수의 주소를 저장할 포인터 변수 p의 주소를 저장할 포인터 변수 q(2중 포인터)
	ptr = M; // 배열 M의 주소를 ptr에 저장
	cout << ptr << " " << M << endl; // 출력: M[0][0]주소 M[0][0]주소
	cout << ptr + 1 << " " << M + 1 << endl; // 출력: M[1]주소(=(ptr+1)+0=M[1][0]) M[1]주소(=M[1][0]) 
	cout << *(ptr + 1) << " " << ptr[1] << " " << *(M + 1) << " " << M[1] << endl; 
	// M[1][0]주소(M[1]내에서 포인터를 다시 돌리는거니까!) M[1]주소(=M[1][0]) M[1]주소(=M[1][0]) M[1][0]주소
	cout << **(ptr + 1) << " " << **(M + 1) << " " << *M[1] << " " << M[1][0] << endl;
	// M[1]을 가리키는 주소에 있는 0번째 배열(M[1][0])값 M[1]을 가리키는 주소에 있는 0번째 배열(M[1][0])값
	// M[1]을 가리키는 주소에 있는 0번째 배열(M[1][0])값 M[1][0]값
	p = M[0]; //포인터 변수 p에 M[0]의 주소 저장(=M[0][0]) -> M[0] 내에서만 해결하겠네요
	cout << p << " " << M[0] << " " << *M << endl;
	// M[0]주소 M[0]주소 M[0]주소 (M[0]~[2] 중 M[0]의 [0]~[2]중 [0]의 주소)
	cout << p + 1 << " " << M[0] + 1 << " " << *M + 1 << endl;
	// M[0][1]주소 M[0][1]주소 M[0][1]주소
	cout << *(p + 1) << " " << *(M[0] + 1) << " " << *(*M + 2) << endl;
	// M[0][1]내용 M[0][1]내용 M[0][1]내용
	// M은 M[0]의 주소이고 *M는 M[0][0]의 주소, *M + 2은 M[0][2]의 주소
	// 그럼 *M + 1은 M[0][1]의 주소, *(*M + 2)은 M[0][2]의 내용
	// 그럼 그냥 *M은 M[0]일 뿐, 그기에 수를 더해도 M[0]내 요소 탐색한다는거네...
	// 아하!
	pt = &p; // pt = M; (X) // p의 주소 = M[0]의 주소 = M의 주소를 pt에 저장
	cout << *pt << " " << p << endl; // M[0]주소 M[0]주소
	cout << **pt << " " << *p << endl; // M[0]주소에 있는 값 M[0]주소에 있는 값

	// 아!!!! *(M[1]+2) == M[1][2] 이 오직 값을 나타낸거처럼 2차원배열 안까진 주소로 못내는구나!
	// 휴...

}

// 2-4
bool average(int a[], int size, int& avvggg) {
	// avg를 average 함수 내에서 avvggg라는 이름으로 쓰겠다.
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i];
	}
	return avvggg = sum / size;
}
void ex2_4() {
	int x[] = { 0,1,2,3,4,5 };
	int avg;
	if (average(x, sizeof(x) / sizeof(int), avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류" << endl;
}

// 2-5
bool bigger(int a, int b, int& big) {
	if (a == b) {
		return 1;
	}
	else if (a > b) {
		big = a;
		return 0;
	}
	else if (a < b) {
		big = b;
		return 0;
	}
}

void ex2_5() {
	int x, y, big;
	bool b;
	cout << "두 정수를 입력하세요>> ";
	cin >> x >> y;
	b = bigger(x, y, big);
	if (b)
		cout << "same" << endl;
	else
		cout << "큰 수는 " << big << endl;
}

// 2-6
char& find(char a[], char c, bool& success) {
	for (int i = 0; i < (sizeof(c) / sizeof(int)), i++) {
		if (a[i] == "M") {
			return ;
			break;
		}
	}
}

void main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M을 발견할 수 없다" << endl;
	}
	loc = 'm'; // 'M' 위치에 'm' 기록
	cout << s << endl; // "mike"가 출력됨
}

// 으에... 2-6 무슨말임 ㅋㅋ
