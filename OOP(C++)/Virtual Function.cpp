#include <iostream>

using namespace std;

class Employee                    //  abstract base class
{
    public:
	virtual void getSalary() =0;    // pure virtual function
};

class Developer : public Employee
{
	int salary;
	public:
		Developer(int s)
		{
			salary = s;
		}
		void getSalary()
		{
			cout<<"Developer salary is:"<<salary<<endl;
		}
};

class Driver : public Employee
{
 int salary;

 public:
    Driver(int t)
    {
        salary = t;
    }
    void getSalary()
    {
        cout<<"Driver salary is:"<<salary<<endl;
    }
};

int main()
{
    Employee *bp;

	Developer d1(8000);
	Driver d2(5000);

	bp=& d1;
	bp->getSalary();

	bp=&d2;
	bp->getSalary();

	return 0;
}


