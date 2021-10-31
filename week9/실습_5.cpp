#include <iostream> 
#include <vector> 
// ���� 
class Shape {
public:
	virtual void Draw() {
		std::cout << "Shape Draw" << std::endl;
	}
};

// �簢�� 
class Rect : public Shape {
public:
	// write code
	void Draw() {
		std::cout << "Rec Draw" << std::endl;
	}
};

// �� 
class Circle : public Shape {
public:
	// write code
	void Draw() {
		std::cout << "Circle Draw" << std::endl;
	}
};

// �ﰢ�� 
class triangle : public Shape {
public:
	// write code
	void Draw() {
		std::cout << "Triangle Draw" << std::endl;
	}
};

int main() {
	std::vector<Shape*> v1; // ���� ���� ���� 

	v1.push_back(new Rect);
	v1.push_back(new Circle);
	v1.push_back(new triangle);

	for (int i = 0; i < v1.size(); i++)
		v1[i]->Draw();

}
