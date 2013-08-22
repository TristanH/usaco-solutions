/*
ID: tristan3
PROG: contact
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
#include <map>
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef long long longo;

using namespace std;

bool isBetterBin(string a, string b){
    if(a.length()<b.length())
        return true;
    else if(a.length()>b.length())
        return false;

    for(int i=0;i<a.length();++i){
        if(a[i]!=b[i]){
            if(a[i]=='1') //if a is greater
                return false;
            else
                return true;
        }
    }
}

int main() {
    ifstream fin("contact.in");
    ofstream fout("contact.out");
    int a,b,n;
    string full;
    fin>>a>>b>>n;
    while(fin.good()){
        string templine;
        fin>>templine;
        full+=templine;
    }

    map<string, longo> patCount;

    //get all the patterns here
    for(int plength=a;plength<=b && plength<=full.length();++plength){
        for(int i=0;i<=full.length()-plength ;++i){
            patCount[full.substr(i,plength)]++;
        }
    }

    ///////////////////////////////print out the best n
    int lastbest=0;
    int freqCount=0;

    for(int i=0;i<=n && patCount.size()!=0;++i){
        int best=0;
        string bestname="";
        map<string,longo>::iterator it;

        for(it=patCount.begin();it!=patCount.end(); it++){

            if((*it).second>best ){
                best=(*it).second;
                bestname=(*it).first;
            }
            else if((*it).second==best  && isBetterBin((*it).first,bestname)){
                best=(*it).second;
                bestname=(*it).first;
            }

        }
        if(best==lastbest){
            if(freqCount==5){
                fout<<endl<<bestname;
                freqCount=-1;
            }
            else
                fout<<" "<<bestname;
            i--;
            freqCount++; //for keeping track of every 6 lines
        }

        else if (i!=n){
            if(i!=0)
                fout<<endl;
            fout<<best<<endl<<bestname;
            freqCount=0;
        }

        lastbest=best;
        patCount.erase(bestname);
    }

    fout<<endl;
//////////////////////////////////////////////////////////////

    fout.close();
    return 0;
}




