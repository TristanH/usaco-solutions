/*
ID: tristan3
PROG: pprime
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

bool isPrime(long in){
    for(int i=2;i<=sqrt(in);++i){
        if(in%i==0)
            return false;
    }
    return true;
}


int main(){

    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
    int a,b;
    fin>>a>>b;

    //first get all da palindromes
    vector<long> pals(0);
    stringstream ss;
    ss<<b;
    string use=ss.str();

    for(int d1=1;d1<10;++d1)
        pals.push_back(d1);

        if(use.length()>=2)
         for(int d1=1;d1<10;++d1)
                    pals.push_back(d1*10+d1);

                    if(use.length()>=3)
         for(int d1=1;d1<10;++d1)
            for(int d2=0;d2<10;++d2)
                    pals.push_back(d1*100+d2*10+d1);


    if(use.length()>=4)
         for(int d1=1;d1<10;++d1)
            for(int d2=0;d2<10;++d2)
                    pals.push_back(d1*1000+d2*100+d2*10+d1);


    if(use.length()>=5)
         for(int d1=1;d1<10;++d1)
            for(int d2=0;d2<10;++d2)
                for(int d3=0;d3<10;++d3)
                            pals.push_back(d1*10000+d2*1000+d3*100+d2*10+d1);

    if(use.length()>=6)
         for(int d1=1;d1<10;++d1)
            for(int d2=0;d2<10;++d2)
                for(int d3=0;d3<10;++d3)
                            pals.push_back(d1*100000+d2*10000+d3*1000+d3*100+d2*10+d1);


    if(use.length()>=7)
         for(int d1=1;d1<10;++d1)
            for(int d2=0;d2<10;++d2)
                for(int d3=0;d3<10;++d3)
                    for(int d4=0;d4<10;++d4)
                            pals.push_back(d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1);

    if(use.length()>=8)
         for(int d1=1;d1<10;++d1)
            for(int d2=0;d2<10;++d2)
                for(int d3=0;d3<10;++d3)
                    for(int d4=0;d4<10;++d4)
                            pals.push_back(d1*10000000+d2*1000000+d3*100000+d4*10000+d4*1000+d3*100+d2*10+d1);

    if(use.length()==9)
        for(int d1=1;d1<10;++d1)
            for(int d2=0;d2<10;++d2)
                for(int d3=0;d3<10;++d3)
                    for(int d4=0;d4<10;++d4)
                        for(int d5=0;d5<10;++d5){
                            pals.push_back(d1*100000000+d2*10000000+d3*1000000+d4*100000+d5*10000+d4*1000+d3*100+d2*10+d1);
                    }

    //have all palindromes

    vector<long> win(0);

    for(int i=0;i<pals.size();++i)
        if( pals[i]<=b && pals[i]>=a && isPrime(pals[i]))
            win.push_back(pals[i]);

    for(int i=0;i<win.size();++i)
        fout<<win[i]<<endl;


    fout.close();
}
