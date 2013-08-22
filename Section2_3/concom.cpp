/*
ID: tristan3
PROG: concom
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
typedef long long longo;

using namespace std;

struct companyLink{
    long c1;
    long c2;
};

bool compareLinks(const companyLink &a, const companyLink &b)
{
    return a.c1*200+a.c2 < b.c1*200+b.c2;
}

int owns[102][102];
vector<string> winners(0);
vector<companyLink> winners2(0);
set<string> hasOwned;
int highestN=-1;

void addToWins(int t1, int t2){

    if(t1==t2)
        return;

    stringstream ss;
    ss<<t1<<" "<<t2;
    string current=ss.str();

    companyLink cLink; cLink.c1=t1; cLink.c2=t2;

    if(hasOwned.find(current)!=hasOwned.end())
        return;
    else{
        winners.push_back(current);
        winners2.push_back(cLink);
        hasOwned.insert(current);
    }
}

void addOwnageFromTo(int from, int to){
    if(from==to)
        return;

  //  cout<<"adding ownage from "<<from<<" to "<<to<<endl;

    for(int i=1;i<=highestN;++i){
        if(owns[from][i]>0 && owns[to][i]<=50){

            owns[to][i]+=owns[from][i];

            if(owns[to][i]>50 && owns[to][i]-owns[from][i]<=50){
                //if adding this ownage from the current company, then its a new check weve gotta do
                addOwnageFromTo(i,to);
                addToWins(to,i);
            }
        }
    }
}

void checkOwnage(int check){
    cout<<check<<endl;
    for(int i=1;i<=highestN;++i){
        if(owns[check][i]>50){
            addOwnageFromTo(i,check);
        }
    }
}

int main() {
    ifstream fin ("concom.in");
    ofstream fout ("concom.out");
    int n;
    fin>>n;

    int t1,t2,t3;
    for(int i=0;i<101;++i) for(int j=0;j<101;++j) owns[i][j]=0;

    for(int i=0;i<n;++i){
        fin>>t1>>t2>>t3;
        owns[t1][t2]=t3;
        if(t3>50)
            addToWins(t1,t2);

        if(t1>highestN)
            highestN=t1;
        if(t2>highestN)
            highestN=t2;
    }

    for(int i=1;i<=highestN;++i){
        checkOwnage(i);
    }


    sort(winners2.begin(),winners2.end(), compareLinks);


    for(int i=0;i<winners2.size();++i)
        fout<<winners2[i].c1<<" "<<winners2[i].c2<<endl;

    fout.close();
    return 0;
}




