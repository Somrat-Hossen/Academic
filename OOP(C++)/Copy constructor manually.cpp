#include <iostream>

using namespace std;

    //declaration of class B

class Test
{
 int value;

 public:

    Test(int x)
    {
        value = x;
    }
    void Show()
    {
      cout<<"Value is "<<value<<endl;
    }

    Test(Test &ob)     // declaring friend function
    {
       value=ob.value;
       cout<<value<<endl;
    }
};



int main()
{
	Test t(50);
	Test t1=t;
	t.Show();
	t1.Show();

	return 0;
}

