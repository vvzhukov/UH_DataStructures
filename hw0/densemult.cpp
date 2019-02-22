#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <math.h>
#include "ArgumentManager.h"
using namespace std;

int main (int argc, char** argv) {
    int row = 0;
    int col = 0;
    int n = 0; //string symbol in every line of input txt
    
    if (argc < 2) {
        std::cout << "Usage: densemult \"A=<file>;C=<file>\"" << std::endl;
        return -1;
    }
    ArgumentManager am(argc, argv);
    string A = am.get("A");
    string C = am.get("C");

 
    string element; //element of string from txt
    string line; //string from txt
    
    static int N = 20;
    float marray[N][N];
    
    ifstream ifile (A);
    if (ifile.is_open())
    {
        while ( getline (ifile,line) ) //go through each line
        {
            col = 0;
            if (line.rfind("#", 0) != 0) { //avoid commented lines
                cout << "Input line: " << line << endl;
                for(n = 0; n < line.length(); n++) { //go through each symbol
                    if (line[n] == ' ') { //separating array's values
                        marray[row][col] = stof(element);
                        cout << "Array element: " << marray[row][col] << endl;
                        col++;
                        element = "";
                        
                    } else element += line[n];
                    if (n == line.length()-1) { // endofline case
                        element += line[n+1];
                        marray[row][col] = stof(element);
                        cout << "Array element: " << marray[row][col] << endl;
                        col++;
                        element = "";
                    };
                };
                row++;
            }
        }
        ifile.close();
        
        ofstream ofile;
        ofile.open (C);
        
        for (int rowo = 0; rowo < row; rowo++) {
            for (int colo = 0; colo < col; colo++) {
                float result = 0;
                for (int k = 0; k < row; k++) {
                    result += (marray[rowo][k] * marray[k][colo]);
                };
                ofile << fixed << setprecision(2) << result << " ";
            };
            ofile << "\n";
        };
        
        ofile.close();

        
        if (row != col) { //Wrong input verification
            ofile.open (C);
            ofile << "";
            ofile.close();
        };

    }
    else cout << "Unable to open file";
    return 0;
}
