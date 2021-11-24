#include <iostream>
#include <iostream>
#include <functional> 
#include "Calc.h"

using namespace std;
 
void main() {

    Calc calc;

    CallBack calcCallback = [&calcCallback](int EVENT_CODE, int Param) -> void { //callback 함수 객체 선언(등록)
        switch (EVENT_CODE) {
        case CALCULATION_SUCCESS: { //계산에 성공한 경우
            cout << "=> " << Param << "\n" << endl;
            break;
        }
        case CALCULATION_FAIL: { // 수식이 올바르지 않거나 계산에 실패한 경우
            cout << "=> 에러" << "\n" << endl;
            break;
        }
        default:
            break;
        }
    };

    calc.addcallBack(&calcCallback); //계산기에 callback 함수 넘겨줌(호출)

    while (1) {
        char exp[256] = "";
        cin >> exp; //식 입력 받음
        if (strcmp(exp, "exit") == 0) { //exit 입력 받으면 종료
            return;
        }
        calc.Calculation(exp);

    }
}