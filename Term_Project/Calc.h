#pragma once 
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <string.h> 
#include <functional>

#define MAXIMUM 100
#define CALCULATION_SUCCESS 1
#define CALCULATION_FAIL 2

using namespace std;
typedef function<void(int, int)> CallBack; //함수 정의

class Calc {
private:
	int   stack[MAXIMUM];
	int   top;
	void init_stack();
	int push(int t);
	int pop();
	int  getTop();
	bool Is_Empty();
	bool Is_operator(char op);
	bool Is_binary(char* str);
	bool Is_hexadecimal(char* str);
	int  OperatorPrecedence(char op);
	bool postfix(char* dst, char* src);
	void calc(char* p);
	void OnNotify(int EVNET_CODE, int Param);
	int cbCount;
	CallBack cb[10]; //callback 직접 사용할 수 있는 배열

public:
	Calc();

	void Calculation(char* exp);
	void addcallBack(CallBack* cb);
};