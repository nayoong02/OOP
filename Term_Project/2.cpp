#include <map>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Expression {
public:
	int interpret(map<string, Expression> variables);
};

class Plus : Expression {
	Expression leftoperand;
	Expression rightoperand;

public:
	Plus(Expression leftoperand, Expression rightoperand) {
		this->leftoperand = leftoperand;
		this->rightoperand = rightoperand;

	}
};

class Minus: Expression {
	Expression leftoperand;
	Expression rightoperand;

public:
	Minus(Expression leftoperand, Expression rightoperand) {
		this->leftoperand = leftoperand;
		this->rightoperand = rightoperand;

	}
};

class Mul : Expression {
	Expression leftoperand;
	Expression rightoperand;

public:
	Mul(Expression leftoperand, Expression rightoperand) {
		this->leftoperand = leftoperand;
		this->rightoperand = rightoperand;

	}
};

class Div : Expression {
	Expression leftoperand;
	Expression rightoperand;

public:
	Div(Expression leftoperand, Expression rightoperand) {
		this->leftoperand = leftoperand;
		this->rightoperand = rightoperand;

	}
};

class Evaluator : Expression {
private: 
	Expression syntax;

public:
	Evaluator(string expression) {
		stack<Expression> stack;
		char strToken;

		for (char strToken : expression) {
			if (strToken == '+') {
				Expression expressionPlus = new Plus(stack.pop, stack.pop);
				stack.push(expressionPlus);
			}
			else if (strToken == '-') {
				Expression expressionMinus = new Minus(stack.pop(), stack.pop());
				stack.push(expressionMinus);
			}
			else {
				stack.push(new Variable(strToken));
			}
		}
		//�ؼ� ����� ���� ���� 
		syntax = stack.pop();
	}

	//����ڰ� �Է��� ���ڷ� ���⿡ ��굹����
	
		public int interpret(Map<String, Expression> variables) {
		return syntax.interpret(variables);
	}
}
};