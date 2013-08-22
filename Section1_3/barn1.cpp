/*
ID: tristan3
PROG: barn1
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

    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    int s, m,c,temp;
    fin>>m>>s>>c;
    bool* stalls=new bool[s]();
    bool* fixed=new bool[s]();
    int min=9999, max=-1;


    for(int i=0;i<c;++i){
        fin>>temp;
        stalls[temp-1]=true;
        if(temp-1>max)
            max=temp-1;
        if(temp-1<min)
            min=temp-1;
    }

    for(int i=0;i<s;++i)
        if(i>=min && i<=max)
            fixed[i]=1;


    int removed=0;
    int start=0,length=0;
    int bests=0,bestl=0;


    for(int i=2;i<=m;++i){//build on each solution

        for(int j=0;j<s;++j){
            if(fixed[j] && !stalls[j]){
                length++;
                if(length>bestl){
                    bestl=length;
                    bests=start;
                }
            }
            else{
                start=j+1;
                length=0;
            }
        }

        for(int j=0;j<s;++j)
            if(j>=bests && j<bestl+bests)
                fixed[j]=false;



        cout<<bests<<" "<<bestl;

        start=0;
        length=0;
        bestl=0;
        bests=0;


        for(int i=0;i<s;++i)
            cout<<fixed[i];
        cout<<endl;

    }

    for(int i=0;i<s;++i)
        if(fixed[i])
            removed++;

    fout<<removed<<endl;


    return 0;
}




