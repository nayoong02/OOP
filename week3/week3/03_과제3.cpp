#include<iostream>

void swap(int &first, int &second) //a,b �� �ܼ����� x, ���������� ���� first,second�� ���� a,b�� �����ؼ� ���� �� ���� ����
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
