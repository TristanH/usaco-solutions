/*
ID: tristan3
PROG: zerosum
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
int oper[9];
long dig[10];
int n;
char symb[4]={'x','+','-',' '};

vector<string> winners(0);

void checkIfWin(){

    vector<int> newdigs(1);
    newdigs.push_back(dig[1]);
    for(int i=1;i<n;++i){ //sort out the spaces
        if(oper[i]==3){
            newdigs[newdigs.size()-1]*=10;
            newdigs[newdigs.size()-1]+=dig[i+1];
        }
        else
            newdigs.push_back(dig[i+1]);
    }

    int total = newdigs[1];

    int fixIndex=0;

    for(int i=1;i<n;++i){
        if(oper[i]==1)
            total+=newdigs[i+1-fixIndex];
        else if(oper[i]==2)
            total-=newdigs[i+1-fixIndex];
        else if(oper[i]==3)
            fixIndex++;
           //check for next operation without moving forward
    }


    if(total==0){
        stringstream ss;
        for(int i=1;i<=n;++i){
            ss<<dig[i];
            if(i!=n)
                ss<<symb[oper[i]];
        }
        winners.push_back(ss.str());
    }

    //just have to push winners into string and print for debug, then sort and win

}

void solve(int spot){

    if(spot==n){
        checkIfWin();
        return;
    }

    for(int i=1;i<=3;++i){
        oper[spot]=i;
        solve(spot+1);
    }
}

int main() {
  ofstream fout ("zerosum.out");
  ifstream fin ("zerosum.in");
  fin>>n;

  for(int i=0;i<=n;++i)
    dig[i]=i;

    solve(1);

    sort(winners.begin(),winners.end());

    for(int i=0;i<winners.size();++i)
        fout<<winners[i]<<endl;

    fout.close();
  return 0;
}




