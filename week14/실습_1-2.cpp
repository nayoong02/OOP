//Singleton ÆĞÅÏ Àû¿ë ÈÄ
#include <iostream>

class GlobalClass
{
private:
	int m_value;
	static GlobalClass* s_instance;
	GlobalClass(int v = 0)
	{
		m_value = v;
	}
public:
	int get_value()
	{
		return m_value;
	}
	void set_value(int v)
	{
		m_value = v;
	}
	//validation(½Ì±ÛÅæ ÇÙ½É)
	static GlobalClass* instance() 
	{
		if (!s_instance) //°´Ã¼ »ı¼ºµÅÀÖ´ÂÁö Ã¼Å©
			s_instance = new GlobalClass;
		return s_instance;
	}
};

// Allocating and initializing GlobalClass's
// static data member.  The pointer is being
// allocated - not the object itself.
GlobalClass* GlobalClass::s_instance = 0;

void foo(void)
{
	GlobalClass::instance()->set_value(1);
	std::cout << "foo: global_ptr is "
		<< GlobalClass::instance()->get_value() << '\n';
}

void bar(void)
{
	GlobalClass::instance()->set_value(2);
	std::cout << "bar: global_ptr is "
		<< GlobalClass::instance()->get_value() << '\n';
}

int main()
{
	std::cout << "main: global_ptr is "
		<< GlobalClass::instance()->get_value() << '\n';
	foo();
	bar();

}
