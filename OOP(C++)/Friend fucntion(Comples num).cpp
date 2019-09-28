#include<bits/stdc++.h>
using namespace std;

class Dream
{
    int  real;
    int imag;
    public:
    Dream(){}

    Dream (int x,int y){real=x;imag=y;}
    friend Dream Complex (Dream,Dream );///complex means function name
    void Display()
    {
        cout<<real<<"+i"<<imag<<endl;
    }
};

Dream Complex(Dream A,Dream B)
{
   Dream res;
   res.real=A.real+B.real;
   res.imag=A.imag+B.imag;
   return res;
}


int main()
{
    Dream ob1(10,3),ob2(5,2),ob3;
    //ob1.set_data;
  //  ob2.set_data;
    ob3=Complex(ob1,ob2);
    ob3.Display();

    return 0;
}
