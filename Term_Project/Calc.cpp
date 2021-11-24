#include "Calc.h" 

void Calc::init_stack() {
    top = -1; //���ÿ� ó�� ���� ���� �ε��� 0���� 
}

int Calc::push(int t) {
    if (top >= MAXIMUM - 1) { //�� �� x
        return -1;
    }

    stack[++top] = t;
    return t;
}

int Calc::pop() {
    if (top < 0) { //���� �� x
        return INT_MIN;
    }
    return stack[top--];
}

// ������ TOP�� �����´�
int Calc::getTop() { //top�� ���� �ִٸ�
    return (top < 0) ? -1 : stack[top];
}

// ������ ����ִ��� üũ
bool Calc::Is_Empty() {
    return (top < 0);
}

// ���������� �Ǵ��Ѵ�.
bool Calc::Is_operator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

// 2�������� �Ǵ��Ѵ�(���ڿ� 0,1��° �ε��� ���� 0,b����)
bool Calc::Is_binary(char* str) {
    return (*str == '0' && str[1] == 'b');
}

// 16�������� Ȯ��(���ڿ� 0,1��° �ε��� ���� 0,x����)
bool Calc::Is_hexadecimal(char* str) {
    return (*str == '0' && str[1] == 'x');
}

// ������ �켱���� �Ǻ�
int Calc::OperatorPrecedence(char op) {
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    else return 3;
}

//����ǥ����� ����ǥ������� ��ȯ(src�� dst��)
bool Calc::postfix(char* dst, char* src) {
    init_stack();
    while (*src) {
        if (*src == '(') { //���� ��ȣ�� ��� ���ÿ� �߰�
            push(*src);
            src++;
        }
        else if (*src == ')') { //���� ��ȣ�̸� ���� ��ȣ�� ���� �� ���� ������ ������
            while (getTop() != '(') {
                //������ �� ���� ������
                char a = pop();

                //���� �� ���� ���� ��ȿ���� ������ ���������� �������� FALSE
                if (a == INT_MIN || a == '\0')
                    return false;

                *dst++ = a;
                *dst++ = ' ';
            }
            //��ȣ ����
            pop();
            src++;
        }
        else if (Is_operator(*src)) { //��Ģ�����ڸ�
            while (!Is_Empty() &&
                OperatorPrecedence(getTop()) >= OperatorPrecedence(*src)) { //������ ���ְ� �� ������(������ top)���� ���� �����ڰ� �켱���� ���ų� ������ 
                *dst++ = pop();
                *dst++ = ' ';
            }
            push(*src); //���� ������ push
            src++;
        }
        else if (*src >= '0' && *src <= '9') { //���ڸ�(�ǿ�����)
            char temp[256] = "0";
            char* tempptr = temp; //���� ������

            if (Is_binary(src)) { //���������� Ȯ��

               //strtol �Լ��� 0b�� �ν����� ���ϹǷ� 2�����̸� ���� 2���ڸ� ���� 
                *src++;
                *src++;
                do {
                    *tempptr++ = *src++;
                } while (*src >= '0' && *src <= '1' || *src == 'b');

                //2���� ���ڿ��� ������ ��ȯ �� �ٽ� ���ڿ��� ��ȯ
                sprintf_s(temp, "%d", strtol(temp, NULL, 2));
            }
            else if (Is_hexadecimal(src)) { //16��������
                do {
                    *tempptr++ = *src++;
                } while (*src >= '0' && *src <= 'f' || *src == 'x');
                //16������ 0x�� ���۵ǹǷ� ���� ���ڿ� ���Ű� �ʿ� x
                //16���� ���ڿ��� ������ ��ȯ �� �ٽ� ���ڿ��� ��ȯ
                sprintf_s(temp, "%d", strtol(temp, NULL, 16));
            }
            else { //10 �����̸�
                do {
                    //tempptr�� ���ڰ� ���� ������ ���� 
                    *tempptr++ = *src++;
                } while (*src >= '0' && *src <= '9');
            }

            //tempptr�� ������ ��ġ ���� �ʱ�ȭ
            tempptr = temp;
            do {
                *dst++ = *tempptr++; //dst�� tempptr���� ����
            } while (*tempptr >= '0' && *tempptr <= '9');
            *dst++ = ' ';
        }
        else {
            src++;
        }
    }

    //������ �� ������ ����ǥ��� dst�� ���� �߰�
    while (!Is_Empty()) {
        *dst++ = pop();
        *dst++ = ' ';
    }

    //����ǥ����� �� NULL���� �߰�
    dst--;
    *dst = 0;

    return true;
}

//������ ����
void Calc::calc(char* p) {
    int i;
    init_stack();

    while (*p) {
        if (*p == '(' || *p == ')') { //�����Ŀ� ��ȣ�� �����ִٸ� ���� 
            OnNotify(CALCULATION_FAIL, INT_MIN);
            return;
        }
        if (*p >= '0' && *p <= '9') { //���ڸ�(�ǿ����ڸ�) �ε��� ���� �� �Ѿ
            i = 0;
            do {
                i = i * 10 + *p - '0'; //���ڸ� ���ڷ� ��ȯ
                p++;
            } while (*p >= '0' && *p <= '9');

            push(i);
        }
        else if (Is_operator(*p)) { //��Ģ �������̸�
            char op = *p;
            int a = pop(); //���� 2�� ���� pop
            int b = pop();

            if (a == INT_MIN || b == INT_MIN) { //2�� ���� pop�� �� x
               //���������� �����ϰ��
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
                if (i == 0) { //0���� ������ ����
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

    //��� ���� EVENT�� ��� ������� Param���� ����
    OnNotify(CALCULATION_SUCCESS, pop());
}

Calc::Calc() {
    cbCount = 0;
}

void Calc::Calculation(char* exp) {
    char dest[256] = "";

    if (!postfix(dest, exp)) { //postfix�� FALSE ��� ���������� �������� ��� ���� ����
        OnNotify(CALCULATION_FAIL, -1);
        return;
    }

    calc(dest); //������ �Ѱ���
}

//�̺�Ʈ �������� CallBack ��ü ���
void Calc::addcallBack(CallBack* cb) {
    this->cb[cbCount++] = *cb;
}

//��ϵ� CallBack ��ü�� �̺�Ʈ ����
void Calc::OnNotify(int EVENT_CODE, int Param) {
    for (int i = 0; i < cbCount; i++) {
        cb[i](EVENT_CODE, Param);
    }

}