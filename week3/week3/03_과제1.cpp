#include <iostream>

void increment(int &x) //������ ������ main�� ���� x���� ����(int &x = x)
{
	++x; 
}

int main()
{
	int x = 55;
	std::cout << " Before increment: " << x << std::endl;
	increment(x); 
	std::cout << " After increment: " << x << std::endl;

	system("pause");
	return 0;
}