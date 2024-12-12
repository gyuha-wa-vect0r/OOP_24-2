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

	cin.getline(c, 100);
	for (int i = 0; i < 100; i++) {
		if (c[i] == 'x') { count++; }
	}

	cout << 'x' << "의 개수는 " << count << endl;
}

void ex1_5() {
	char password1[100], password2[100];
	cout << "새 암호를 입력하세요 >> ";
	cin >> password1;
	cout << "새 암호를 다시 한번 입력하세요 >> ";
	cin >> password2;
	
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (password1[i] == password2[i]) {
			count++;
		}
	}
	if (count == 100) { cout << "같습니다." << endl; }
	else { cout << "같지 않습니다." << endl; }
}

void ex1_6() {
	char name[100];
	char address[100];
	int age;

	cout << "이름은?";
	cin.getline(name, 100);
	cout << "주소는?";
	cin.getline(address, 100);
	cout << "나이는?";
	cin >> age;

	cout << name << ". " << address << ". " << age << "세" << endl;
}

// 실습 1-7
namespace KIM {
	float area(float r) {
		return 3.14 * r * r;
	}
}
namespace KANG {
	float area(float x, float y) {
		return x * y;
	}
}
void main()
{
	float A = KIM::area(10.0);
	float B = KANG::area(2, 3);
	cout << A << " / " << B << endl;
}