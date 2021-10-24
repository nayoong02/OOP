#include <iostream>
class Strategy { //�⺻ Ŭ����
public:
    virtual int doOperation(int num1, int num2) = 0;
};

//OperationAdd
class OperationAdd : public Strategy {
public:
    int doOperation(int num1, int num2) override {
        return num1 + num2;
    }
};
//OperationSubstract
class OperationSubstract : public Strategy {
public:
    int doOperation(int num1, int num2) override {
        return num1 - num2;
    }
};
//OperationMultiply
class OperationMultiply : public Strategy {
public:
    int doOperation(int num1, int num2) override {
        return num1 * num2;
    }
};

//��� ���� Ŭ����
class Context { 
public:
    Context(Strategy* strategy) {
        this->strategy = strategy;
    }
    int executeStrategy(int num1, int num2) {
        return strategy->doOperation(num1, num2);
    }
private:
    Strategy* strategy;
};

//��� �޼ҵ�
int main() {
    Context* context = new Context(new OperationAdd);
    std::cout << "10 + 5 = " << context->executeStrategy(10, 5) << '\n';
    context = new Context(new OperationSubstract);
    std::cout << "10 - 5 = " << context->executeStrategy(10, 5) << '\n';
    context = new Context(new OperationMultiply);
    std::cout << "10 * 5 = " << context->executeStrategy(10, 5) << '\n';
};
