#include<bits/stdc++.h>

using namespace std;

double error =0.00001;

double Func(double x)
{
	return (x*x - 3*x + 2);
}

double Derivative(double x)  ///Compute derivative of the given function
{
	return (2*x -3);
}

void Raphson(double x)
{
   double x1;

	 while(true)
    {

          x1=x-(Func(x)/Derivative(x));

          cout<< x<<"   "<<x1<<"   "<<fabs(x1-x) <<endl;

          if( fabs((x1-x)/x1)<=error) break;
          x=x1;
    }

    cout << "The root of the equation is :" << fixed<<setprecision(4)<<x1<<endl;
}

int main()
{
	double x;

	puts("Enter the initial gauss value:"); /// Initial values assumed
	cin>>x;

	Raphson(x);

	return 0;
}

