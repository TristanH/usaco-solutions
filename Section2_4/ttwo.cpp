/*
ID: tristan3
PROG: ttwo
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

char map[10][10];
int dir[255];
int x[255];
int y[255];


bool canGoForward(char at){

        if(dir[at]%4==0)//north
            return y[at]-1>=0 && map[y[at]-1][x[at]]!='*';
        else if(dir[at]%4==1)
            return x[at]+1<10 && map[y[at]][x[at]+1]!='*';
        else if(dir[at]%4==2)
            return y[at]+1<10 && map[y[at]+1][x[at]]!='*';
        else
            return x[at]-1>=0 && map[y[at]][x[at]-1]!='*';

}

void goForward(char at){
    if(dir[at]%4==0)//north
        y[at]--;
    else if(dir[at]%4==1)
        x[at]++;
    else if(dir[at]%4==2)
        y[at]++;
    else
        x[at]--;
}

int main() {
    ifstream fin ("ttwo.in");
    ofstream fout ("ttwo.out");

    string current;
    dir['f']=0;
    dir['c']=0;


    for(int i=0;i<10;++i){
        fin>>current;
        for(int j=0;j<10;++j){
            map[i][j]=current[j];
            if(map[i][j]=='F'){
                x['f']=j;
                y['f']=i;
            }
            if(map[i][j]=='C'){
                x['c']=j;
                y['c']=i;
            }
        }
    }

    set<string> pos;
    int moves=0;

    while(true){
        if(x['f']==x['c'] && y['f']==y['c'])//check if they collide
            break;

        stringstream ss;
        ss<<x['f']<<y['f']<<" "<<dir['f']%4<<" "<<x['c']<<y['c']<<" "<<dir['c']%4;
        current=ss.str();

        if(pos.find(current)!=pos.end()){ //check if they are in an infinite loop
            moves=0;
            break;
        }
        else
            pos.insert(current);



        cout<<current<<endl;

        if(canGoForward('f'))
            goForward('f');
        else
            dir['f']++;//rotate it

        if(canGoForward('c'))
            goForward('c');
        else
            dir['c']++;

        moves++;
    }

    fout<<moves<<endl;

    fout.close();
    return 0;
}




