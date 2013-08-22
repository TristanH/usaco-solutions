/*
ID: tristan3
PROG: holstein
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

int needed[25];
int neededcopy[25];
int vit[15][25];
int v,g;

int bestScoops=99999;
int bestsum=99999;
string winstr;


string toBinString(int in){

    string out="";
    stringstream ss;

    while(true){
        ss<<in%2;
        out.append(" ");
        if(in<=1)
            break;
        in/=2;
    }
    while(out.length()<g){
        out.append(" ");
        ss<<0;
    }

    string temp=ss.str();

    for(int i=0;i<temp.length();++i)
        out[i]=temp[temp.length()-1-i];


    return out;

}


void tryMoves(string use){

  //  cout<<use<<endl;

    int numScoops=0;
    int sum=0;
    for(int i=0;i<use.length();++i){
        if(use[i]=='1'){
            numScoops++;
            for(int j=0;j<v;++j){
                sum+=vit[i][j];
                needed[j]-=vit[i][j];
            }
        }
    }
    if(numScoops>bestScoops)
        return;

    if(numScoops==bestScoops && sum>bestsum )
        return;

    for(int j=0;j<v;++j)
        if(needed[j]>0)
            return;

    //if you get here, youve found a current winner
 //   cout<<"!"<<endl;
    bestScoops=numScoops;
    winstr=use;

}

int main(){
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");

    fin>>v;
    for(int i=0;i<v;++i){
        fin>>needed[i];
        neededcopy[i]=needed[i];
    }

    fin>>g;
    for(int i=0;i<g;++i)
        for(int j=0;j<v;++j){
            fin>>vit[i][j];
        }

        string current;

  for(int i=0;i<pow(2,g);++i){
        current=toBinString (i);
        tryMoves(current);
        for(int j=0;j<v;++j)
            needed[j]=neededcopy[j];

    }
    int end;
    for(int i=winstr.length();i>=0;--i)
        if(winstr[i]=='1'){
            end=i;
            break;
        }

    fout<<bestScoops<<" ";
    for(int i=0;i<=end;++i){
        if(winstr[i]=='1'){
            fout<<i+1;
            if(i!=end)
                fout<<" ";
        }
    }
    fout<<endl;
    fout.close();
    return 0;
}




