#include <iostream>

/* ....(�ǽ�1)���� ������ template swap ....*/
template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

/* ... (�߰�) template swap�� string type specialization ... */
template <> void swap(std::string& a, std::string& b) {

}

int main() {
	int a = 1;
	int b = 2;
	float c = 3.3;
	float d = 4.4;
	std::string e = "World";
	std::string f = "Hello";

	swap<int>(a, b); //swap(a,b)�� ����
	swap<float>(c, d); //swap(c,d)�� ����

   //(�߰�) e, f�� swap�� �����ϵ��� swap template ȣ��
	swap(e, f);

	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "e: " << e << ", f: " << f << std::endl;

	return 0;
}
