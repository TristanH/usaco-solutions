/*
ID: tristan3
PROG: castle
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
int map[50][50];
bool visited[50][50]={0};
int m,n;
int roomsize=0;
//memset(array, 0, sizeof array);

void reset(){
    roomsize=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            visited[i][j]=0;

}


void search(int i, int j){
    if(visited[i][j] || i<0 || i>=n || j<0 || j>=m )
        return;

    visited[i][j]=true;
    roomsize++;

    int use=map[i][j];

    if(use-8<0)
        search(i+1,j);
    else
        use-=8;

    if(use-4<0)
        search(i,j+1);
    else
        use-=4;

    if(use-2<0){
        search(i-1,j);
    }
    else
        use-=2;
    if(use-1<0)
        search(i,j-1);

}

int main(){

    ifstream fin("castle.in");
    ofstream fout("castle.out");
    fin>>m>>n;

    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            fin>>map[i][j];

    int numrooms=0;
    int bestroom=0;

    for(int i=0;i<n;++i) //for parts 1 and 2
        for(int j=0;j<m;++j)
            if(!visited[i][j]){
                search(i,j);
                numrooms++;
                if(roomsize>bestroom)
                    bestroom=roomsize;

                roomsize=0;
            }
    reset();
    fout<<numrooms<<endl;
    fout<<bestroom<<endl;
    bestroom=0;
    int besti, bestj;
    char bestdir;



        for(int j=0;j<m;++j){//go through all the room
            for(int i=n-1;i>=0;--i){

            if(map[i][j]==2 || map[i][j]==3|| map[i][j]==6 || map[i][j]==7|| map[i][j]==10|| map[i][j]==11|| map[i][j]==14|| map[i][j]==15){//if theres a wall there,
                map[i][j]-=2;//remove the wall
                search(i,j);//try to see if room is bigger
                if(roomsize>bestroom){
                    besti=i;
                    bestj=j;
                    bestdir='N';
                    bestroom=roomsize;
                }
                reset();
                map[i][j]+=2;
            }

             if(map[i][j]==4|| map[i][j]==5|| map[i][j]==6|| map[i][j]==7|| map[i][j]==12|| map[i][j]==13|| map[i][j]==14|| map[i][j]==15){//if theres a wall there,
                map[i][j]-=4;//remove the wall
                search(i,j);//try to see if room is bigger
                if(roomsize>bestroom){
                    besti=i;
                    bestj=j;
                    bestdir='E';
                    bestroom=roomsize;
                }
              //  cout<<i<<" "<<j<<" "<<" "<<roomsize<<endl;
                reset();
                map[i][j]+=4;
            }

        }
    }
    fout<<bestroom<<endl;
    fout<<besti+1<<" "<<bestj+1<<" "<<bestdir<<endl;



    fout.close();
    return 0;
}




