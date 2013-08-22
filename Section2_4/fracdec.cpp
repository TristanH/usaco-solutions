/*
ID: tristan3
PROG: fracdec
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
#include <queue>
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef long long longo;

using namespace std;


//say sequence has to repeat atleast 10 times
int main() {
    ifstream fin("fracdec.in");
    ofstream fout("fracdec.out");

    int num,den;
    fin>>num>>den;
    stringstream ss;
    ss<<num;
    string inNum;
    inNum=ss.str();
    string out(100000,' ');

    int addOn, current=0;
    int upTo;

    short hitCurrent[1000001];
    for(int i=0;i<1000001;++i)
        hitCurrent[i]=0;

    for(int i=0;true;++i){

        if(i<inNum.size()){
            addOn=inNum[i]-'0';
        }
        else{
            addOn=0;
            if(i==inNum.size()){
                out[i]='.';
                continue;
            }
        }

        current*=10;
        current+=addOn;
        out[i]=current/den+'0';

        if(i>=inNum.size()){
            if(hitCurrent[current]!=0){
                //youve won
                upTo=i;
                break;
            }
            else
                hitCurrent[current]=i;

        }
      //  cout<<current<<endl;
        current%=den;
    }

    for(int i=0;i<90;++i)
        cout<<out[i];

    cout<<endl;


    bool doneZeros=false;

    stringstream sout;

    if(1.0*num/den<1)
        sout<<"0";

    for(int i=0;i<hitCurrent[current];++i){
        if(out[i]!='0' || doneZeros){
            sout<<out[i];
            doneZeros=true;
        }
    }

    if(out.substr(hitCurrent[current],upTo-hitCurrent[current])=="0"){
        if(num/den==1.0*num/den)
            sout<<0;
    }
    else
        sout<<"("<<out.substr(hitCurrent[current],upTo-hitCurrent[current])<<")";

    string use=sout.str();

    for(int i=0;i<use.size();++i){
        fout<<use[i];
        if((i+1)%76==0)
            fout<<endl;
    }



    fout<<endl;
    fout.close();
    return 0;
}




