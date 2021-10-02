#include<iostream>

void swap(int &first, int &second) //a,b 값 단순복사 x, 참조변수에 의해 first,second가 각각 a,b에 접근해서 실제 값 변경 가능
{
    int temp = first;
    first = second;
    second = temp;
}

int main()
{
    int a = 2, b = 3;
    swap(a, b);
    std::cout << a << " " << b << std::endl;
    return 0;
}
