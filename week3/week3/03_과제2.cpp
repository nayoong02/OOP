#include <iostream> 

int main()
{
	int value = 5; 
	int& x = value; //레퍼런스 값에 상수(rvalue)가 아닌 변수이름(lvalue)이 와야 함
	std::cout << x << std::endl;
}
