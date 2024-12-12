#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


// 1
class DynamicArray {
public:
	int* arr;
	int size;
	DynamicArray(int s) {
		this->size = s;
		arr = new int[size];
		for (int i = 0; i < size; ++i) {
			arr[i] = i;
		}
	}
	
	// (1) 여기에 복사 생성자 작성 //5점
	// 클래스명(클래스명& 원본받을변수명) { }
	DynamicArray(DynamicArray& arr1) { // arr1 -> arr2 복붙
		size = arr1.size;
		arr = new int[size]; // 새로운 메모리를 팠기때문에 깊은복사 ㅇㅇ
		for (int i = 0; i < size; i++) {
			arr[i] = arr1.arr[i];
		}
	}
	~DynamicArray() {
		delete[] arr; // 복사생성자에서 팠던 메모리 해제 철저하게 
	}
};
int one() {
	DynamicArray arr1(5);
	// (2) 여기에 arr1을 이용하여 arr2를 생성하세요 // 2점
	DynamicArray arr2 = arr1;
	cout << "arr2 elements: ";
	for (int i = 0; i < arr2.size; ++i) {
		cout << arr2.arr[i] << " ";
	}
	cout << endl;
	return 0;
}

// 2
class FxRect {
	int width, height;
public:
	// (1) 여기에 적절한 생성자를 작성하시오 // 3점
	FxRect() {
		width = 1, height = 1;
	}
	FxRect(int a, int b) {
		width = a, height = b;
	}
	// (2) 여기에 equal()함수를 프렌즈로 선언하시오 // 2점
	friend bool equals(FxRect& a, FxRect& b);
};
// (3) 여기에 프렌드가 될 외부함수를 작성하시오 // 3점
bool equals(FxRect& a, FxRect& b) { // 메모리 같이 쓰게 & 걸어서 참조 해버리죠?
	// 하나 마나 ㄴ상관일거같긴한데...
	return (a.height == b.height && a.width == b.width);
	// 각 객체 참조해서 같다고 묶어야되거든여... 명심하세요!!
}

void two() {
	FxRect a(3, 4), b(4, 5);
	if (equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}

// 3
class FxComplex {
	float re, im;
public:
	FxComplex() { re = im = 0; }
	FxComplex(float re, float im) {
		this->re = re, this->im = im;
	}
	// (1) 여기에 +연산자 중복 코드를 작성하시오 // 4점
	FxComplex operator+(FxComplex b) {
		// 클래스 내부에서는 뒤에꺼만! 앞에꺼는 this->로 해주기
		FxComplex tmp;
		tmp.re = this->re + b.re;
		tmp.im = this->im + b.im;
		return tmp;
	}
	// (2) 여기에 -연산자 중복 코드를 프렌즈로 선언하시오. // 2점
	friend FxComplex operator-(FxComplex a, FxComplex b);
	// 프렌즈는 변수 두개 다!
};
// (3) 여기에 –연산자를 외부 함수로 작성하시오. // 4점
FxComplex operator-(FxComplex a, FxComplex b) {
	FxComplex tmp;
	tmp.re = a.re - b.re;
	tmp.im = a.im - b.im;
	return tmp;
}
void three() {
	FxComplex c1(3.0, 4.0);  // 복소수 3 + 4i
	FxComplex c2(1.0, 2.0);  // 복소수 1 + 2i
	FxComplex c3;

	// 덧셈 연산
	c3 = c1 + c2;

	// 뺄셈 연산
	c3 = c1 - c2;
}

// 4
// 다음 코드에서 ① ~④의 각각에 대해 코드 오류가 있는지 없는지
// (접근가능 여부의 관점에서)와 그 이유를 설명하시오.
class Point {
protected:
	int x, y; //한 점 (x,y) 좌표값
public:
	void set(int x, int y);
};

void Point::set(int x, int y) {
	this->x = x;
	this->y = y;
}

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color);
	bool equals(ColorPoint p);
};

void ColorPoint::setColor(string color) {
	this->color = color;
}

bool ColorPoint::equals(ColorPoint p) {
	if (x == p.x && y == p.y && color == p.color) // 1 // 2점
		// colorpoint 클래스는 point에 상속되어있기에 protect로 묶여있는 x, y 참조 가능
		return true;
	else
		return false;
}
#if 0
int four() {
	Point p;
	p.set(2, 3); // 2 // 2점 -> 오류 없음 p 클래스 멤버 함수 타고 들어가기 때문에 오류 안남
	p.x = 5; // 3 // 2점 -> 클래스에서 x y 가 public으로 되어있는게 아니라서 직접 참조 불가
	p.y = 5; // 얘 또한 3번 항목과 동일함
	ColorPoint cp;
	cp.x = 10; // 4 // 2점 -> cp로 받아도 cp 내 함수로 들어가 참조하는게 아니라 
					       // 바로 함수로 들어가지기 때문에 이거 또한 3번 오류처럼 동일함
	cp.y = 10; // 얘 또한 4번 항목과 동일함
	cp.set(3, 4);
	cp.setColor("Red");
}
#endif // 0

// 5 다음 코드의 출력을 쓰시오(4점).
class FxA {
public:
	FxA() { cout << "생성자 A" << endl; }
	~FxA() { cout << "소멸자 A" << endl; }
};
class FxB : public FxA {
public:
	FxB() { cout << "생성자 B" << endl; }
	~FxB() { cout << "소멸자 B" << endl; }
};
class FxC : public FxB {
public:
	FxC() { cout << "생성자 C" << endl; }
	~FxC() { cout << "소멸자 C" << endl; }
};
int five() {
	FxC c;
	return 0;
}
/* output
* 생성자 A
* 생성자 B
* 생성자 C
* 소멸자 C
* 소멸자 B
* 소멸자 A
*/

// 6
class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	int getRadius() { return radius; }
	double getArea() { return 3.14 * radius * radius; }
};
// 여기에 NamedCircle 클래스를 작성하시오. // 5점
class NamedCircle : public Circle {
public:
	string name;
	NamedCircle(int radius, string name) {
		setRadius(radius); // 부모클래스로 넣기
		this->name = name; // 자식 클래스에 이름 저장
	}
	void show() {
		cout << "반지름이 " << getRadius() << "인 " << name << endl;
		// 부모클래스에서 반지름 빼오고, 자식클래스에서 이름 빼오기
	}
};

void six()
{
	NamedCircle waffle(3, "waffle");
	waffle.show();
}
// 출력 예시 : 반지름이 3인 waffle

// 7 
// 아래 코드의 출력을 쓰고, 그 이유를 설명하시오. 
#if 0
class Base {
public:
	void f() { cout << "Base::f() called" << endl; }
};
class Derived : public Base {
public:
	void f() { cout << "Derived::f() called" << endl; }
};
void seven() {
	Derived d, * pDer; 
	pDer = &d;
	// derived 클래스 d 객체 주소를 pDer 에 저장
	pDer->f(); // pDer의 f 함수 pointing -> derived 클래스로 point!
	Base* pBase; // !!!!!!!
	pBase = pDer;
	// derived 클래스 d 객체 주소를 'Base' 클래스 pBase에 저장!!!
	pBase->f();
	// 주소 자체는 derived 클래스로 point 하고 있지만, 
	// pBase가 Base 클래스이기에 Base내 f 로 pointing!
}
#endif // 0

// 8 
// 문제 7에서 f()를 가상함수로 만드는 코드를 제시하고, 그 출력을 쓰시오.
class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; }
	// 부모 클래스쪽에 virtual 걸어버리기
};
class Derived : public Base {
public:
	void f() { cout << "Derived::f() called" << endl; }
};
void eight() {
	Derived d, * pDer;
	pDer = &d;
	// derived 클래스 d 객체 주소를 pDer 에 저장
	pDer->f(); // pDer의 f 함수 pointing -> derived 클래스로 point!
	Base* pBase; // !!!!!!!
	pBase = pDer;
	// derived 클래스 d 객체 주소를 'Base' 클래스 pBase에 저장!!!
	pBase->f();
	// 주소 자체는 derived 클래스로 point 하고 있지만, 
	// pBase가 Base 클래스이기에 Base내 f 로 pointing!
	
}

// 9 
// 아래 코드에서 main() 내에 문제가 있는 라인을 찾고, 그 이유를 설명하시오. 
#if 0
class Point {
protected:
	int x, y;
public:
	void set(int x, int y);
	void showPoint();
}; 

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color);
	void showColorPoint();
};
// Point와 ColorPoint 멤버함수는 생략되어 있음
void nine() {
	ColorPoint cp;
	ColorPoint* pDer = &cp;
	Point* pBase = pDer;
	pDer->set(3, 4);
	pBase->showPoint();
	pDer->setColor("Red");
	pDer->showColorPoint();
	// pBase->showColorPoint();
	static_cast<ColorPoint*>(pBase)->showColorPoint();
}
#endif // 0

// 10
// 문제 9의 Rectangle 클래스의 3개의 객체로 구성된 객체배열을 선언하는 main함수를 작성하시오.
// (객체배열을 선언하면서 초기값이 설정되도록 작성)(뒷페이지에 출력힌트 있음). 
/*
* m_size : m_buffer의 최대 용량
* m_top : 데이터 들어갈 위치 index, 최초에는 0이며, m_buffer에 3개의 push되었다면 이 값은 3임
* m_buffer : 데이터를 저장할 공간
* Push() : value를 m_buffer에 저장, m_buffer의 용량을 초과하는 push의 경우에는 
           에러메시지 출력하고 문제가 없도록 처리하는 코드 작성
* Pop() : m_buffer에 저장된 값 중 가장 최근에 push한 데이터를 return하고 m_buffer에서 제거함, 
          더이상 pop할 데이터가 없는 경우 에러 메시지를 출력하고 0을 반환함.
*/

// (1) 여기에 필요한 코드 추가(힌트 : 1줄) // 1점
template <typename T> class Stack {
// template 써줘서 T에 대한 자료형 다양화
protected:
	int m_size;
	int m_top;
	T* m_buffer;
public:
	Stack(int size); // m_buffer 메모리 할당
	~Stack(); // m_buffer 메모리 해제
	void Push(T value);
	T Pop();
};
// (2) 여기에 클래스에서 필요한 멤버함수 4개 작성 // 13점
template <typename T> Stack<T>::Stack(int size) {
// template <typename T> 클래스명<템플릿 명>::클래스명(인자)
	m_buffer = new T[size];
}

template <typename T> Stack<T>::~Stack() {
	delete[] m_buffer;
}

template <typename T> void Stack<T>::Push(T value) {
	if (m_top >= m_size) {
		cout << "더 이상 push가 불가능합니다!" << endl;
		return;
	}
	m_buffer[m_top++] = value; // 데이터 삽입 후 위치 증가
}

template <typename T> T Stack<T>::Pop() {
	if (m_top <= 0) {
		cout << "더 이상 pop이 불가능합니다!" << endl;
		return 0;
	}
	return m_buffer[--m_top]; // 위치 감소 후 데이터 반환
}

void ten()
{
	float data[4] = { 100, 200, 300, 400 };
	Stack<float> A(3); // (3) 밑줄친 곳에 들어갈 코드 작성 // 1점
	for (int i = 0; i < 4; i++)
		A.Push(data[i]);
	for (int i = 0; i < 4; i++)
		cout << A.Pop() << endl;
}

// 11
// 이런 미친 문제 왜 이런거임 ㅋㅋ
class Product {
protected:
	string name;
	double price;
public:
	Product(string& n, double p) { name = n; price = p; }
	double getPrice() { return price; }
	// (1) 여기에 showInformation()를 순수가상함수로 작성 // 2점
};
class myBook : public Product {
private:
	int pageCount;
public:
	// (2) 여기에 생성자 작성(부모 클래스 생성자도 같이 초기화 되도록) // 2점
	// (3) 여기에 myBook에 대한 showInformation() 코드 작성 // 2점
};
class Clothing : public Product {
private:
	string size;
public:
	// (4) 여기에 생성자 작성(부모 클래스 생성자도 같이 초기화 되도록) // 2점
	// (5) Clothing에 대한 showInformation() 코드 작성 // 2점
};
// (6) 이 줄에 필요한 코드 작성(힌트 : 1줄) // 1점
class ShoppingCart {
public:
	vector<T> items;
	void addItem(T& item) {
		items.push_back(item);
	}
	// (7) 여기에 calculateTotalPrice() 코드 작성 // 3점
};
int main() {
	Product* book = new myBook((string)"The C++ Programming Language", 49.99, 700);
	Product* shirt = new Clothing((string)"Cool T-shirt", 19.99, (string)"XXLarge");
	ShoppingCart<Product*> cart;
	cart.addItem(book); // cart에 book 담기
	cart.addItem(shirt); // cart에 shirt 담기
	for (int i = 0; i < cart.items.size(); i++) // cart item 정보 모두 출력
		cart.items[i]->showInformation();
	cout << "Total Price: $" << cart.calculateTotalPrice() << "\n"; // cart에 담긴 item의 총가격delete book; delete shirt;
	return 0;
}
/* 출력
이름 : The C++ Programming Language, 가격 : $49.99
책 페이지 수 : 700
이름 : Cool T-shirt, 가격 : $19.99
옷 사이즈 : XXLarge
Total Price: $69.98
*/