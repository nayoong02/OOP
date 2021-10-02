#include <iostream>

void increment(int &x) //참조형 변수로 main의 실제 x값에 접근(int &x = x)
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