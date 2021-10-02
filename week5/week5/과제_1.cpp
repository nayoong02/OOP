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
    {i = 3;
    A ob; } //¡ﬂ√∏∫Ì∑œ¿Ã ≥°≥Ø∂ß ∞¥√º º“∏Í
    return i; 
}

int main()
{
    cout << foo() << endl;
    return 0;
}
