#include <iostream> 
#include <string> 
using namespace std;

/*
void myswap(int& a, int& b) { // a <-> b swap
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
void myswap(double& a, double& b) {
	double tmp;
	tmp = a;
	a = b;
	b = tmp;
}
*/

// �Լ��� Ŭ������ �Ϲ�ȭ���׽�.. ���� �� �Լ��� �ϳ��� ���ƴٰ� ���� �˴ϴ�
// <class T> �� ������ <typename T> �� ������ �����
template <class T> void myswap(T& a, T& b) {
	T tmp; // int�� double�̳� �� �ȴٴ°�~~~ T�� ��ǥ�� ������
	tmp = a;
	a = b;
	b = tmp;
}

void ex0926_1() {
	int a = 4, b = 5;
	myswap(a, b); // myswap(int& a, int& b) ȣ��
	cout << a << '\t' << b << endl; // myswap()�� ���� swap�� a b ���
	double c = 0.3, d = 12.5;
	myswap(c, d); // myswap(double& a, double& b) ȣ��
	cout << c << '\t' << d << endl;
}

// �ǽ� 3-3
template <class K> K add(K* a, int b) {
	K sum = 0;
	for (int i = 0; i < b; i++) { sum += a[i];}
	return sum;
}

void ex0926_2() {
	int x[] = { 1,2,3,4,5 };
	double d[] = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.7 };
	float y[] = { 1, 2, 3, 4, 5, 6 };

	cout << "sum of x[] = " << add(x, 5) << endl; // �迭 x�� ���� 5���� ���� ���
	cout << "sum of d[] = " << add(d, 6) << endl; // �迭 d�� ���� 6���� ���� ���
	cout << "sum of y[] = " << add(y, 6) << endl; // �迭 d�� ���� 6���� ���� ���
}

class Circle { // Ŭ������ �� ����
public:
	int radius; // ���� Ŭ���� �������� ��������ó�� ��밡��, 
	double getArea() { // �Լ��� �ζ����Լ��� �ڵ� �����ϴ� ���
		double area = 3.14 * radius * radius; // class���� radius ���� �Ǿ����Ƿ� �Լ� �������� �� ��
		return area;
	}
private:
	//int radius
};
// class���� public �Ƚ��ָ� ����Ʈ�� private�Ӵϴ�.

/*
double Circle::getArea() { // Ŭ������ �Ҽӵ� ��� �Լ���� �ް�����
	double area = 3.14 * radius * radius; // class���� radius ���� �Ǿ����Ƿ� �Լ� �������� �� ��
	return area;
}
*/

void ex0926_3() {
	Circle A, B, C; // Circle Ŭ������ ��ü�� A Ÿ�� B Ÿ�� C Ÿ������ ����
	A.radius = 10; // A ��ü�� ������ ����
	cout << A.getArea() << endl;

	int a; // ���� ����
	int* b; // �ּҸ� ����

	Circle* p = &A; // 64��Ʈ �����ͺ��� //�� ���� �����ֽŴٰ� ��...
	cout << (*p).radius << endl; // p �ּ��� �ִ� ���빰 Ŭ������ radius ���
	cout << p->radius << endl;
	cout << (*p).getArea() << endl;
	cout << p->getArea() << endl;
}

// �ǽ� 4-3
class Rectangle {
public: // �̰� �Ⱦ��� �����̺��̶� ��¯���繬�Դϴ�...
	int width, height;
	int getArea();
	/*
	int getArea() { // Class ���� �Լ� �ֱ� (�ζ����Լ�)
		int output = width * height;
		return output;
	} // output�� getArea �Լ� ���� ��������!
	*/
};

int Rectangle::getArea() { // Class �ܿ� �Լ� �ֱ� 
	int output = width * height;
	return output;
} // output�� getArea �Լ� ���� ��������!

void ex0926_4() {
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	cout << "�簢���� ������ " << rect.getArea() << endl;
}

class Rectangle2 {
private: // �ܺ� ���� ����
	int width, height;

public: 
	int getArea() {
		int output = width * height;
		return output;
	}
	bool setWidth(int input) {
		if (input < 0) return false;
		else {
			width = input;
			return true;
		}
	}
	bool setHeight(int input) {
		if (input < 0) return false;
		else {
			height = input;
			return true;
		}
	}
	// void setWidth(int input) { width = input; }
	// void setHeight(int input) { height = input; }
	int getWidth() { return width; }
	int getHeight() { return height; }
	// Ŭ���� ���� �������� �����̺��� �ۺ� ������� �� ��� ����!
		
	
};

void ex0926_5() {
	Rectangle2 rect;
	// rect.setWidth(3); // width = 3
	if (rect.setWidth(3) == false) {
		cout << "width error" << endl; return; 
	}
	//rect.setHeight(5); // height = 5
	if (rect.setHeight(5) == false) {
		cout << "height error" << endl; return; 
	}
	cout << "�ʺ� " << rect.getWidth() << endl;
	cout << "���� " << rect.getHeight() << endl;
	cout << "�簢���� ������ " << rect.getArea() << endl;
}
// ���Ͷ� ��Ʈ���� ��������!!


class Circle2 {
public:
	int radius;
	Circle2(); // ������
	Circle2(int r);
	double getArea();
};

Circle2::Circle2() {

}

Circle2::Circle2(int r) {

}

double Circle2::getArea() {
	return 3.14 * radius * radius;
}
