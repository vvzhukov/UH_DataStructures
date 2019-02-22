#include <iostream>
using namespace std;

struct st
{   string name; //char * name;
    float gpa;
    st * another;
};

int main()
{   st *first;
    first = new st;
    first -> name = "Yun";
    first -> gpa = 2.0;
    first -> another = new st;
    st *second = first -> another;
    second -> name = "Mario";
    second -> gpa = 3.5;
    second -> another = new st;
    st *third = second -> another;
    third-> name = "X";
    third-> gpa = 0;
    third-> another=nullptr;
    
    cout << "Our classmates: "  << endl
                                << first -> name << endl
                                << second -> name << endl
                                << third -> name << endl;
    return 0;
}