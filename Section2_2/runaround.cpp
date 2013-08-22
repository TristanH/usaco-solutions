/*
ID: tristan3
PROG: runround
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
#define setZeros(a) for(int i=0;i<10;++i)a[i]=0;
typedef long long longo;

using namespace std;

ofstream fout("runround.out");
ifstream fin("runround.in");

int main(){
    int m;

    fin>>m;
    longo max=1000000000;

    int dig[10];
    bool visited[10];
    setZeros(visited);
    bool won=false;
    bool lost=false;
    longo nowAt;
    int size=0;

    for(longo check=m+1;check<max;++check){
        nowAt=check;

        for(int i=1;nowAt>0;++i){
            dig[10-i]=nowAt%10;
            if(dig[10-i]==0 || visited[dig[10-i]]){
                lost=true;
                break;
            }
            visited[dig[10-i]]=true;
            nowAt/=10;
            size++;
        }

        setZeros(visited);
        if(lost){
            lost=false;
            size=0;
            continue;
        }

       int spot=10-size;
        nowAt=dig[spot];

        for(int i=0;i<size;++i){
            visited[nowAt]=true;
            spot+=nowAt%size;
            if(spot>=10)
                spot-=size;
            nowAt=dig[spot];
            if(i==size-1 && spot==10-size)
                won=true;
            if(visited[nowAt])
                break;
        }

        if(won){
            fout<<check<<endl;
            break;
        }
        cout<<check<<endl;
        setZeros(visited);
        size=0;
    }

    fout.close();
    return 0;
}




