#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

typedef char element;

struct Node {
    element data;
    Node* link;
};

Node* top;

void push(element data)
{
    Node* temp;
    temp = new Node();

    if (!temp)
    {
        cout << "\nHeap Overflow";
        exit(1);
    }

    temp->data = data;
    temp->link = top;
    top = temp;
}

int isEmpty()
{
    return top == NULL;
}

int peek()
{
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

element pop()
{
    Node* temp;
    element data;

    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {
        data = top->data;
        temp = top;
        top = top->link;
        temp->link = NULL;
        delete temp;
    }

    return data;
}

void display()
{
    Node* temp;
    if (top == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->link;
        }
    }
}

bool paircheck(string exp)
{
    element symbol;

    for (int i = 0; i < exp.size(); i++)
    {
        symbol = exp[i];
        switch (symbol)
        {
        case '(':case '[':case '{':
            push(symbol);
            break;
        case ')':case ']':case '}':
            if (isEmpty())
                return false;
            else
            {
                element popelement = pop();
                if ((popelement == '(' && symbol != ')') ||
                    (popelement == '[' && symbol != ']') ||
                    (popelement == '{' && symbol != '}'))
                    return false;
                else
                    break;
            }
            break;
        }
    }
    if (isEmpty())
        return true;
    else
        return false;
}


string postfix(string exp)
{
    char symbol;
    int count = 0;
    string result = "";

    for (int i = 0; i < exp.size(); i++)
    {
        symbol = exp[i]; // ���� �ϳ� �ϳ��� ����
        if (isdigit(symbol))
        {
            result += symbol;
            continue;
        }

        switch (symbol)
        {
        case '+':case '-':case '*':case '/':
            push(symbol);
            break;
        case ')':case '}':case ']':
            result += pop();
            break;
        }
    }

    while (!isEmpty())
        result += pop();
    return result;
}
// �������� ���
int eval(string exp)
{
    element symbol;

    for (int i = 0; i < exp.size(); i++)
    {
        symbol = exp[i];
        if (isdigit(symbol))
        {
            push((element)(symbol - '0'));
        }
        else
        {
            element opr2 = pop();
            element opr1 = pop();

            switch (symbol)
            {
            case '+':
                push(opr1 + opr2);
                break;
            case '-':
                push(opr1 - opr2);
                break;
            case '*':
                push(opr1 * opr2);
                break;
            case '/':
                push(opr1 / opr2);
                break;
            }
        }
    }
    return pop(); // ���ÿ� ����� ���� ���� ��� ����� ��ȯ
}

void test(string exp)
{
    cout << "-------------------- " << endl;
    cout << "����: " << exp << endl;

    while (!isEmpty()) pop();
    if (!paircheck(exp))
    {
        cout << "�߸��� ���� " << endl;
        return;
    }
    while (!isEmpty()) pop();

    string postexp = postfix(exp);
    cout << "����ǥ��: " << postexp << endl;

    while (!isEmpty()) pop();

    int result = eval(postexp);
    cout << "���: " << result << endl;
}

int main()
{
    test("1+2");
    test("(1+2)*3");
    test("(1+2)/3");
    test("(1+2)/3)");

    return 0;
}

