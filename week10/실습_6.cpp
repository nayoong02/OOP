#include <iostream>
#include <string>
 
class DrawAPI { //�������̽�
public:
	virtual void drawCircle(int radius, int x, int y) = 0;
};

class RedCircle : public DrawAPI { //DrawAPI �������̽� �����ϴ� RedCircle Ŭ����
public:
	void drawCircle(int radius, int x, int y) {
		std::cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " <<  x <<  ", " << y << "]" << std::endl;
	}
};

class GreenCircle : public DrawAPI { //DrawAPI �������̽� �����ϴ� GreenCircle Ŭ����
public:
	void drawCircle(int radius, int x, int y) {
		std::cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", " << y << "]" << std::endl;
	}
};

class Shape { //DrawAPI �������̽� ����ϴ� Shape(abstract Ŭ����)
protected:
	DrawAPI* drawAPI;

protected:
	Shape() { //�⺻ ������ 

	}

	Shape(DrawAPI* drawAPI) {
		this -> drawAPI = drawAPI;
	}

public:
	virtual void draw() = 0;
};

class Circle : public Shape { //Shape Ŭ������ ��ӹ޴� Circle Ŭ���� 
private:
	int x, y, radius;
	
public:
	Circle(int x, int y, int radius, DrawAPI* drawAPI) {
		this -> drawAPI = drawAPI;
		this -> x = x;
		this -> y = y;
		this -> radius = radius;
	}

public: 
	void draw() {
		drawAPI -> drawCircle(radius, x, y);
	}
};

int main() {
		Shape* redCircle = new Circle(100, 100, 10, new RedCircle());
		Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle());

		redCircle -> draw();
		greenCircle -> draw();
};

