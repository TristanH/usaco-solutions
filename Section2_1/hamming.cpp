/*
ID: tristan3
PROG: hamming
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

int n,b,d, maxsize;
ofstream fout("hamming.out");
vector < vector<short> > differs(512, vector<short> (0));
bool differsB[512][512]={0};

struct Binary{
    bool dig[8];
};

void plusplus(Binary &in){

    for(int i=0;i<b;++i){
        if(in.dig[i]==0){
            for(int j=0;j<i;++j)
                in.dig[j]=0;
            in.dig[i]=1;
            break;
        }
    }
}

int toInt(Binary in){
    int out=0;
    for(int i=0;i<b;++i)
        out+=in.dig[i]*pow(2,i);

    return out;
}

int numDiff(Binary b1, Binary b2 ){
    int num=0;

    for(int i=0;i<b;++i)
        if(b1.dig[i]!=b2.dig[i])
            num++;

    return num;
}

vector<short> currentGroup(0);
bool inGroup[512]={0};
bool won=false;

void expandGroup(int justAdded){

    if(currentGroup.size()==n &&!won){
        for(int i=0;i<n;++i){
            fout<<currentGroup[i];
            if((i+1)%10==0)
                fout<<endl;
            else if(i!=n-1)
                fout<<" ";
        }
        if((n)%10!=0)fout<<endl;
        won=true;
    }

    int use;
    for(int i=0;i<differs[currentGroup[0]].size();++i){
        use=differs[currentGroup[0]][i];
        if(!inGroup[use]){
            for(int j=0;j<currentGroup.size();++j){
                if(!differsB[use][currentGroup[j]])
                    break;
                else if(j==currentGroup.size()-1){//add to current group, its good
                    currentGroup.push_back(use);
                    inGroup[use]=true;
                    expandGroup(use);
                    if(won)
                        return;
                    inGroup[use]=false;
                    currentGroup.pop_back();
                }
            }
        }
    }
}


int main(){

    ifstream fin("hamming.in");

    fin>>n>>b>>d;
    maxsize=pow(2,b);

    Binary current={};


    for(int i=0;i<maxsize;++i,plusplus(current)){
        Binary compareTo={};
        for(int j=0;j<maxsize;++j,plusplus(compareTo)){
            if(numDiff(current, compareTo)>=d){
                differs[toInt(current)].push_back(toInt(compareTo));
                differsB[toInt(current)][toInt(compareTo)]=true;
            }
        }
    }

    for(int i=0;i<maxsize;++i){
        currentGroup.push_back(i);
        inGroup[i]=true;
        expandGroup(i);
        if(won)
            break;
        inGroup[i]=false;
        currentGroup.clear();
    }


    fout.close();
    return 0;
}




