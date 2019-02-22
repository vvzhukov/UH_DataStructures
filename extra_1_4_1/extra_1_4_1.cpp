#include <iostream>
using namespace std;

int main (int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Use parameters to play with this program!" << std::endl;
        return -1;
    } else {
        cout << "You have entered " << argc << " parameters!" << endl;
        cout << "They are: " << endl;

        for (int i = 1; i < argc; ++i) {
            cout << "Number " << i << "; Value: " << argv[i] << endl;
        };
    };
    return 0;
}