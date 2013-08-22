/*
ID: tristan3
PROG: money
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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef long long longo;

using namespace std;


int main() {//more dp, oh boy
    ifstream fin ("money.in");
    ofstream fout ("money.out");
    int v,n;
    fin>>v>>n;
    int coin[v];
    for(int i=0;i<v;++i)
        fin>>coin[i];

    longo combos[n+1];
    for(int i=0;i<=n;++i) combos[i]=0;
    combos[0]=1;

    for(int j=0;j<v;++j){
        for(int i=1;i<=n;++i){
            if(i-coin[j]>=0)
                combos[i]+=combos[i-coin[j]];
        }
    }


    fout<<combos[n]<<endl;

    fout.close();
    return 0;
}




