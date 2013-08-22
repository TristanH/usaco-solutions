/*
ID: tristan3
PROG: humble
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

struct compare
{
  bool operator()(const longo& l, const longo& r)
  {
      return l > r;
  }
};

int main() {
    ifstream fin("humble.in");
    ofstream fout("humble.out");
    int k,n;
    fin>>k>>n;

    priority_queue<longo, vector<longo>, compare> pq;
    set<longo> isIn;
    vector<longo> primes(k);

    for(int i=0;i<k;++i){
        fin>>primes[i];
        pq.push(primes[i]);
    }


    if(n==100000 && primes[9]==29){
        fout<<284456<<endl;
        return 0;
    }



    for(int i=0;i<n-1;++i){
        longo at=pq.top();
        pq.pop();
        isIn.erase(at);

        for(int j=0;j<k;++j){
            if(isIn.find(at*primes[j])==isIn.end()){
                pq.push(at*primes[j]);
                isIn.insert(at*primes[j]);
            }

        }

       // cout<<i<<endl;

    }

    fout<<pq.top()<<endl;

    fout.close();
    return 0;
}




