/*
ID: tristan3
PROG: frac1
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
#include <deque>

using namespace std;

struct fraction{
    int num;
    int den;
};

bool operator<(const fraction& a, const fraction& b) {
        return 1.0*a.num/a.den < 1.0*b.num/b.den;
    }

int gcd(int a, int b){
    if(b==0)
        return a;
    else
        return gcd(b, a % b);

}


int main(){
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");
    int n;
    fin>>n;

    vector<fraction> fractions(0);

    fraction use={0,1};
    fractions.push_back(use);
    int ugcd, useA, useB;

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(1.0*i/j<=1){
            ugcd=gcd(i,j);
            use={i/ugcd,j/ugcd};
                fractions.push_back(use);
            }
        }
    }
    sort(fractions.begin(),fractions.end());

    fout<<fractions[0].num<<"/"<<fractions[0].den<<endl;
    for(int i=1;i<fractions.size();++i){
        if(!(fractions[i].num==fractions[i-1].num && fractions[i].den==fractions[i-1].den))
            fout<<fractions[i].num<<"/"<<fractions[i].den<<endl;
    }

    fout.close();
    return 0;
}




