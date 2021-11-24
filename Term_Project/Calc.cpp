#include "Calc.h" 

void Calc::init_stack() {
    top = -1; //스택에 처음 들어가는 원소 인덱스 0부터 
}

int Calc::push(int t) {
    if (top >= MAXIMUM - 1) { //들어갈 수 x
        return -1;
    }

    stack[++top] = t;
    return t;
}

int Calc::pop() {
    if (top < 0) { //꺼낼 게 x
        return INT_MIN;
    }
    return stack[top--];
}

// 스택의 TOP을 가져온다
int Calc::getTop() { //top에 뭐가 있다면
    return (top < 0) ? -1 : stack[top];
}

// 스택이 비어있는지 체크
bool Calc::Is_Empty() {
    return (top < 0);
}

// 연산자인지 판단한다.
bool Calc::Is_operator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

// 2진수인지 판단한다(문자열 0,1번째 인덱스 각각 0,b인지)
bool Calc::Is_binary(char* str) {
    return (*str == '0' && str[1] == 'b');
}

// 16진수인지 확인(문자열 0,1번째 인덱스 각각 0,x인지)
bool Calc::Is_hexadecimal(char* str) {
    return (*str == '0' && str[1] == 'x');
}

// 연산자 우선순위 판별
int Calc::OperatorPrecedence(char op) {
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    else return 3;
}

//중위표기식을 후위표기식으로 변환(src를 dst로)
bool Calc::postfix(char* dst, char* src) {
    init_stack();
    while (*src) {
        if (*src == '(') { //여는 괄호일 경우 스택에 추가
            push(*src);
            src++;
        }
        else if (*src == ')') { //닫힌 괄호이면 열린 괄호가 나올 때 까지 스택을 가져옴
            while (getTop() != '(') {
                //스택의 맨 위를 가져옴
                char a = pop();

                //만약 맨 위의 값이 유효하지 않으면 비정상적인 수식으로 FALSE
                if (a == INT_MIN || a == '\0')
                    return false;

                *dst++ = a;
                *dst++ = ' ';
            }
            //괄호 제거
            pop();
            src++;
        }
        else if (Is_operator(*src)) { //사칙연산자면
            while (!Is_Empty() &&
                OperatorPrecedence(getTop()) >= OperatorPrecedence(*src)) { //스택이 차있고 전 연산자(스택의 top)보다 현재 연산자가 우선순위 같거나 낮으면 
                *dst++ = pop();
                *dst++ = ' ';
            }
            push(*src); //현재 연산자 push
            src++;
        }
        else if (*src >= '0' && *src <= '9') { //숫자면(피연산자)
            char temp[256] = "0";
            char* tempptr = temp; //현재 포인터

            if (Is_binary(src)) { //이진수인지 확인

               //strtol 함수는 0b를 인식하지 못하므로 2진수이면 앞의 2문자를 제거 
                *src++;
                *src++;
                do {
                    *tempptr++ = *src++;
                } while (*src >= '0' && *src <= '1' || *src == 'b');

                //2진수 문자열을 정수로 변환 후 다시 문자열로 변환
                sprintf_s(temp, "%d", strtol(temp, NULL, 2));
            }
            else if (Is_hexadecimal(src)) { //16진수인지
                do {
                    *tempptr++ = *src++;
                } while (*src >= '0' && *src <= 'f' || *src == 'x');
                //16진수는 0x로 시작되므로 따로 문자열 제거가 필요 x
                //16진수 문자열을 정수로 변환 후 다시 문자열로 변환
                sprintf_s(temp, "%d", strtol(temp, NULL, 16));
            }
            else { //10 진수이면
                do {
                    //tempptr에 숫자가 끝날 때까지 복사 
                    *tempptr++ = *src++;
                } while (*src >= '0' && *src <= '9');
            }

            //tempptr의 포인터 위치 값을 초기화
            tempptr = temp;
            do {
                *dst++ = *tempptr++; //dst에 tempptr값을 복사
            } while (*tempptr >= '0' && *tempptr <= '9');
            *dst++ = ' ';
        }
        else {
            src++;
        }
    }

    //스택이 빌 때까지 후위표기식 dst의 끝에 추가
    while (!Is_Empty()) {
        *dst++ = pop();
        *dst++ = ' ';
    }

    //후위표기식의 끝 NULL문자 추가
    dst--;
    *dst = 0;

    return true;
}

//후위식 연산
void Calc::calc(char* p) {
    int i;
    init_stack();

    while (*p) {
        if (*p == '(' || *p == ')') { //후위식에 괄호가 남아있다면 에러 
            OnNotify(CALCULATION_FAIL, INT_MIN);
            return;
        }
        if (*p >= '0' && *p <= '9') { //숫자면(피연산자면) 인덱스 증가 후 넘어가
            i = 0;
            do {
                i = i * 10 + *p - '0'; //문자를 숫자로 변환
                p++;
            } while (*p >= '0' && *p <= '9');

            push(i);
        }
        else if (Is_operator(*p)) { //사칙 연산자이면
            char op = *p;
            int a = pop(); //위의 2개 원소 pop
            int b = pop();

            if (a == INT_MIN || b == INT_MIN) { //2개 원소 pop할 수 x
               //비정상적인 수식일경우
                OnNotify(CALCULATION_FAIL, INT_MIN);
                return;
            }
            if (op == '+') {
                push(a + b);
                p++;
            }
            else if (op == '*') {
                push(a * b);
                p++;
            }
            else if (op == '-') {
                i = a;
                push(b - i);
                p++;
            }
            else if (op == '/') {
                i = a;
                if (i == 0) { //0으로 나누면 에러
                    OnNotify(CALCULATION_FAIL, INT_MIN);
                    return;
                }
                else {
                    push(b / i);
                }
                p++;
            }
        }
        else {
            p++;
        }
    }

    //계산 성공 EVENT와 계산 결과값을 Param으로 전달
    OnNotify(CALCULATION_SUCCESS, pop());
}

Calc::Calc() {
    cbCount = 0;
}

void Calc::Calculation(char* exp) {
    char dest[256] = "";

    if (!postfix(dest, exp)) { //postfix가 FALSE 경우 비정상적인 수식으로 계산 실패 통지
        OnNotify(CALCULATION_FAIL, -1);
        return;
    }

    calc(dest); //후위식 넘겨줌
}

//이벤트 통지받을 CallBack 객체 등록
void Calc::addcallBack(CallBack* cb) {
    this->cb[cbCount++] = *cb;
}

//등록된 CallBack 객체에 이벤트 전송
void Calc::OnNotify(int EVENT_CODE, int Param) {
    for (int i = 0; i < cbCount; i++) {
        cb[i](EVENT_CODE, Param);
    }

}