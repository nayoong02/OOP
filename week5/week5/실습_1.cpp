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
    return i; //ob�� �Ҹ��ڰ� i ���� �Լ��� ��ȯ ��(3)���� ����� �Ŀ� ȣ���
}

int main()
{
    cout << foo() << endl;
    return 0;
}
