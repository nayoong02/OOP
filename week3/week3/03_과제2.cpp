#include <iostream> 

int main()
{
	int value = 5; 
	int& x = value; //���۷��� ���� ���(rvalue)�� �ƴ� �����̸�(lvalue)�� �;� ��
	std::cout << x << std::endl;
}
