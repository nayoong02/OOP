class Base {
public:
	void func_1() {};
protected:
	void func_2() {};
private:
	int x_;
};

class Derived : public  Base { //protected를 public으로 변환
public:
	void func_3() {
		func_1();
		func_2();
	}
};

int main() {
	Derived d;
	d.func_3();
	d.func_1();
}
