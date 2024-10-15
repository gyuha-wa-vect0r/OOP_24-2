#include <iostream> 
#include <string> 
using namespace std;

void ex1_2() {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			cout << i << "X" << j << "=" << i * j << " ";
		}
		cout << endl;
	}
}

double biggest_ex1_3(double* list, int num) {
	float big = list[0];
	for (int i = 1; i < num; i++) {
		if (big < list[i]) { big = list[i]; }
	}
	return big;
}

void ex1_3() {
	double a[5];
	cout << "5개의 실수를 입력하라 >> ";

	for (int i = 0; i < 5; i++) { cin >> a[i]; }

	cout << "제일 큰 수 = " << biggest_ex1_3(a, 5) << endl;
}

void ex1_4() {
	char c[100]; // 한 라인에 100개의 문자면 충분하다.
	int count = 0;
	cout << "문자들을 입력하라(100개 미만)." << endl;


	cout << 'x' << "의 개수는 " << count << endl;
}