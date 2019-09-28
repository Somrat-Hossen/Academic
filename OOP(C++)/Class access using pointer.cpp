#include <iostream>

using namespace std;

class Myclass
{
 int width;

 public:
      void printWidth();
      void setWidth(int a );
};

void Myclass::setWidth( int wid )
 {
   width = wid;
}

void Myclass:: printWidth()
 {
   cout << "Width of box : " << width <<endl;
}

// Main function for the program
int main()
{
   Myclass obj,*ob;

   obj.setWidth(10);
   ob=&obj;
   ob->printWidth();
   return 0;
}

