/*
ID: tristan3
PROG: namenum
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
long long n;


long long toNum(string in){
    long long times=pow(10,in.length()-1);
    long long out=0;

    for(int i=0;i<in.length();++i){
        if(in[i]>='A' && in[i]<='C'){
            out+=times*2;
        }
        else if(in[i]>='D' && in[i]<='F'){
            out+=times*3;
        }
        else if(in[i]>='G' && in[i]<='I'){
            out+=times*4;
        }
        else if(in[i]>='J' && in[i]<='L'){
            out+=times*5;
        }
        else if(in[i]>='M' && in[i]<='O'){
            out+=times*6;
        }
        else if(in[i]>='P' && in[i]<='S'){
            out+=times*7;
        }
        else if(in[i]>='T' && in[i]<='V'){
            out+=times*8;
        }
        else if(in[i]>='W' && in[i]<='Y'){
            out+=times*8;
        }

        times/=10;
    }

    return out;


}


int main(){

    ifstream fin("namenum.in");
    ofstream fout("namenum.out");

    string at;
    fin>>at;
    stringstream(at)>>n;

    fin.close();
    fin.open("dict.txt");

    int sames=0;

    cout<< toNum("KRISTOPHER");
    while(!fin.eof()){
        fin>>at;

        if(toNum(at)==n){
            fout<<at<<endl;
            sames++;
        }

    }

    if(sames==0)
        fout<<"NONE"<<endl;

    return 0;
}
