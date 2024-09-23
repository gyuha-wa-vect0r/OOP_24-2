#include <iostream>

void test2() {

};

void test1() {
	test2();
};


int main() {

	// std::cout << "hello"; // printf("hello");
	std::cout << "hello" << std::endl; // printf("hello\n")
	printf("22222hello\n");
	test1();
	return 0;
}