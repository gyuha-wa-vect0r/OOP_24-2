#include <iostream>
#include <string>
using namespace std;

// 클래스 만들기
// 멤버 변수, 멤버 함수

class Hello {
public:
	char name;
	int age;
};

class Rect {
public:
	int width;
	int height;
	int getArea();
};

int Rect::getArea() {
	return width * height;
}

int main() {
	Rect rect;
	rect.width = 3;
	rect.height = 5;
	cout << "사각형의 면적은 " << rect.getArea() << endl;
}