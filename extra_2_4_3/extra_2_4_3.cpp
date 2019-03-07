#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;

// EXTRA_2_4_3
// Stack implemented by array!!! Should I redo it with native stack?
// Do I need to reverse it anyways? What to benchmark? 
// fill two stacks
// reverse them
//1 +
//2 -
//4 -
//8 +
//9 -
//...
//1+2+4+8+9
// clock - fill a stackm and reverse a stackm
// define default capacity of stackm
// Code partly taken from techiedelight.com

#define SIZE 100

// Class for stackm
template <class X>
class stackm
{
private:
    X *arr;
    int top;
    int capacity;
    
public:
    stackm(int size = SIZE);    // constructor
    void push(X);
    X pop();
    X peek();
    int size();
    bool isEmpty();
    bool isFull();
};

// Constructor to initialize stackm
template <class X>
stackm<X>::stackm(int size)
{
    arr = new X[size];
    capacity = size;
    top = -1;
}

// function to add an element x in the stackm
template <class X>
void stackm<X>::push(X x)
{
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    
    cout << "Inserting " << x << endl;
    arr[++top] = x;
}

// function to pop top element from the stackm
template <class X>
X stackm<X>::pop()
{
    // check for stackm underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    
    cout << "Removing " << peek() << endl;
    
    // decrease stackm size by 1 and (optionally) return the popped element
    return arr[top--];
}

// function to return top element in a stackm
template <class X>
X stackm<X>::peek()
{
    if (!isEmpty())
        return arr[top];
    else
        exit(EXIT_FAILURE);
}

// Utility function to return the size of the stackm
template <class X>
int stackm<X>::size()
{
    return top + 1;
}

// Utility function to check if the stackm is empty or not
template <class X>
bool stackm<X>::isEmpty()
{
    return top == -1;    // or return size() == 0;
}

// Utility function to check if the stackm is full or not
template <class X>
bool stackm<X>::isFull()
{
    return top == capacity - 1;    // or return size() == capacity;
}

// main function
int main()
{
    stackm<int> Si(10);
    
    Si.push(8);
    Si.push(1);
    Si.push(9);
    Si.push(3);
    Si.push(10);
    Si.push(13);
    
    stackm<string> So(10);
    
    So.push("+");
    So.push("-");
    So.push("+");
    So.push("-");
    So.push("+");
    
    while (!So.isEmpty()) {
        if (So.pop() == "+") {
            Si.push(Si.pop() + Si.pop());
        } else if (So.pop() == "-") {
            Si.push(Si.pop() - Si.pop());
        }}
    // Prints the top of the stackm
    cout << "--- Result is " << Si.peek() << endl;
    
    return 0;
}
