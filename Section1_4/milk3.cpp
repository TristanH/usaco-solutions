/*
ID: tristan3
PROG: milk3
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

int bin[4]={0};
int size[4]={0};

int used[1000][4];
int usedAt=0;

void tryMoves(){

  //  cout<<bin[1]<<" "<<bin[2]<<" "<<bin[3]<<endl;

    for(int i=0;i<usedAt;++i){
        if(used[i][1]==bin[1] && used[i][2]==bin[2] && used[i][3]==bin[3])
            return;
    }

    used[usedAt][1]=bin[1];
    used[usedAt][2]=bin[2];
    used[usedAt][3]=bin[3];
    usedAt++;

    for(int i=1;i<4;++i){
        for(int j=1;j<4;++j){
            if(j!=i){
                int lasti=bin[i];
                int  lastj=bin[j];

                if(bin[i]+bin[j]>size[j]){
                    bin[j]=size[j];
                    bin[i]-=size[j]-lastj;
                }
                else if(bin[i]+bin[j]<=size[j]){
                    bin[i]=0;
                    bin[j]+=lasti;
                }
                tryMoves();

                bin[i]=lasti;
                bin[j]=lastj;
            }
        }
    }
}

int main(){

    ifstream fin("milk3.in");
    ofstream fout("milk3.out");

    fin>>size[1]>>size[2]>>size[3];
    bin[3]=size[3];

    tryMoves();


    vector<int> win(0);

    for(int i=0;i<usedAt;++i){
        if(used[i][1]==0)
            win.push_back(used[i][3]);
    }
    sort(win.begin(), win.end());

    for(int i=0;i<win.size();++i){
        fout<<win[i];
        if(i!=win.size()-1)
            fout<<" ";
    }

    fout<<endl;
}
