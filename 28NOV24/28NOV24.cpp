#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <malloc.h>
#include <cmath> // atan2 불러올라면 이게 있어야함

using namespace std;

class Shapeeee {
public:
	virtual void draw() { }
	void paint(Shapeeee*);
};

class Circleee : public Shapeeee {
public:
	virtual void draw() {
		cout << "CIRCLE DRAW" << endl;
		// Circle을 그린다.
	}
};

class Rectttt : public Shapeeee {
public:
	virtual void draw() {
		cout << "RECT DRAW" << endl;
		// Rect을 그린다.
	}
};

class Lineeee : public Shapeeee {
public:
	virtual void draw() {
		cout << "LINE DRAW" << endl;
		// Line을 그린다.
	}
};

void paint(Shapeeee* pShape) {
	pShape->draw();
}

void ex1121_2() {
	paint(new Circleee()); // Circle을 그린다.
	paint(new Rectttt()); // Rect을 그린다.
	paint(new Lineeee()); // Line을 그린다. 
	// -> new 쓰면 객체의 주소를 ...? 알아봐야함
	// Up-Casting
}

void ex1121_3() {
	Circleee C;
	Rectttt R;
	Lineeee L;

	paint(&C);
	paint(&R);
	paint(&L);
}

// 버추얼 여러개 들고있어도 그만큼 다 실행 X


// 실습 11-0
class Shape {
	string name;
public:
	virtual float getArea() { return 0.0; }
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
};
class Oval : public Shape {
	int a, b;
public:
	Oval(string name, int a, int b) {
		setName(name);
		this->a = a;
		this->b = b;
	}
	virtual float getArea() { return 3.14 * a * b; }
};
class Triang : public Shape {
	int a, b;
public:
	Triang(string name, int a, int b) {
		setName(name);
		this->a = a;
		this->b = b;
	}
	virtual float getArea() { return 0.5 * a * b; }
};

void ex1121_4() {
	Oval oval("타원", 10, 20);
	Triang triang("삼각형", 30, 40);

	cout << oval.getName() << "넓이는 " << oval.getArea() << endl;
	cout << triang.getName() << "넓이는 " << triang.getArea() << endl;

	Shape* pShape;
	pShape = &oval; // upcasting
	cout << pShape->getName() << "넓이는 " << pShape->getArea() << endl;
	pShape = &triang; // upcasting
	cout << pShape->getName() << "넓이는 " << pShape->getArea() << endl;
}

/*
void main() {

	// 포인터 쓴거
	Oval_1127* p0;
	Rect_1127* p1;
	Triangular_1127* p2;

	p0 = new Oval_1127("빈대떡", 10, 20);
	p1 = new Rect_1127("찰떡", 30, 40);
	p2 = new Triangular_1127("토스트", 30, 40);

	cout << p0->getName() << " 넓이는 " << p0->getArea() << endl;
	cout << p1->getName() << " 넓이는 " << p1->getArea() << endl;
	cout << p2->getName() << " 넓이는 " << p2->getArea() << endl;

	delete p0; delete p1; delete p2;
}
*/

// 실습 11-0에 포인터로 넘겨버린거
void ex1121_5() {
	Oval* pOval = new Oval("타원", 10, 20);
	// new 를 통해 객체를 만들었기 떄문에 (아래쪽을 봐주세욤)
	Triang* pTriang = new Triang("삼각형", 30, 40);

	cout << pOval->getName() << "넓이는 " << pOval->getArea() << endl;
	cout << pTriang->getName() << "넓이는 " << pTriang->getArea() << endl;


	Shape* pShape;
	pShape = pOval; // upcasting
	cout << pShape->getName() << "넓이는 " << pShape->getArea() << endl;
	pShape = pTriang; // upcasting
	cout << pShape->getName() << "넓이는 " << pShape->getArea() << endl;

	delete pOval;
	delete pTriang;
	// main에서 new으로 만든 두개 delete 걸어주고
	// delete pShape;
	// 얘는 지울게 있나...???? 있으면 안되는 코드입니다.


}

// 실습 11-1
void ex1121_6() {
	Shape* p[5]; // p[0], p[1], p[2], p[3], p[4]
	p[0] = new Oval("타원", 10, 20);
	p[1] = new Triang("삼각형", 30, 40);
	p[2] = new Oval("타원", 10, 20);
	p[3] = new Triang("삼각형", 30, 40);
	p[4] = new Oval("타원", 10, 20);

	for (int i = 0; i < 5; i++) {
		cout << p[i]->getName() << "넓이는 " << p[i]->getArea() << endl;
	}
}

// 강의자료 13주차 11-1 15p

class Base {
public:
	int* data_base; // int data[size]
	int size_base;
	Base() {
		size_base = 0;
		data_base = NULL; // data_base[size]
	}
	Base(int size) {
		size_base = size;
		data_base = new int[size]; // data_base[size]
	}
	virtual void f() { cout << "Base::f() called" << endl; }
	~Base() {
		if (data_base != NULL) delete[] data_base;
		cout << "Base 소멸자" << endl;
	}
};
class Derived : public Base {
public:
	int* data_der;
	int size_der;
	Derived(int size) {
		size_der = size;
		data_der = new int[size];
	}
	void f() { cout << "Derived::f() called" << endl; }
	~Derived() {
		delete[] data_der;
		cout << "Derived 소멸자" << endl;
	}
};
void ex1125_1() {
	Derived* A = new Derived(1000);
	Base* pBase = A;
	delete pBase;
}

// 실습 11-2
class Calculator1 {
public:
	virtual int add(int a, int b) = 0; // 두 정수의 합 리턴
	virtual int subtract(int a, int b) = 0; // 두 정수의 차 리턴
	virtual double average(int a[], int size) = 0; // 배열 a의 평균 리턴. size는 배열의 크기
};

class GoodCalc : public Calculator1 { // public 안쓰면 프라이빗으로 상속됨 ㅇㅇ
	virtual int add(int a, int b) {
		return a + b;
	}
	virtual int subtract(int a, int b) {
		return a - b;
	}
	virtual double average(int a[], int size) {
		double sum = 0.0;
		for (int i = 0; i < size; i++) {
			sum += a[i];
			return sum / size;
		}
	}
	// 위에 함수 세개 퍼블릭 안되어있고 프라이빗으로 걸려있는데 
	// 그래서 부모 함수에서만 컨트롤 가능...부모 거쳐서 자식 컨트롤이 된다는말!
};


void ex1125_2() {
	int a[] = { 1,2,3,4,5 };
	Calculator1* p = new GoodCalc();
	cout << p->add(2, 3) << endl;
	cout << p->subtract(2, 3) << endl;
	cout << p->average(a, 5) << endl;
	delete p;
}

// 실습 11-3
class Calculator {
	void input() { // private
		cout << "정수 2 개를 입력하세요>> ";
		cin >> a >> b;
	}
protected: // 자식에게 물려줄 protected
	int a, b;
	virtual int calc(int a, int b) = 0; // 두 정수의 합 리턴
	// 순수 가상함수... 누군가가 정의해줄거다 -> 자식 클래스에서 했음
public:
	void run() {
		input();
		cout << "계산된 값은 " << calc(a, b) << endl;
	}
};

class Adder : public Calculator {
	virtual int calc(int a, int b) {
		return a + b;
	}
};

class Subtractor : public Calculator {
	virtual int calc(int a, int b) {
		return a - b;
	}
};

void ex1125_3() {
	Adder adder;
	Subtractor subtractor;
	adder.run();
	subtractor.run();
}


// 강의자료 12-1 6p
template <class T> class Stack {
protected:
	int m_size;
	int m_top;
	T* m_buffer;
public:
	Stack() {
		m_buffer = NULL;
		m_size = m_top = 0;
	}
	Stack(int size) {
		m_buffer = new T[size];
		m_size = size;
	}
	~Stack() {
		delete[] m_buffer;
	}
	void Push(T value);
	T Pop();
};

template <class TT> void Stack<TT>::Push(TT value) {
	// Stack<T>라 써줘야됨... 그냥 Stack만 쓰면 오류남
	m_buffer[m_size] = value;
}

void ex1128_1() {
	Stack<int> A; // Stack의 T에 쓸 type를 명시해야함 -> <type>
	Stack<float> B;
}

template <class T1, class T2, int MAX> class TwoArray {
public:
	T1 arr1[MAX];
	T2 arr2[MAX];
};

#define NUMBER 1000

typedef Stack<int> StackInt;
// typedef 문으로 클래스 템플릿의 별명을 정의하면서 템플릿의 파라미터 지정
typedef Stack<int>* pStackInt;

void ex1128_2() {
	TwoArray<int, float, 100> A; // 템플릿 노말 타입
	// TwoArray라는 Template을 t1 타입을 int, t2 타입을 float, MAX = 100으로 지정
	A.arr1[99] = 200;
	A.arr2[50] = 100.0;
	cout << A.arr1[99] << " " << A.arr2[50] << endl;

	TwoArray<int, float, 100>* ptr; // 포인터 쓴거
	ptr = &A;
	cout << ptr->arr1[99] << " " << ptr->arr2[50] << endl;

	TwoArray<int, float, 100>& ref = A;
	cout << ref.arr1[99] << " " << ref.arr2[50] << endl; // 레퍼런스 쓴거, &는 주소 절대 아님ㅋㅋㅋ
}

// 강의자료 12-1 11p
template <class T1, class T2> class GClass {
	T1 data1;
	T2 data2;
public:
	GClass() { data1 = 0; data2 = 0; }
	void set(T1 a, T2 b);
	void get(T1& a, T2& b);
};

template <class T1, class T2> void GClass<T1, T2>::set(T1 a, T2 b) {
	data1 = a; data2 = b;
}

template <class T1, class T2> void GClass<T1, T2>::get(T1& a, T2& b) {
	a = data1; b = data2;
}

void ex1128_3() { // a랑 b swap!
	GClass<int, float> A;
	A.set(100, 200);
	int value1;
	float value2; // int value2라 하면 GClass 선언한거랑 안맞음 ㅇㅇ
	A.get(value1, value2);
	cout << value1 << " " << value2 << endl;
}

void ex1128_4() {
	int a;
	double b;
	GClass<int, double> x;
	x.set(2, 0.5);
	x.get(a, b);
	cout << "a=" << a << "\t" << "b=" << b << endl;

	char c;
	float d;
	GClass<char, float> y;
	y.set('m', 12.5);
	y.get(c, d);
	cout << "c=" << c << "\t" << "d=" << d << endl;
}

// 실습 12-1
/*
int* remove(int src[], int sizeSrc, int minus[], int sizeMinus, int& retSize) {

}
얘를 일반화 하기
*/

template <class T> T* remove(T* src, int sizeSrc, T* Minus, int sizeMinus, int& retSize) {
	T* output = new T[sizeSrc]; // 배열크기를 변수로 받아서 동적할당 ㅇㅇ
	
	int index = 0;

	for (int k = 0; k < sizeSrc; k++) {
		bool equal = false;
		for (int i = 0; i < sizeMinus; i++) {
			if (src[k] == Minus[i]) {
				equal = true;
			}
		}
		if (equal == false) {
			output[index] = src[k];
			index++;
		}
	}

	retSize = index;
	return output;

/*
	for (int j = 0; j < sizeMinus; j++) {
		bool equal = false;
		for (int i = 0; i < sizeSrc; i++) { // 중복 체크
			if (minus[0] == srn[i]) {
				equal = true; // 제외
			}
		}
		if (equal == false) {
			output[j] = src[];

		}
	}
*/	
	

}


void ex1202_1() {
	// remove() 함수를 int로 구체화하는 경우
	cout << "정수 배열 {1,2,3,4}에서 정수 배열 {-3,5,10,1,2,3}을 뺍니다" << endl;
	int x[] = { 1,2,3,-4 };
	int y[] = { -4,5,10,1,2,3 };
	int retSize;
	int* p = remove(x, 4, y, 6, retSize);
	if (retSize == 0) {
		cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
		return;
	}
	else {
		for (int i = 0; i < retSize; i++) // 배열의 모든 원소 출력
			cout << *(p + i) << " "; // *(p+i) = p[i]
		cout << endl;
		delete[] p; // 할당받은 배열 반환
	}

	// remove() 함수를 double로 구체화하는 경우
	// remove() 함수를 int로 구체화하는 경우
	cout << "정수 배열 {1,2,3,4}에서 정수 배열 {-3,5,10,1,2,3}을 뺍니다" << endl;
	double xx[] = { 1,2,3,4 };
	double yy[] = { -4,5,10,1,2,3 };
	int rretSize;
	double* pp = remove<double>(xx, 4, yy, 6, retSize);
	if (retSize == 0) {
		cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
		return;
	}
	else {
		for (int i = 0; i < retSize; i++) // 배열의 모든 원소 출력
			cout << *(p + i) << " "; // *(p+i) = p[i]
		cout << endl;
		delete[] p; // 할당받은 배열 반환
	}
}

#include <vector>

void ex1202_2() {
	vector<int> A; // 1차원 배열
	/*
	templete <class T> class vector {

	}
	로 정의된거랑 동일.
	*/
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << A.at(i) << endl;
	}

	vector<int>::iterator it;

	for (it = A.begin(); it != A.end(); it++) { // 끝주소가 될때까지 참조
		cout << *it << endl;
	}

	A.erase(A.begin()); // 배열 요소 제거
	for (it = A.begin(); it != A.end(); it++) { // 끝주소가 될때까지 참조
		cout << *it << endl;
	}
}

#include <map>

void ex1202_3() {
	map<string, string> dic;
	dic.insert({ "love", "사랑" }); // 앞: key, 뒤: value
	dic.insert({ "human", "휴-먼" }); // 앞: key, 뒤: value

	string kor = dic["love"];
	cout << kor << " " << dic["love"] << " " << dic.at("love") << endl;

	map<int, int> dicInt;
	dicInt.insert({ 100, 200 });
	dicInt.insert({ 200, 400 }); 
	cout << dicInt[200] << " " << dicInt.at(200) << endl;
}

#include <algorithm>

void ex1202_4() {
	vector<char> vec;
	vec.push_back('e');
	vec.push_back('b');
	vec.push_back('a');
	vec.push_back('d');
	vec.push_back('c');

	// sort() 함수를 사용해서 정렬한다.
	sort(vec.begin()+1, vec.end()); 
	// 정렬 후 상태를 출력한다.
	cout << "vector 정렬 후\n"; 
	vector<char>::iterator it; 
	for (it = vec.begin(); it != vec.end(); ++it) 
		cout << *it; 

	// 이번에는 배열을 정렬해보자
	// 임의 문자열을 넣은 배열을 만든다
	char arr[5] = { 'd', 'c', 'b', 'a', 'e'};
	// sort() 함수를 사용해서 정렬한다.
	sort(arr, arr + 5);
	// 정렬 후 상태를 출력한다.
	cout << "배열 정렬 후\n" ;
	for (char* p = arr; p != arr + 5; ++p)
		cout << *p;

	for (auto it = vec.begin(); it != vec.end(); it++) {
		cout << *it;
	}

}

// 실습 12-2

void ex1202_5() {
	map<string, string> dic; // 맵 컨테이너 생성. 키는 영어 단어, 값은 한글 단어
	// 단어 3개를 map에 저장
	dic.insert({ "love", "사랑" }); // ("love", "사랑") 저장
	dic.insert(make_pair("apple", "사과")); // ("apple", "사과") 저장
	dic["cherry"] = "체리"; // ("cherry", "체리") 저장
	cout << "저장된 단어 개수 " << dic.size() << endl;
	string eng;
	while (true) {
		cout << "찾고 싶은 단어>> ";
		cin >> eng; // 사용자로부터 키 입력
		if (eng == "exit")
			break; // "exit"이 입력되면 종료
		if (dic.find(eng) == dic.end()) // eng '키'를 끝까지 찾았는데 없음
			cout << "없음" << endl;
		else
			cout << dic[eng] << endl; // dic에서 eng의 값을 찾아 출력
	}
	cout << "종료합니다..." << endl;
}


template<class T> void removeVect(vector<T>& src, vector<T>& minus, vector<int>& output) {
	for (int i = 0; i < src.size(); i++) {
		bool equal = false;
		for (int j = 0; j < minus.size(); j++)
			if (src[i] == minus[j]) {
				equal = true;
			}
		if (equal == false)
			output.push_back(src[i]);
	}
}


void main() {
	// remove() 함수를 int로 구체화하는 경우
	cout << "정수 배열 {1,2,3,4}에서 정수 배열 {-3,5,10,1,2,3}을 뺍니다" << endl;
	vector<int> x = { 1,2,3,-4 };
	vector<int> y = { -4,5,10,1,2,3 };
	vector<int> output;
	removeVect(x, y, output);
	
	if (output.size() == 0) {
		cout << "공집합" << endl;
	}
	else {
		for (int n = 0; n < output.size(); n++) {
			cout << output[n] << endl;
		}
	}
	
}