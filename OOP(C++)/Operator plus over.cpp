#include<bits/stdc++.h>
using namespace std;



class Complex
{
  int real,imag;
  public:
  Complex(int a=0,int b=0){real=a;imag=b;}

  Complex operator +(Complex ob)
  {

    real=real+ob.real;
    imag=imag+ob.imag;
    Show();
  }
  void Show()
  {
    cout<<real<<"+ i"<<imag<<endl;
  }



};

int main()
{
   Complex ob(10,5),ob1(5,6);
   ob+ob1;

  return 0;
}
