/*
ID: tristan3
PROG: preface
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
ifstream fin("preface.in");
ofstream fout("preface.out");

int numUsed[7]={0};
int val[7]={1000,500,100,50,10,5,1};
char convert[7]={'M','D','C','L','X','V','I'};
vector<int> lastUsed(0);


void addCounts(int in){
    int size;
    int numLeft=in;
    while(numLeft>0){
      //  cout<<numLeft<<endl;
        for(int i=0;i<7;++i){
            if(val[i]<=numLeft){
                numLeft-=val[i];
                numUsed[i]++;
                lastUsed.push_back(i);
                size=lastUsed.size();
                if(size>3 && lastUsed[size-1]==lastUsed[size-2] && lastUsed[size-1]==lastUsed[size-3]&& lastUsed[size-1]==lastUsed[size-4]){
                    numUsed[i]-=3;
                    numUsed[i-1]++;
                    lastUsed.pop_back();lastUsed.pop_back();lastUsed.pop_back();
                    lastUsed.push_back(i-1);

                    size=lastUsed.size();
                    if(size<3)
                        break;

                    if(val[lastUsed[size-1]]==5 &&val[lastUsed[size-2]]==1 &&val[lastUsed[size-3]]==5){
                        lastUsed.pop_back();lastUsed.pop_back();lastUsed.pop_back();
                        lastUsed.push_back(6);
                        lastUsed.push_back(4);
                        numUsed[5]-=2;
                        numUsed[4]++;
                    }
                    if(val[lastUsed[size-1]]==50 &&val[lastUsed[size-2]]==10 &&val[lastUsed[size-3]]==50){
                        lastUsed.pop_back();lastUsed.pop_back();lastUsed.pop_back();
                        lastUsed.push_back(4);
                        lastUsed.push_back(2);
                        numUsed[3]-=2;
                        numUsed[2]++;
                    }
                    if(val[lastUsed[size-1]]==500 &&val[lastUsed[size-2]]==100 &&val[lastUsed[size-3]]==500){
                        lastUsed.pop_back();lastUsed.pop_back();lastUsed.pop_back();
                        lastUsed.push_back(2);
                        lastUsed.push_back(0);
                        numUsed[1]-=2;
                        numUsed[0]++;
                    }


                }

                break;
            }
        }
    }
    size=lastUsed.size();

    if(size>3 && lastUsed[size-1]==lastUsed[size-2] && lastUsed[size-1]==lastUsed[size-3]&& lastUsed[size-1]==lastUsed[size-4]){
        numUsed[lastUsed[size-1]]-=3;
        numUsed[lastUsed[size-1]-1]++;
    }

    lastUsed.clear();
}

int main(){

    int n;
    fin>>n;

    for(int i=1;i<=n;++i)
        addCounts(i);

/*    for(int i=1;i<=20;++i){
        addCounts(i);
        for(int j=6;j>=0;--j){
            if(numUsed[j]!=0){
                cout<<convert[j]<<" "<<numUsed[j]<<endl;
            }
          //  numUsed[j]=0;
        }
        cout<<endl;
    }*/

    for(int i=6;i>=0;--i){
        if(numUsed[i]!=0){
            fout<<convert[i]<<" "<<numUsed[i]<<endl;
        }
    }

    fout.close();
    return 0;
}
