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

	std::ofstream out("testOveroding.txt"); //���ϸ�

	AnyString a("Hello, this is operator overloading test!!!"); //anyString
	std::string output = a.getAnyString();
	out << output << std::endl; //���� ���

	return 0;
}
