/*
ID: tristan3
PROG: crypt1
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
#include <queue>
#include <map>
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef long long longo;

using namespace std;

int counts =0;
vector<int> set;


bool setContains(int in){
    for(int i=0;i<set.size();++i)
        if(set[i]==in)
            return true;


    return false;
}

 void checkCrypt(int a,int b, int c, int d, int e){

    int top=c+10*b+100*a;
    int bot=e+10*d;

    int now=top*e;
    for(int i=0;i<3;++i){

        if(i==0)
            now=top*e;
        if(i==1)
            now=top*d;
        if(i==2)
            now=top*bot;

        if(i<2 && now>=1000)
            return;//must be 3 digs if not final product

        if(!setContains(now%10))
            return;//first dig not in set
        now/=10;

        if(!setContains(now%10))
            return;//sec dig not in set
        now/=10;

        if(!setContains(now%10))
            return;//third dig not in set
        now/=10;

        if(i==2){
            if(!setContains(now%10))
                return;//fourth dig not in set
            now/=10;
        }


    }

    counts++; //if we're this far in the method, its a unique solution, add it up

}


int main() {
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    int n;
    fin>>n;
    set.resize(n);

    for(int i=0;i<n;++i)
        fin>>set[i];

   //this is a n^5 loop, luckily n can only go up to 10
   		for(int a=0;a<n;++a){
			for(int b=0;b<n;++b){
				for(int c=0;c<n;++c){
					for(int d=0;d<n;++d){
						for(int e=0;e<n;++e){
							checkCrypt(set[a],set[b],set[c],set[d],set[e]);
						}
					}

				}
			}

		}

    fout<<counts<<endl;

    fout.close();
    return 0;
}
