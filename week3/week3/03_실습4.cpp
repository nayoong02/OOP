#include <iostream> 

void increment(int* x) //int형 포인터 받아 x에 저장
{
	++*x; //포인터 값 증가
}

int main()
{
	int x = 55;
	std::cout << " Before increment: " << x << std::endl;
	increment(&x); //x의 참조자를 increment 매개변수로 전달
	std::cout << " After increment: " << x << std::endl;

	system("pause");
	return 0;
}
