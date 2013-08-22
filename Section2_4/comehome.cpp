/*
ID: tristan3
PROG: comehome
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

long INF = 9999999;

//simple shortest path problem
//set up pastures in an adjacency matrix and use warshalls
//find shortest path out of all cow nodes to node 'Z'
int main() {
    ifstream fin("comehome.in");
    ofstream fout("comehome.out");

    long adj[256][256];
    for(int i=0;i<256;++i)
        for(int j=0;j<256;++j)
            adj[i][j] = i==j ? 0 : INF;
    string t1, t2;
    long p, t3;

    fin>>p;

    for(int i=0;i<p;++i){
        fin>>t1>>t2>>t3;
        adj[t1[0]][t2[0]]= min(t3,adj[t1[0]][t2[0]]);
        adj[t2[0]][t1[0]]= min(t3, adj[t2[0]][t1[0]]);
    }

    for(int k=0;k<256;++k) //warshalllllllllll
        for(int i=0;i<256;++i)
            for(int j=0;j<256;++j)
                adj[i][j] = min(adj[i][k]+adj[k][j],adj[i][j]);

    char bestC;
    long bestPath=INF;


    for(int i='A';i<'Z';++i){
        if(adj[i]['Z']<bestPath){
            bestPath=adj[i]['Z'];
            bestC=i;
        }
    }



    fout<<bestC<<" "<<bestPath<<endl;



    fout.close();
    return 0;
}




