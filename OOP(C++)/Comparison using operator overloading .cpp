#include<iostream>
using namespace std;

class Time
{
    int hours,minutes,seconds;
public:
    Time(int h,int m,int s)
    {
        hours=h;
        minutes=m;
        seconds=s;
    }
 void  display()
    {
        cout<<"hours "<<hours<<"minutes "<<minutes<<" seconds"<<seconds<<endl;
    }
    int operator > (Time ob)
    {
        return ((hours>ob.hours) || (minutes>ob.minutes) || (seconds>ob.seconds));
    }
};


int main()
{
    Time t1(8,58,49),t2(8,58,50);
    if(t1>t2)
        cout<<"t1 is greater than t2"<<endl;
    else
        cout<<"t1 is less than t2"<<endl;

    return 0;
}
