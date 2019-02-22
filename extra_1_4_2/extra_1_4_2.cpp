#include <iostream>
using namespace std;

int main() {
    int **da;
    da = new int* [4];
    for (int i = 0; i < 4; i++) {
        da[i] = new int[7];
        system("sleep .5");
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            da[i][j]=i*j;
            cout << da[i][j] << " ";
        }
        cout << endl;
    }
    system("sleep .5");
    return 0;
}
