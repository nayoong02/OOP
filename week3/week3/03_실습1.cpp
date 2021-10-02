#include <string>
#include <iostream>

int main() {
	std::string s;
	std::cout << "문자를 입력하세요(100자 이내)." << std::endl;
	std::cin >> s; //s 입력 받음
	std::cout << "입력된 문자는 " << s << "입니다." << std::endl; //입력 받은 s 출력

	//system("pause"); // keep terminal open
	return 0;
}
