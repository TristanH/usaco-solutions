/*
ID: tristan3
PROG: stamps
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
#include <set>
#include <queue>
#include <map>
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef long long longo;

using namespace std;


int main() {
    ifstream fin("stamps.in");
    ofstream fout("stamps.out");

    int n,k;
    fin>>k>>n;//input

    int stampVal[n];
    int maxVal=0;

    for(int i=0;i<n;++i){//input again
        fin>>stampVal[i];
        if(stampVal[i]>maxVal)
            maxVal=stampVal[i];
    }

    int minStamps[maxVal*k+2];
    for(int i=1;i<=maxVal*k+1;++i){
        minStamps[i]=999999;
    }
    minStamps[0]=0;//need 0 stamps for a total of 0 cents

    for(int m=1;true;m++){
        for(int i=0;i<n;++i){
            if(m-stampVal[i]>=0 && minStamps[m-stampVal[i]]+1<minStamps[m] )
                minStamps[m]=minStamps[m-stampVal[i]]+1;
        }
        if(minStamps[m]>k){//weve found the break
            fout<<m-1<<endl;
            break;
        }
    }

    fout.close();
    return 0;
}




