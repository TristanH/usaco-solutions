/*
ID: tristan3
PROG: numtri
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(){

    ifstream fin("numtri.in");
    ofstream fout("numtri.out");

    int r;
    fin>>r;
    int tri[r][r];

    for(int i=0;i<r;++i){
        for(int j=0;j<=i;++j){
            fin>>tri[i][j];
        }
    }

    for(int i=r-2;i>=0;--i){
        for(int j=0;j<=i;++j){
            tri[i][j]+=max(tri[i+1][j],tri[i+1][j+1]);
        }
    }
    fout<<tri[0][0]<<endl;

    fout.close();
}
