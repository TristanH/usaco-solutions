/*
ID: tristan3
PROG: sort3
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

int main(){
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");
    int n;
    fin>>n;
    int key[n];
    int count[4]={0,0,0,0};

    for(int i=0;i<n;++i){//get input and count the numbers of each
        fin>>key[i];
        count[key[i]]++;
    }
    count[2]+=count[1];
    count[3]+=count[2];
    int switches=0;
    int temp;

    //go through where all the ones should be, removing any twos or threes if its optimal to both nums
    for(int at=0;at<count[1];++at){
        if(key[at]==2 ){
            for(int b=count[1];b<count[2];++b){
                if(key[b]==1){//found an optimal switch
                    switches++;
                    key[b]=2;
                    key[at]=1;
                    break;
                }
            }
        }
        else if(key[at]==3){
            for(int b=count[2];b<n;++b){
                if(key[b]==1){//found an optimal switch
                    switches++;
                    key[b]=3;
                    key[at]=1;
                    break;
                }
            }

        }
    }
  //  cout<<switches<<endl;
  //      cout<<endl;


    //go through where all the twos should be, removing any twos or threes if its optimal to both nums
    for(int at=count[1];at<count[2];++at){
        if(key[at]==3){
            for(int b=count[2];b<n;++b){
                if(key[b]==2){//found an optimal switch
                    switches++;
                    key[b]=3;
                    key[at]=2;
                    break;
                }
            }
        }
    }
  //  cout<<switches<<endl;

    //now all the ones to place
    for(int at=0;at<count[1];++at){
        if(key[at]!=1){
            for(int b=count[1];b<n;++b){
                if(key[b]==1){
                    key[b]=key[at];
                    key[at]=1;
                    switches++;
                    break;
                }
            }
        }
    }
  //  cout<<switches<<endl;
    //now last swap, fixing errythang else
    for(int at=count[1];at<count[2];++at){
        if(key[at]==3){
            for(int b=count[2];b<n;++b){
                if(key[b]==2){
                    key[b]=3;
                    key[at]=2;
                    switches++;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;++i)
       cout<<key[i]<<endl;

    fout<<switches<<endl;
    fout.close();
    return 0;
}




