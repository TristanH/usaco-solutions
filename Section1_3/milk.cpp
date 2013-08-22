/*
ID: tristan3
PROG: milk
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

    ifstream fin("milk.in");
    ofstream fout("milk.out");
    int n, m;
    fin>>n;
    fin>>m;

    int farmer[m][2];

    for(int i=0;i<m;++i){
        fin>>farmer[i][0];
        fin>>farmer[i][1];
    }
    bool changed=true;
    int temp1,temp2;

    while(changed){ //sort with bubble, only 5000 ints, nbd for quadratic
        changed=false;
        for(int i=0;i<m-1;++i){
            if(farmer[i][0]>farmer[i+1][0]){
                changed=true;
                temp1=farmer[i][0];
                temp2=farmer[i][1];
                farmer[i][0]=farmer[i+1][0];
                farmer[i][1]=farmer[i+1][1];
                farmer[i+1][0]=temp1;
                farmer[i+1][1]=temp2;
            }
        }

    }

    int left=n;
    int spent=0;

    for(int i=0;i<m;++i){
        if(left>farmer[i][1]){
            spent+=farmer[i][0]*farmer[i][1];
            left-=farmer[i][1];

        }
        else{
            spent+=left*farmer[i][0];
            break;
        }

    }

    fout<<spent<<endl;
    return 0;
}
