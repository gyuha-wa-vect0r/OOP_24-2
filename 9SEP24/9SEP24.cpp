#include <iostream> // 요즘꺼는 .h 안붙임 ㅇㅇ
#include <string> // string 클래스를 사용하기 위한 헤더 파일
using namespace std; // 이걸 쓰면 함수 내에서 std 빼고 그냥 쓰면 됨... like std::cout -> cout

int sep02() {

	cout << "hello" << endl; // printf("hello\n")
	printf("22222hello\n");
	return 0;
}

double f(double r) {
	return 3.14 * r * r;
}

// SEP09에 배운 주제 : cout cin namespace string getline
int sep09_1() {
	
	int n = 3;
	char c = '#';
	cout << c << 5.5 << '-' << n << "hello" << true << endl;  
	// << 사이에는 띄어쓰기가 반영이 안된다...
	// false 는 0, true 는 1
	// 끝에 std::endl == "\n" 하면 줄바꿈 가능

	cout << "n + 5 = " << n + 5 << "\n";
	cout << f(10.0) << "\n";

	double y = f(5.0);
	cout << y << '\n';

	return 0;
}


// 이름공간을 활용하여 같은 명의 함수를 같이 사용
namespace KIM {
	float area(float r) {
		return 3.14 * r * r;
	}
}

namespace KANG {
	float area(float r) {
		return r * 10;
	}
}

int sep09_2() {

	float A = KIM::area(5.0); // KIM 공간에 있는 area 함수 이용
	float B = KANG::area(5.0); // KANG 공간에 있는 area 함수 이용

	cout << A << " / " << B << endl;

	int width, height; // 너비와 높이
	cout << "너비와 높이를 입력하세용 : ";
	cin >> width >> height;
	cout << "너비는 " << width << endl;
	cout << "높이는 " << height << endl;

	return 0;
}

int sep09_3() {

	int a = 100;
	string song = "falling in love with you"; //string 도 int float 등등 처럼 변수의 종류이다.
	//string song("falling in love with you"); 와 같은 말임,, 함수느낌으로 써본것
	cout << song << endl;

	string symbol("!!!!!");
	song = song + symbol;
	
	int index = song.find("love"); //string 헤더에 있는 find 함수 -> 문자열 중에서 어디에 있는지 알려줌

	cout << song << endl;
	cout << index << endl; 

	return 0;
}

int sep09_4() {
	string singer;
	getline(cin, singer); // cin 객체에게 입력을 요청하여 입력 받은 것을 singer에 저장해주는 전역함수
	if (singer == "Kang") {
		cout << "************" << endl;
	}
	else {
		cout << "-----------" << endl;
	}
	
	return 0;
}

int sum(int, int);

int main() {

	int n = 0;

	cout << "끝 수를 입력하세요>> ";
	cin >> n;
	
	if (n <= 0) {
		cout << "양수를 입력하세요!" << endl;
		return 0;
	}
	cout << "1에서 " << n << "까지의 합은 " << sum(1, n) << "입니다.";
	return 0;
}

int sum(int a, int b) {
	int res = 0;

	for (int k = a; k <= b; k++) {
		res += k;
	}

	return res;
}