//constructor overloading ������ ���� �ذṮ��
#include <iostream>
class Animal {
public:
	Animal() { //����Ʈ ������ �߰�
		
	}
	Animal(int numberOfLeg) {
		this->numberOfLeg = numberOfLeg;
	}
private:
	int numberOfLeg;
};

int main() {
	Animal a;
	Animal b(4); //�߰�
	return 0;
}

