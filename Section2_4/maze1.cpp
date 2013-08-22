/*
ID: tristan3
PROG: maze1
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

struct point{
    int x;
    int y;
};

char maze[100*2+1][38*2+1];
int scoredMaze[100*2+1][38*2+1];
bool visited[100*2+1][38*2+1];
int w,h;
queue<point> toCheck;
point at;


void tryAdding(int x, int y){
    if(y>0 && x>0 && y<h*2 && x<w*2 && !visited[y][x] && maze[y][x]==' '){
        visited[y][x]=true;
        point temp; temp.x=x;temp.y=y;
        if(scoredMaze[at.y][at.x]+1<scoredMaze[y][x])
            scoredMaze[y][x]=scoredMaze[at.y][at.x]+1;

        toCheck.push(temp);
    }
}


int main() {
    ifstream fin("maze1.in");
    ofstream fout("maze1.out");
    fin>>w>>h;
    int entX[2];
    int entY[2];
    int entAt=0;
    char current[2000];

    fin.getline(current,2000);

    for(int y=0;y<2*h+1;++y){
        fin.getline(current,2000);
        for(int x=0;x<w*2+1;++x){
            maze[y][x]=current[x];
            if(maze[y][x]==' ' && (y==0 || x==0 ||y==h*2 || x==w*2) ){

                if(x==0){ //finding entrances and correcting them
                entX[entAt]=x+1;
                entY[entAt]=y;
                entAt++;
                }
                if(x==w*2){
                    entX[entAt]=x-1;
                    entY[entAt]=y;
                    entAt++;
                }
                if(y==0){
                    entX[entAt]=x;
                    entY[entAt]=y+1;
                    entAt++;
                }
                if(y==h*2){
                    entX[entAt]=x;
                    entY[entAt]=y-1;
                    entAt++;
                }
            }
        }
    }
    for(int i=0;i<h*2+1;++i){
        for(int j=0;j<w*2+1;++j)
           scoredMaze[i][j]=9999;
    }

    for(int i=0;i<2;++i){
        at.x=entX[i];
        at.y=entY[i];
        scoredMaze[at.y][at.x]=1;
        toCheck.push(at);

        for(int i=0;i<h*2+1;i++){
            for(int j=0;j<w*2+1;++j)
                visited[i][j]=false;
        }
        visited[at.y][at.x]=true;

        while(!toCheck.empty()){
            at=toCheck.front();
            toCheck.pop();

            if(maze[at.y+1][at.x]==' ')
                tryAdding(at.x,at.y+2);
            if(maze[at.y-1][at.x]==' ')
                tryAdding(at.x,at.y-2);
            if(maze[at.y][at.x+1]==' ')
                tryAdding(at.x+2,at.y);
            if(maze[at.y][at.x-1]==' ')
                tryAdding(at.x-2,at.y);
        }
    }

   /* for(int i=0;i<h*2+1;++i){
        for(int j=0;j<w*2+1;++j)
            cout<<scoredMaze[i][j]<<"  ";
        cout<<endl;
    }
*/   int farthest=0;
    for(int i=0;i<h*2+1;++i){
        for(int j=0;j<w*2+1;++j)
            if(scoredMaze[i][j]>farthest && scoredMaze[i][j]!=9999)
                farthest=scoredMaze[i][j];
    }

    fout<<farthest<<endl;
    fout.close();
    return 0;
}




