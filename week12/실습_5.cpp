#include <iostream>
using namespace std; 

class Student {  
private: 
	std::string rollNo;
	std::string name;
public:
	std::string getRollNo() {
		return rollNo;
	}
	void setRollNo(std::string rollNo) {
		this->rollNo = rollNo;
	}
	std::string getName() {
		return name;
	}
	void setName(std::string name) {
		this->name = name;
	}
};

class StudentView {
public:
	void printStudentDetails(std::string studentName, std::string studentRollNo) { //Ãâ·Â¹®
		cout << "Student: " << endl 
			<< "Name: " << studentName << endl 
			<< "RollNo: " << studentRollNo << endl;
	}
};

class StudentController {
private: 
	Student model;
	StudentView view;

public:
	StudentController(Student model, StudentView view) {
		this->model = model;
		this->view = view;
	}
	void setStudentName(std::string name) {
		model.setName(name);
	}
	std::string getStudentName() {
		return model.getName();
	}
	void setStudentRollNo(std::string rollNo) {
		model.setRollNo(rollNo);
	}
	std::string getStudentRollNo() {
		return model.getRollNo();
	}
	void updateView() {
		view.printStudentDetails(model.getName(), model.getRollNo());
	}
};

int main() {
	Student model;
	model.setName("Robert");
	model.setRollNo("10");
	//Create a view : to write student details on console
	StudentView view;
	StudentController controller(model, view);
	controller.updateView();
	//update model data
	controller.setStudentName("John");
	controller.updateView();
};


