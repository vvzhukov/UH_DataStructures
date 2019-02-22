#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <math.h>
#include "ArgumentManager.h"
using namespace std;

// Function findLCS from study example. Could be found
// at www.dyclassroom.com/dynamic-programming/longest-common-subsequence
int findLCS(string X, string Y, int XLen, int YLen) {
    int L[XLen + 1][YLen + 1];
    int r, c;
    
    /*
     * find the length of the LCS
     */
    for(r = 0; r <= XLen; r++) {
        for(c = 0; c <= YLen; c++) {
            if(r == 0 || c == 0) {
                L[r][c] = 0;
            } else if(X[r - 1] == Y[c - 1]) {
                L[r][c] = L[r - 1][c - 1] + 1;
            } else {
                L[r][c] = max(L[r - 1][c], L[r][c - 1]);
            }
        }
    }
        
    //return result
    return L[XLen][YLen];
}

int main (int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: densemult \"input=<file>;output=<file>\"" << std::endl;
        return -1;
    }
    ArgumentManager am(argc, argv);
    
    string A = am.get("input");
    string B = am.get("output");
    int n = 0; //lines counter
    int mincls = 2001;
    
    int result[4][4];
    string element[4]; //array of string from txt
    string line = ""; //string from txt

    ifstream ifile (A);
    if (ifile.is_open())
    {
        while ( getline (ifile,line) ) //go through each line
        {
            if (line.length() != 0) {
                element[n] = line;
                n++;
            }
        }
    ifile.close();
    for (int i=0; i<=n-1; i++) {
        for (int z=0; z<=n-1; z++) {
            if ( i==z ) {
                result[i][z] = 2001;
            } else {
                result[i][z] = findLCS(element[i], element[z],
                                       element[i].length(), element[z].length());
                if (result[i][z] < mincls) {
                    mincls = result[i][z];
                }
            }
        }
      }
    ofstream ofile;
    ofile.open (B);
 
    ofile << "Len: " << mincls;
        ofile.close();
    } else cout << "Unable to open file";
    return 0;
}