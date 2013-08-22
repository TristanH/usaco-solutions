/*
ID: tristan3
PROG: agrinet
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

int adj[100][100];

int main() {
    ifstream fin("agrinet.in");
    ofstream fout("agrinet.out");
    int n;
    fin>>n;

    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            fin>>adj[i][j];

    int distance[n];
    bool inTree[n];
    int source[n];
    int treeSize=0;
    int treeCost=0;
    for(int i=0;i<n;++i){
        distance[i]=999999;
        source[i]=-1;
        inTree[i]=false;
    }

    inTree[0]=true;
    treeSize=1;
    for(int i=1;i<n;++i){
        distance[i]=adj[0][i];
        source[i]=0;
    }

    int curBest, bestNode;

    while(treeSize<n){
        cout<<"lol";
        curBest=999998;

        for(int i=0;i<n;++i){
            if(!inTree[i] && curBest>distance[i]){
                curBest=distance[i];
                bestNode=i;
            }
        }

        treeSize++;
        treeCost+=curBest;
        inTree[bestNode]=true;

        for(int i=0;i<n;++i){
            if(adj[bestNode][i]<distance[i]){
                distance[i]=adj[bestNode][i];
                source[i]=bestNode;
            }
        }
    }

    fout<<treeCost<<endl;
    fout.close();
    return 0;
}




