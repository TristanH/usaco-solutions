/*
ID: tristan3
PROG: checker
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
int n;
bool board[13][13]={0};
vector<vector<int> > winners(0,vector<int>(13));
bool colTaken[13]={0};
bool dTaken[2][13*4];

void markWin(){

    vector<int> use(13);

    for(int r=0;r<n;++r)
        for(int c=0;c<n;++c)
            if(board[r][c])
                use[r]=c+1;

    winners.push_back(use);
}

bool canPlace(int r, int c){
    if(colTaken[c])
        return false;

    if(dTaken[0][r+c+1]|| dTaken[1][r+n-c+1])
        return false;

    return true;
}

void findQueens(int row){

    if(row==n-1){
        markWin();
        return;
    }


    for(int c=0;c<n;++c){
        if(canPlace(row+1,c)){
            dTaken[0][row+1+c+1]=true;
            dTaken[1][row+1+n-c+1]=true;
            board[row+1][c]=true;
            colTaken[c]=true;

            findQueens(row+1);

            dTaken[0][row+1+c+1]=false;
            dTaken[1][row+1+n-c+1]=false;
            colTaken[c]=false;
            board[row+1][c]=false;
        }
    }

}

int main(){

    ifstream fin("checker.in");
    ofstream fout("checker.out");
    fin>>n;

    findQueens(-1);

    for(int i=0;i<3;++i){
        for(int j=0;j<n;++j){
            fout<<winners[i][j];
            if(j!=n-1)
                fout<<" ";
        }
        fout<<endl;
    }
    fout<<winners.size()<<endl;

    fout.close();
    return 0;
}

