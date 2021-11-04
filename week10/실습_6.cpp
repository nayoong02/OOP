#include <iostream>
#include <string>
 
class DrawAPI { //인터페이스
public:
	virtual void drawCircle(int radius, int x, int y) = 0;
};

class RedCircle : public DrawAPI { //DrawAPI 인터페이스 구현하는 RedCircle 클래스
public:
	void drawCircle(int radius, int x, int y) {
		std::cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " <<  x <<  ", " << y << "]" << std::endl;
	}
};

class GreenCircle : public DrawAPI { //DrawAPI 인터페이스 구현하는 GreenCircle 클래스
public:
	void drawCircle(int radius, int x, int y) {
		std::cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", " << y << "]" << std::endl;
	}
};

class Shape { //DrawAPI 인터페이스 사용하는 Shape(abstract 클래스)
protected:
	DrawAPI* drawAPI;

protected:
	Shape() { //기본 생성자 

	}

	Shape(DrawAPI* drawAPI) {
		this -> drawAPI = drawAPI;
	}

public:
	virtual void draw() = 0;
};

class Circle : public Shape { //Shape 클래스를 상속받는 Circle 클래스 
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

