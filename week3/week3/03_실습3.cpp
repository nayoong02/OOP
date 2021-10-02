#include <iostream> 

void increment(int x)
{
	++x;
}

int main()
{
	int x = 55;
	std::cout << " Before increment: " << x << std::endl;
	increment(x); //main함수 안에서는 x가 증가되지 않음.(값에 의한 호출)
	std::cout << " After increment: " << x << std::endl;

	system("pause");
	return 0;
}
