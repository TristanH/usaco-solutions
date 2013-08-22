/*
ID: tristan3
PROG: sprime
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

bool notPrime[1000000]={0};

bool isPrime(long in){

    if(in<1000000)
        return !notPrime[in];

    for(long i=2;i<=sqrt(in);++i){
        if(in%i==0)
            return false;
    }
    return true;
}

int main(){

    ifstream fin("sprime.in");
    ofstream fout("sprime.out");

    int n;
    fin>>n;

    notPrime[1]=true;
    notPrime[0]=true;

    for(int i=4;i<1000000;i+=2)
        notPrime[i]=true;

    for(int i=3;i<1000000;i+=2){
        if(!notPrime[i])
            for(int j=2*i;j<1000000;j+=i)
                notPrime[j]=true;
    }

    long top=(long)pow(10,n);


    for(long i=top/10+1;i<top;i+=2){
        for(long j=top/10;j>=1;j/=10){//1000,100,10,1
            if(!isPrime(i/j))
                break;

            if(j==1)
                fout<<i<<endl;
        }

    }

    fout.close();
}
