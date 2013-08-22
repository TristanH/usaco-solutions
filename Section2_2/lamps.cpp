/*
ID: tristan3
PROG: lamps
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

using namespace std;

ifstream fin("lamps.in");
ofstream fout("lamps.out");
bool moves[4]={0,0,0,0};

void binplusplus(){
    for(int i=0;i<4;++i){
        if(moves[i]==0){
            moves[i]=1;
            break;
        }
        else
            moves[i]=0;
    }
}


int main(){
    //moves can either be done or not, as doing twice is same as none
    int n, c, at;
    fin>>n>>c;
    vector<int> on(0);
    vector<int> off(0);

  fin>>at;
    while(at!=-1){
        on.push_back(at);
        fin>>at;
    }

    fin>>at;
    while(at!=-1){
        off.push_back(at);
        fin>>at;
    }

    bool current[n];
    vector<string> wins(0);


    for(int i=0;i<16;++i, binplusplus()){ //try every possible outcome

        for(int i=0;i<n;++i) current[i]=true;

        if(moves[0]){
            for(int i=0;i<n;++i)
                current[i]=!current[i];
        }
        if(moves[1]){
            for(int i=0;i<n;++i)
                if((i+1)%2==1)
                    current[i]=!current[i];
        }
        if(moves[2]){
            for(int i=0;i<n;++i)
                if((i+1)%2==0)
                    current[i]=!current[i];
        }
        if(moves[3]){
            for(int i=0;i<n;++i)
                if((i+1)%3==1)
                    current[i]=!current[i];
        }

        int numMoves=0;
        for(int i=0;i<4;++i)
            if(moves[i])
                numMoves++;

        int numModTwo=numMoves%2;

       if(numMoves>c || numMoves%2!=c%2)
            continue; //this move couldnt happen

        bool endGood=true;
        for(int i=0;i<on.size();++i)
            if(!current[on[i]-1])
                endGood=false;

        for(int i=0;i<off.size();++i)
            if(current[off[i]-1])
                endGood=false;

        if(endGood){
            stringstream ss;
            for(int i=0;i<n;++i)
                ss<<current[i];
            wins.push_back(ss.str());

        }

    }
    sort(wins.begin(),wins.end());
    for(int i=0;i<wins.size();++i)
        if(i==0 || wins[i]!=wins[i-1])
            fout<<wins[i]<<endl;
    if(wins.size()==0)
        fout<<"IMPOSSIBLE"<<endl;
    fout.close();
    return 0;
}




