#include <iostream>
#include <string>
#include <math.h>
#define PI 3.14159265
using namespace std;

//Design the class lineType to store a line. To store a line, you need to store the values of a
// (coefficient of x), b (coefficient of y), and c. Your class must contain the following operations:
//a. If a line is nonvertical, then determine its slope.
//b. Determine if two lines are parallel.

class lineType
{
public:
    lineType();
    //Default constructor.
    lineType(int a, int b, int c);
    //Constructor with parameters.
    
    int getSlope() {     //Function to determine the slope
        if (ina != 0) {
            slope = atan (inb/ina) * 180 / PI;
            // cout << "Line slope is: " << slope << " degrees" << endl;
        } else {
            cout << "A equals to zero! Slope not identified (set to 0)." << endl;
            slope = 0;
        };
        return slope;
    };
    
    bool is_parallel(lineType line2)
    {
        if (slope == line2.getSlope())
            return true;
        else
            return false;
    };
    
 
private:
    int ina;
    int inb;
    int inc;
    int slope;
};

lineType::lineType()
{
    ina = 0;
    inb = 0;
    inc = 0;
}

lineType::lineType(int a, int b, int c)
{
    ina = a;
    inb = b;
    inc = c;
}

int main () {
    lineType myline1(1,2,0);
    cout << "Line1 slope is: " << myline1.getSlope() << " degrees" << endl;
    lineType myline2(1,3,5);
    cout << "Line2 slope is: " << myline2.getSlope() << " degrees" << endl;
    cout << "Is parallel (1=T,0=F): " << myline1.is_parallel(myline2) << endl;
    return 0;
}
