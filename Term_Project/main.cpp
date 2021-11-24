#include <iostream>
#include <iostream>
#include <functional> 
#include "Calc.h"

using namespace std;
 
void main() {

    Calc calc;

    CallBack calcCallback = [&calcCallback](int EVENT_CODE, int Param) -> void { //callback �Լ� ��ü ����(���)
        switch (EVENT_CODE) {
        case CALCULATION_SUCCESS: { //��꿡 ������ ���
            cout << "=> " << Param << "\n" << endl;
            break;
        }
        case CALCULATION_FAIL: { // ������ �ùٸ��� �ʰų� ��꿡 ������ ���
            cout << "=> ����" << "\n" << endl;
            break;
        }
        default:
            break;
        }
    };

    calc.addcallBack(&calcCallback); //���⿡ callback �Լ� �Ѱ���(ȣ��)

    while (1) {
        char exp[256] = "";
        cin >> exp; //�� �Է� ����
        if (strcmp(exp, "exit") == 0) { //exit �Է� ������ ����
            return;
        }
        calc.Calculation(exp);

    }
}