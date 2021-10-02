#include <iostream>
using namespace std;

int i;

class A
{
public:
    ~A()
    {
        i = 10;
    }
};

int foo()
{
    i = 3;
    A ob;
    return i; //ob의 소멸자가 i 값이 함수의 반환 값(3)으로 복사된 후에 호출됨
}

int main()
{
    cout << foo() << endl;
    return 0;
}
