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

int& foo()
{
    i = 3;
    A ob;
    return i; //i의 주소가 반환값에 복사되고 참조는 자동 소멸됨
}

int main()
{
    cout << foo() << endl;
    return 0;
}
