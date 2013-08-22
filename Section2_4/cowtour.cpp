/*
ID: tristan3
PROG: cowtour
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

//figure out disjointed fields via dfs and mark nodes as one or the other
//precompute warshall for each field, so we know farthest from a is e with dist 12.07
//then try a hypotenuse path from every node of oneside to the other
//to check, simply add farthest from each connecting with connecting distance

struct point{
    long x;
    long y;
};

bool isFirstGroup[150]={0};
int n;
double adj[150][150];
point pos[150];
double maxDistFrom[150];
int inf=999999;

void dfs(int loc){
    isFirstGroup[loc]=true;
    for(int i=0;i<n;++i)
        if(adj[loc][i]!=inf && !isFirstGroup[i])
            dfs(i);
}

double dist(point a, point b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

int main() {
    ifstream fin("cowtour.in");
    ofstream fout("cowtour.out");
    fin>>n;
    string current;

    for(int i=0;i<n;++i){
        fin>>pos[i].x>>pos[i].y;
      //  cout<<pos[i].x<<" "<<pos[i].y<<endl;
    }

    for(int i=0;i<n;++i){
        fin>>current;
        for(int j=0;j<n;++j){
            if(current[j]=='0'){
                adj[i][j]=inf;
            }
            else{
                adj[i][j]=dist(pos[i],pos[j]);
            }
            if(i==j)
                adj[i][j]=0;
        }
    }

    dfs(0);

    for(int k=0;k<n;++k){ //find all shortest distances via warshall
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)
                if(adj[i][k]+adj[k][j]<adj[i][j])
                    adj[i][j] = adj[i][k]+adj[k][j];
        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            cout<<adj[i][j]<<" ";
        cout<<endl;
    }


    //now find max distance from each point
    for(int i=0;i<n;++i){
        maxDistFrom[i]=0;
        for(int j=0;j<n;++j){
            if(adj[i][j]<inf && i!=j && adj[i][j]>maxDistFrom[i])
                maxDistFrom[i]=adj[i][j];

        }
      //  cout<<i<<" "<<maxDistFrom[i]<<endl;
    }


    double shortest=inf;
    double tryDist=0;

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if( i!=j && adj[i][j]>=inf){
                tryDist = dist(pos[i],pos[j]) + maxDistFrom[i]+ maxDistFrom[j];

                for(int k=0;k<n;++k){
                    if((adj[k][i]<inf || adj[k][j]<inf) &&  maxDistFrom[k]>tryDist)
                        tryDist=maxDistFrom[k];
                }

                //cout<<i<<" to "<<j<<" ="<<tryDist<<endl;
                if(shortest>tryDist){
                    shortest=tryDist;
                //    cout<<i<<" to "<<j<<" with dist "<<tryDist<<endl;//dist(pos[i],pos[j])<<endl;
                }
            }
        }
    }
    fout.setf(ios::fixed);
    fout.precision(6);
    fout<<shortest<<endl;

    fout.close();
    return 0;
}




