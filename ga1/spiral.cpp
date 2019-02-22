#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "ArgumentManager.h"
using namespace std;

int matrix_size_by_string(string inp){
    double param = inp.length();
    double i = 0;
    double intpart;
    while ( modf(sqrt(param+i) , &intpart) != 0) {i++;};
    return sqrt(param+i);
};

int main (int argc, char** argv) {
    string inputtxt = "";

    if (argc < 2) {
        std::cout << "Usage: densemult \"input=<file>;output=<file>\"" << std::endl;
        return -1;
    }
    ArgumentManager am(argc, argv);
    
    string I = am.get("input");
    string O = am.get("output");
    
    ifstream ifile (I);
    if (ifile.is_open()) {
        getline (ifile, inputtxt); //go through each line
        ifile.close();

    int s = matrix_size_by_string(inputtxt);
    inputtxt.append(s*s - inputtxt.length(),'.'); //adding '.' exatly to an array size
    int n = s; /*n Size of the array*/
    string A[n][n];
    /*len is used to update(decrease) array size so that values cans be assign to them */
    int len=n,k=1,p=0,i;            /*k is to assign the values to the array from 1...n*n */
    
    ofstream ofile;
    ofile.open (O);
    
    while(k<=n*n)
    {
        for(i=p;i<len;i++)         /*Loop to access the first row of the array*/
        {
            A[p][i]=inputtxt[k++-1];
        }
        for(i=p+1;i<len;i++)      /*Loop tp access the last column of the array*/
        {
            A[i][len-1]=inputtxt[k++-1];
        }
        for(i=len-2;i>=p;i--)     /*Loop to access the last row of the array*/
        {
            A[len-1][i]=inputtxt[k++-1];
        }
        for(i=len-2;i>p;i--)      /*Loop to access the first column of the array*/
        {
            A[i][p]=inputtxt[k++-1];
        }
        p++;
        len=len-1;
        
    }
    if(!n%2)                      /*This block will run only if n is even*/
    {
        A[(n+1)/2][(n+1)/2]=n*n; /*It will assign the last value to the centremost element*/
    }
    for(i=0;i<n;i++)             /*This loop will print the array in matrix format*/
    {
        for(int j=0;j<n;j++)
        {
            ofile<<A[i][j];
        }
        ofile<<endl;
    }
    ofile.close();
    } else cout << "Unable to open file";
    
    return 0;
}
