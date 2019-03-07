#include <iostream>
#include <iomanip>
#include <chrono>
#include <stack>
using namespace std;

//EXTRA_2_4_2 -> create stack of characters
//read a name, length,
//fill it (stack) and pop it

//read 'mario'
//o
//i
//r
//a
//m
//-> oiram
//use stack to reverse something

void showstack(stack <string> s) {
    while (!s.empty())
    {
        cout << "\t" << s.top();
        s.pop();
    }
    cout << "\n";
}


int main() {
    stack <string> s;
    s.push("m");
    s.push("a");
    s.push("r");
    s.push("i");
    s.push("o");
    
    cout << "The stack is : ";
    showstack(s);
    
    cout << "\n s.size() : " << s.size();
    cout << "\n s.top() : " << s.top();
    cout << "\n s.pop()" << "\n";
    s.pop();
    cout << "The stack is : ";
    showstack(s);
    
    return 0;
    return 0;
}
