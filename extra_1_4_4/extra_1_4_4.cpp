#include <iostream>
using namespace std;

template <class A_Type> class calc
{
public:
    A_Type multiply(A_Type x, A_Type y);
    A_Type add(A_Type x, A_Type y);
};
template <class A_Type> A_Type calc <A_Type>::multiply(A_Type x,A_Type y) {
    return x*y;
}
template <class A_Type> A_Type calc <A_Type>::add(A_Type x, A_Type y) {
    return x+y;
}

calc <int> my_int_calc;
calc <float> my_float_calc;

int main() {
    cout << my_int_calc.add(12, 13) << endl;
    cout << my_float_calc.multiply(6.7f, 8.1f) << endl;
    return 0;
}