#include <iostream>
class Strategy { //기본 클래스
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

//제어를 위한 클래스
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

//출력 메소드
int main() {
    Context* context = new Context(new OperationAdd);
    std::cout << "10 + 5 = " << context->executeStrategy(10, 5) << '\n';
    context = new Context(new OperationSubstract);
    std::cout << "10 - 5 = " << context->executeStrategy(10, 5) << '\n';
    context = new Context(new OperationMultiply);
    std::cout << "10 * 5 = " << context->executeStrategy(10, 5) << '\n';
};