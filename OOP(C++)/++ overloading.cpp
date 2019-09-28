#include<iostream>

using namespace std;

class Time
{
    int hours,minutes,seconds;
    public:


    Time(int h=0,int m=0,int s=0)
    {
        hours=h;
        minutes=m;
        seconds=s;
    }

    void display()
    {
    cout<<"hours:"<<hours<<" minutes:"<<minutes<<" seconds:"<<seconds<<endl;
    }

    Time operator ++();
    Time operator ++(int unused);
};

Time Time::operator ++()
{
    seconds++;
    if(seconds>=60)
    {
        minutes++;
        seconds-=60;
    }
    if(minutes>=60)
    {
        hours++;
        minutes-=60;
    }
    return *this;
}

Time Time::operator ++(int unused)
{
    Time ob (*this);

    seconds++;
    if(seconds>=60)
    {
        minutes++;
        seconds-=60;
    }
    if(minutes>=60)
    {
        hours++;
        minutes-=60;
    }
    return ob;
}

int main()
{
    Time t1(5,6,59);
    t1.display();
    (++t1).display();
    (t1++).display();
    t1.display();

    return 0;
}
