#include <iostream> // ���򲨴� .h �Ⱥ��� ����
#include <string> // string Ŭ������ ����ϱ� ���� ��� ����
using namespace std; // �̰� ���� �Լ� ������ std ���� �׳� ���� ��... like std::cout -> cout

void ex0912_1() {
	double a[5];
	cout << "5 ���� �Ǽ��� �Է��϶�>>";
	for (int n = 0; n < 5; n++) {
		cin >> a[n];
	}

	double a_max = a[0]; // �񱳴�� ���� ����, �迭�� ���� ù ��ҷ� ����
	if (a_max < a[1]) { a_max = a[1]; }
	if (a_max < a[2]) { a_max = a[2]; }
	if (a_max < a[3]) { a_max = a[3]; }
	if (a_max < a[4]) { a_max = a[4]; }
	
	/* // �ݺ����� �Ẹ�ڸ�,,,
	for (int i = 1; i < 5; i++) {
		if (a_max < a[i]) {a_max = a[i];}
	}
	*/
	cout << a_max << endl;

	// for (int n = 0; n < 5; n++) { cout << a[n] << endl; } // �Է¹��� ���� �� ���

	return;
}


double biggest(double b[], int N) { // �ݺ��� + �Լ�ȭ

	double a_max = b[0]; // �񱳴�� ���� ����, �迭�� ���� ù ��ҷ� ����
	for (int i = 1; i < N; i++) { if (a_max < b[i]) { a_max = b[i]; } }

	return a_max; // biggest �Լ� �� ���� (��������)
}


void ex0912_2() {

	double a[7]; // a, a[0], ... , a[6] ���� a�� �迭�� �޸� �ּ�
	int N = 7;

	cout << "7 ���� �Ǽ��� �Է��϶�>>";
	for (int n = 0; n < 7; n++) { cin >> a[n]; }
	
	double a_max = biggest(a, N); // main �Լ� �� ���� (��������)
	
	cout << a_max << endl;

	return;
}

void main() {
	int K[3] = { 7, 8, 9 };
	int M[3] = { 6, 5, 4 };
	cout << K << " " << &K[0] << " " << &K[1] << " " << &K[2] << endl; // &K[i]�� K�迭 �� i��° ĭ�� �ּҰ�
	// K�� �迭 ó���� �ּ� = &K[0] ���� ù ĭ�� �ּ�

	int* p = K; // k�� �ּ� ���� p�� ����, �̶� * �� �� ������ �ּҸ� �����ϴ� �������� ��Ÿ����
	cout << p << " " << p[0] << " " << p[1] << " " << p[2] << endl;
	cout << *p << " " << *(p + 1) << " " << *(p + 2) << endl;
	// ���⼭�� *�� �� �ּ��� ���빰�� �����ϰڴٴ�...
	// �ּ� p�� i�� ���ϸ� �� ��ġ���� i��° ������ �� ��ġ�� ��Ÿ��

	p = &K[2];
	cout << *p << " " << *(p - 1) << " " << *(p - 2) << endl; // 9  8  7
	cout << p[0] << " " << p[-1] << " " << p[-2] << endl; // 9  8  7 -> ���� ������ΰ� �迭�� Ȯ���� ��Ҹ� ����ֱ� ����...

}