/*
ID: tristan3
PROG: calfflac
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


bool isPunc(char in){
    return in<'A' || in>'Z' && in<'a' || in>'z';
}



int main(){

    ifstream fin("calfflac.in");
    ofstream fout("calfflac.out");
    char* forw= new char[20000]();
    char* back= new char[20000]();
    int size;

    fin.read(forw,20000);
    forw[fin.gcount()]=0;


    for(int i=0;i<20000;++i){//find size of char array
        if(forw[i]==0){
            size=i;
            break;
        }
    }

    for(int i=0;i<size;++i){
        back[i]=forw[size-1-i];
    }

    int count=1, bestcount=1, beststart=0, bestr, bestl;
    int r, l,next=0;

    cout<<forw[727]<<forw[728]<<forw[729];

    for(int i=0;i<size;++i){
        if(isPunc(forw[i]))
            continue;

        r=1;
        l=1;


        while(isPunc(forw[i+r+next])){
            next++;
        }
        if(toupper(forw[i+r+next])==toupper(forw[i])){
            r+=next+1;
            count++;
        }

        if(next>0)
            cout<<i<<endl;
        next=0;


        for(int j=1;j<20000;++j){
            while(i+r<size && isPunc(forw[i+r]))
                r++;
            while(i-l>=0 && isPunc(forw[i-l]))
                l++;
            if(i+r>size || i-l<0 ||toupper(forw[i-l])!=toupper(forw[i+r]) )
                break;

            count+=2;

            r++;
            l++;

        }
      //  if(i>size/2-50 && i<size/2+50)
      //      cout<<i<<": "<<l<<" "<<r<<endl;
        if(count>bestcount){
            bestcount=count;
            beststart=i;
            bestr=r;
            bestl=l;
        }

        count=1;

    }


    cout<<beststart;

    bestl--; //some fixes for formatting
    bestr--;
    fout<<bestcount<<endl;

    for(int i=beststart-bestl;i<=beststart+bestr;++i)//remove starting spacing
        if(!isPunc(forw[i]))
            break;
        else
            bestl--;
    for(int i=beststart+bestr;i>=beststart-bestl;--i) //remove end spacing
        if(!isPunc(forw[i]))
            break;
        else
            bestr--;


    for(int i=beststart-bestl;i<=beststart+bestr;++i)
            fout<<forw[i];

    fout<<endl;
    return 0;
}
