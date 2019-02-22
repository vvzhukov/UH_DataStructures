#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

int main () {
    int var = 10;
    std::cout<<"var1: "<<var<<std::endl;
    std::cout<<"var1 address: "<<&var<<std::endl;
    
    int *ptr = &var;
    *ptr = 20;

    std::cout<<"var1: "<<var<<std::endl;
    std::cout<<"var1 address: "<<&var<<std::endl;
    int **ptr2 = &ptr;
    **ptr2 = 30;
    std::cout<<"var1: "<<var<<std::endl;
    std::cout<<"var1 address: "<<&var<<std::endl;
    
    std::cout<<"ptr value: "<<ptr<<std::endl;
    std::cout<<"ptr & value: "<<&ptr<<std::endl;
    std::cout<<"ptr2 value: "<<ptr2<<std::endl;
    std::cout<<"ptr2 & value: "<<&ptr2<<std::endl;
    
    std::cout<<"ptr2 * value: "<<*ptr2<<std::endl;
    std::cout<<"ptr2 ** value: "<<**ptr2<<std::endl;
    
    
    int val[3] = { 5, 10, 15};
    int *ptr3;
    
    // Assign address of val[0] to ptr.
    // We can use ptr=&val[0];(both are same)
    ptr3 = val ;
    std::cout << "Elements of the array are: ";
    std::cout << ptr3[0] << " " << ptr3[1] << " " << val[2] << std::endl;
    
    int x = 10;
    // ref is a reference to x.
    int& ref = x;
    // Value of x is now changed to 20
    ref = 20;
    std::cout << "x = " << x << std::endl ;
    std::cout << "&ref = " << &ref << std::endl ;
    // Value of x is now changed to 30
    x = 30;
    std::cout << "ref = " << ref << std::endl ;
    
    
    int i,n;
    int * p;
    std::cout << "How many numbers would you like to type? ";
    std::cin >> i;
    p= new (std::nothrow) int[i];
    if (p == nullptr)
        std::cout << "Error: memory could not be allocated";
    else
    {
        for (n=0; n<i; n++)
        {
            std::cout << "Enter number: ";
            std::cin >> p[n];
        }
        std::cout << "You have entered: ";
        for (n=0; n<i; n++)
            std::cout << p[n] << ", ";
        delete[] p;
    }

    return 0;
}

