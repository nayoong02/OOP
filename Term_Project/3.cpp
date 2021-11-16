#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

struct oper {
    int p; // ������ �켱����
    string o; // ������
};

stack<int> num; // ���� ����
stack<oper> op; // ������ ����

void calc() {
    int a, b, result;
    b = num.top();
    num.pop();
    a = num.top();
    num.pop();
    string oper = op.top().o;
    op.pop();

    if (oper == "*")
        result = a * b;
    else if (oper == "/")
        result = a / b;
    else if (oper == "+")
        result = a + b;
    else if (oper == "-")
        result = a - b;
    // ��� �� ���ÿ� �ٽ� ����
    num.push(result);
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;
    istringstream ss(input);
    string tok;
    

        // ������ �켱������ ���� ���ÿ� push
        // 0 : ( )
        // 1 : + -
        // 2 : * /
       
  
    while (ss >> tok) {
        // ( �� ������ ������ ���ÿ� push
        if (tok == "(") {
            op.push({ 0, tok });
        } // ) �� ������ ( �� ���� �� ���� ���
        else if (tok == ")") {
            while (op.top().o != "(")
                calc();
            op.pop();
        }
        else if (tok == "*" || tok == "/" || tok == "+" || tok == "-") {
            int prior; // ������ �켱����
            if (tok == "*")
                prior = 2;
            else if (tok == "/")
                prior = 2;
            else if (tok == "+")
                prior = 1;
            else if (tok == "-")
                prior = 1;

            // ������ �켱 ���� ������ top���� �� ������ ���
            while (!op.empty() && prior <= op.top().p)
                calc();
            // ���ÿ� ������ push
            op.push({ prior, tok });
        }
        else // ������ ��� ���� ���ÿ� push
            num.push(stoi(tok));
    }
    // ���� ������ ���
    while (!op.empty())
        calc();

    cout << num.top();

    return 0;
};