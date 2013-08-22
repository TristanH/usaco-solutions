/*
ID: tristan3
PROG: inflate
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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef long long longo;

using namespace std;

//pretty much an easy backpack problem, hi dp

int main() {
    ifstream fin("inflate.in");
    ofstream fout("inflate.out");
    int mins, num;
    fin>>mins>>num;
    int cat[num][2];// the category's points and minutes

    for(int i=0;i<num;++i)
        fin>>cat[i][0]>>cat[i][1];


    int best[mins+1];//the best bscore after i minutes
    best[0]=0;
    for(int i=1;i<=mins;++i) best[i]=0;

    for(int a=1;a<=mins;++a){
        for(int b=0;b<num;++b){
            if(a-cat[b][1]>=0 && best[a-cat[b][1]]+cat[b][0]>best[a])
                best[a]=best[a-cat[b][1]]+cat[b][0];
        }
       // cout<<a<<" "<<best[a]<<endl;
    }

    fout<<best[mins]<<endl;



    fout.close();
    return 0;
}




