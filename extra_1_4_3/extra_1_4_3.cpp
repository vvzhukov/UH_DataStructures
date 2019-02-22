#include <iostream>
using namespace std;

template <class Type>
Type larger(Type x, Type y) {
    if (x >= y)
        return x;
    else
        return y;
}

int main() {
    cout << "Larger of 5 and 6 = " << larger(5, 6) << endl;
    cout << "Larger of A and B = " << larger('A','B') << endl;
    cout << "Larger of 5.6 and 3.2 = " << larger(5.6, 3.2) << endl;
    string str1 = "Funny";
    string str2 = "Sunny";
    cout << "Larger of " << str1 << " and " << str2 << " = " << larger(str1, str2) << endl;
    return 0;
}