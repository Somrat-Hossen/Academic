#include<iostream>
using namespace std;

class Base
{
public:
    virtual void show() = 0;
};

class Derived: public Base
{
public:
    void show() { cout << "In Derived \n"; }
};
class Derive: public Base
{
public:
    void show() { cout << "In Derived two\n"; }
};


int main(void)
{
    Derived d;
    Derive d1;

    Base *bp;
    bp=& d;

    bp->show();
    bp=& d1;

    bp->show();



    return 0;
 }
