#include <iostream> // ���򲨴� .h �Ⱥ��� ����
#include <string> // string Ŭ������ ����ϱ� ���� ��� ����
using namespace std; // �̰� ���� �Լ� ������ std ���� �׳� ���� ��... like std::cout -> cout

int sep02() {

	cout << "hello" << endl; // printf("hello\n")
	printf("22222hello\n");
	return 0;
}

double f(double r) {
	return 3.14 * r * r;
}

// SEP09�� ��� ���� : cout cin namespace string getline
int sep09_1() {
	
	int n = 3;
	char c = '#';
	cout << c << 5.5 << '-' << n << "hello" << true << endl;  
	// << ���̿��� ���Ⱑ �ݿ��� �ȵȴ�...
	// false �� 0, true �� 1
	// ���� std::endl == "\n" �ϸ� �ٹٲ� ����

	cout << "n + 5 = " << n + 5 << "\n";
	cout << f(10.0) << "\n";

	double y = f(5.0);
	cout << y << '\n';

	return 0;
}


// �̸������� Ȱ���Ͽ� ���� ���� �Լ��� ���� ���
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

	float A = KIM::area(5.0); // KIM ������ �ִ� area �Լ� �̿�
	float B = KANG::area(5.0); // KANG ������ �ִ� area �Լ� �̿�

	cout << A << " / " << B << endl;

	int width, height; // �ʺ�� ����
	cout << "�ʺ�� ���̸� �Է��ϼ��� : ";
	cin >> width >> height;
	cout << "�ʺ�� " << width << endl;
	cout << "���̴� " << height << endl;

	return 0;
}

int sep09_3() {

	int a = 100;
	string song = "falling in love with you"; //string �� int float ��� ó�� ������ �����̴�.
	//string song("falling in love with you"); �� ���� ����,, �Լ��������� �ẻ��
	cout << song << endl;

	string symbol("!!!!!");
	song = song + symbol;
	
	int index = song.find("love"); //string ����� �ִ� find �Լ� -> ���ڿ� �߿��� ��� �ִ��� �˷���

	cout << song << endl;
	cout << index << endl; 

	return 0;
}

int sep09_4() {
	string singer;
	getline(cin, singer); // cin ��ü���� �Է��� ��û�Ͽ� �Է� ���� ���� singer�� �������ִ� �����Լ�
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

	cout << "�� ���� �Է��ϼ���>> ";
	cin >> n;
	
	if (n <= 0) {
		cout << "����� �Է��ϼ���!" << endl;
		return 0;
	}
	cout << "1���� " << n << "������ ���� " << sum(1, n) << "�Դϴ�.";
	return 0;
}

int sum(int a, int b) {
	int res = 0;

	for (int k = a; k <= b; k++) {
		res += k;
	}

	return res;
}