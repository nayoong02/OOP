#include <stdio.h>

int main() {
	char s[100]; //입력 받을 문자의 배열 선언

	printf("문자를 입력하세요(100자 이내).\n");
	scanf("%s", s); //문자열 입력받기
	printf("입력된 문자는 %s입니다.", s);

	return 0;
}