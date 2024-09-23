#include <iostream> // ���򲨴� .h �Ⱥ��� ����
#include <string> // string Ŭ������ ����ϱ� ���� ��� ����
using namespace std; // �̰� ���� �Լ� ������ std ���� �׳� ���� ��... like std::cout -> cout

double biggest(double* b, int N) { // �ݺ��� + �Լ�ȭ

	double a_max = *(b+0); // �񱳴�� ���� ����, �迭�� ���� ù ��ҷ� ���� // b[0] = *(b+0) -> b+0 �ּ��� ���빰 
	for (int i = 1; i < N; i++) { if (a_max < *(b+i)) { a_max = *(b+i); } } // b[i] =  *(b+i)

	return a_max; // biggest �Լ� �� ���� (��������)
}

void ex0912_2() {

	double a[7]; // a, a[0], ... , a[6] ���� a�� �迭�� �޸� �ּ�
	int N = 7;

	cout << "7 ���� �Ǽ��� �Է��϶�>>";
	for (int n = 0; n < 7; n++) { cin >> a[n]; }

	double a_max = biggest(a, N); // main �Լ� �� ���� (��������) // a�� �迭 ������ �ּҸ� �Ѱ���

	cout << a_max << endl;

	return;
}

void ex0919_1() {
	int K[3] = { 7, 8, 9 }; // K[0], K[1], K[2]
	int M[4] = { 6, 5, 4, 0 };
	int N[2] = { 1, 2 };

	int* p;
	int* q[3]; // q[0], q[1], q[2] (pointer)

	// ������ ������ ���״�� ���� q[i] = �ּ� ����� �迭 ùĭ�� �ּҰ� K
	q[0] = K; // �迭 K�� �ּҸ� q[0]�� ����
	q[1] = M;
	q[2] = N;

	// K = q[0]; -> ��� �ȸ���, K�� ������ �ּҰ��̱� ������ ������ �ȵ˴ϴ�...

	cout << q[0] << endl;
	cout << *(q[0]) << endl; // K�� ���� ù ��� ������ -> 7

	cout << *(q[0] + 0) << " " << *(q[0] + 1) << " " << *(q[0] + 2) << endl;
	cout << q[0][0] << " " << q[0][1] << " " << q[0][2] << endl;

	cout << *(q[1] + 0) << " " << *(q[1] + 1) << " " << *(q[1] + 2) << " " << *(q[1] + 3) << endl;
	cout << q[1][0] << " " << q[1][1] << " " << q[1][2] << " " << q[1][3] << endl;

	cout << *(q[2] + 0) << " " << *(q[2] + 1) << " " << *(q[2] + 2) << endl;
	cout << q[2][0] << " " << q[2][1] << " " << q[2][2] << endl; // 2���� �迭 �������� ǥ��
	// q[2] = *(q+2) -> q[2][1] : N�迭�� 1��° ���

}

void ex0919_2() {
	
	ex0912_2();

}

void pfunc_1_(int* a, int* b) { // 
	cout << *a << " " << *b << endl;
	*a = 30; // a�� �ּ� *a�� ����
	*b = 40;
}

void ex0919_3() {
	int a = 10, b = 20;
	pfunc_1_(&a, &b); // a�� b ������ �ּҸ� �Լ��� �Ѱ���� �� �Լ������� link �ɾ ���� ������ �ٷ�� �ְ���..?
	cout << a << " " << b << endl;  // main �Լ� �� a�� b��, pfunc_1_ �Լ� �� a�� b�� �ٸ� �޸���ġ�� �Ҵ�ǹǷ� '�ٸ� ����' �̴�.
}

void pfunc_2_(int& c, int& d) { // 
	cout << c << " " << d << endl;
	c = 30; 
	d = 40;
}

void ex0919_3_1() { // no������, �Լ����� ����(&, ���۷���) ���

	int a = 10, b = 20;
	pfunc_2_(a, b); 
	cout << a << " " << b << endl;
}

void ex0919_4() {

	int a = 10;
	int b[5] = { 1, 2, 3, 4, 5 };
	
	int& c = a; 
	// ��� �����Ϳ� �ƹ� ���� ����!!!!!!!!!!!, 'a�� �Ǵٸ� �̸� c', ������ �̿���
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
	if (average(x, sizeof(x)/sizeof(int), avg)) { cout << "����� " << avg << endl; }
	else cout << "�Ű� ���� ����" << endl;
}

// �ǽ� 2-5(����)
bool bigger(int a, int b, int& big) { 
	if (a == b) { return true; }
	else if (a < b) { big = b; return false; }
	else if (a > b) { big = a; return false; }
}

void main() {
	int x, y, big;
	bool b;
	cout << "�� ������ �Է��ϼ��� >> ";
	cin >> x >> y;
	b = bigger(x, y, big);
	if (b)
		cout << "same" << endl;
	else
		cout << "ū ���� " << big << endl;
}