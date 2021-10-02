#include <iostream>
class Animal {
public:
	/**Animal() {
		numberOfLeg = 4;
	}**/
	Animal(int numberOfLeg) {
		this->numberOfLeg = numberOfLeg;
	}
private:
	int numberOfLeg;
};

int main() {
	Animal a;
	return 0;
}

