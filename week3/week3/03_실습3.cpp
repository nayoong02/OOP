#include <iostream> 

void increment(int x)
{
	++x;
}

int main()
{
	int x = 55;
	std::cout << " Before increment: " << x << std::endl;
	increment(x); //main�Լ� �ȿ����� x�� �������� ����.(���� ���� ȣ��)
	std::cout << " After increment: " << x << std::endl;

	system("pause");
	return 0;
}
