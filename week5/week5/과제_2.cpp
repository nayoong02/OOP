//constructor overloading 컴파일 오류 해결문제
#include <iostream>
class Animal {
public:
	Animal() { //디폴트 생성자 추가
		
	}
	Animal(int numberOfLeg) {
		this->numberOfLeg = numberOfLeg;
	}
private:
	int numberOfLeg;
};

int main() {
	Animal a;
	Animal b(4); //추가
	return 0;
}

