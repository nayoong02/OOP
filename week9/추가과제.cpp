#include <iostream>
#include <string>

class Shape { //Shape 인터페이스 정의
public:
	virtual void draw() = 0;
};

class RoundedRectangle : public Shape { //Shape 인터페이스 구현하는 concrete class
public:
	void draw() {
	std::cout<<"Inside RoundedRectangle::draw() method."<<'\n';
	}
};

class RoundedSquare : public Shape { //Shape 인터페이스 구현하는 concrete class 
public:
	void draw() {
		std::cout << "Inside RoundedSquare::draw() method." << '\n';
	}
};

class Rectangle : public Shape { //Shape 인터페이스 구현하는 concrete class
public:
	void draw() {
		std::cout << "Inside Rectangle::draw() method." << '\n';
	}
};

class Square : public Shape { //Shape 인터페이스 구현하는 concrete class
public:
	void draw() {
		std::cout << "Inside Square::draw() method." << '\n';
	}
};

class AbstractFactory { //Abstract 클래스
public:
	virtual Shape* getShape(std::string shapeType) = 0;
};

class ShapeFactory : public AbstractFactory { //Abstract 클래스 상속받는 ShapeFactory 
public:
	Shape* getShape(std::string shapeType) {
		if (shapeType  == "RECTANGLE") {
			return new Rectangle();
		}
		else if (shapeType == "SQUARE") {
			return new Square();
		}
		return NULL;
	}
};

class RoundedShapeFactory : public AbstractFactory { //Abstract 클래스 상속받는 RoundShapeFactory
public:
	Shape* getShape(std::string shapeType) {
		if (shapeType  == "RECTANGLE") {
			return new RoundedRectangle();
		}
		else if (shapeType == "SQUARE") {
			return new RoundedSquare();
		}
		return NULL;
	}
};

class FactoryProducer {
public:
	static AbstractFactory* getFactory(bool rounded) {
		if (rounded) {
			return new RoundedShapeFactory();
		}
		else {
			return new ShapeFactory();
		}
	}
};

int main() {
	//get shape factory
	AbstractFactory* shapeFactory = FactoryProducer::getFactory(false);
	//get an object of Shape Rectangle
	Shape* shape1 = shapeFactory->getShape("RECTANGLE");
	//call draw method of Shape Rectangle
	shape1->draw();
	//get an object of Shape Square 
	Shape* shape2 = shapeFactory->getShape("SQUARE");
	//call draw method of Shape Square
	shape2->draw();
	//get shape factory
	AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true);
	//get an object of Shape Rectangle
	Shape* shape3 = shapeFactory1->getShape("RECTANGLE");
	//call draw method of Shape Rectangle
	shape3->draw();
	//get an object of Shape Square 
	Shape* shape4 = shapeFactory1->getShape("SQUARE");
	//call draw method of Shape Square
	shape4->draw();

	return 0;

};




