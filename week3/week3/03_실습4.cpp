#include <iostream> 

void increment(int* x) //int�� ������ �޾� x�� ����
{
	++*x; //������ �� ����
}

int main()
{
	int x = 55;
	std::cout << " Before increment: " << x << std::endl;
	increment(&x); //x�� �����ڸ� increment �Ű������� ����
	std::cout << " After increment: " << x << std::endl;

	system("pause");
	return 0;
}
