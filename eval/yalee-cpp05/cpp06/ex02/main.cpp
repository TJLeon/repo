#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* createRandomClass()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    switch (std::rand() % 3)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
    }
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        cout << "its A!" << endl;
    else if (dynamic_cast<B*>(p))
        cout << "its B!" << endl;
    else if (dynamic_cast<C*>(p))
        cout << "its C!" << endl;
    else
        cout << "ITS BLACK!!!" << endl;
}

void identify(Base& p)
{
    cout << "---------------------" << endl;
	try {
		cout << "Trying to cast to A" << endl;
		A &a = dynamic_cast<A&>(p);
		cout << "Identified class: A (identify(Base &p))" << endl;
		(void)a;
        return;
	}
	catch (std::bad_cast &bc) {
		cout << "Identified class: unknown (identify(Base &p))" << endl;
	}
	
	cout << "---------------------" << endl;
	try {
		cout << "Trying to cast to B" << endl;
		B &b = dynamic_cast<B&>(p);
		cout << "Identified class: B (identify(Base &p))" << endl;
		(void)b;
        return;
	}
	catch (std::bad_cast &bc) {
		cout << "Identified class: unknown (identify(Base &p))" << endl;
	}
	
	cout << "---------------------" << endl;
	try {
		cout << "Trying to cast to C" << endl;
		C &c = dynamic_cast<C&>(p);
		cout << "Identified class: C (identify(Base &p))" << endl;
		(void)c;
        return;
	}
	catch (std::bad_cast &bc) {
		cout << "Identified class: unknown (identify(Base &p))" << endl;
	}
	cout << endl;
    return;
}

int main()
{
    A *objA = new A;
    B *objB = new B;
    C *objC = new C;

    cout << "--------------testing--------------" << endl;
    objA->whoMe();
    objB->whoMe();
    objC->whoMe();
    cout << "--------------testing--------------" << endl;
    cout << "----------------Real---------------" << endl;
    Base* gacha = createRandomClass();
    identify(gacha);
    identify(*gacha);
    cout << "---------------------" << endl;
    delete gacha;
    delete objA;
    delete objB;
    delete objC;
    cout << "----------------Real---------------" << endl;
}