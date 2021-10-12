#include <fstream>
#include <iostream>
#include <string>

class AnyString {
	std::string anyString;

public:
	AnyString(const std::string& anyString) : anyString(anyString) {}
	std::string getAnyString() {
		return "Stored String :: " + anyString; 
	}

};

int main() {

	std::ofstream out("testOveroding.txt"); //파일명

	AnyString a("Hello, this is operator overloading test!!!"); //anyString
	std::string output = a.getAnyString();
	out << output << std::endl; //파일 출력

	return 0;
}
