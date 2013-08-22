/*
ID: tristan3
PROG: checkers
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
int n=5;
bool board[13][13]={0};
vector<string> winners(0);
bool rowTaken[13]={0};

void markWin(){

    stringstream ss;

    for(int r=0;r<n;++r)
        for(int c=0;c<n;++c)
            if(board[r][c])
                ss<<c+1;

    winners.push_back(ss.str());

}

bool canPlace(int r, int c){
    if(rowTaken[r])
        return false;


    for(int i=1;r-i>=0 && c-i>=0;++i)
        if(board[r-i][c-i])
            return false;

    for(int i=1;r+i<n && c+i<n;++i)
        if(board[r+i][c+i])
            return false;


    for(int i=1;r+i<n && c-i>=0;++i)
        if(board[r+i][c-i])
            return false;


    for(int i=1;r-i>=0 && c+i<n;++i)
        if(board[r-i][c+i])
            return false;

    return true;
}

void findQueens(int col){

    cout<<col<<endl;

    if(col==n-1){
        cout<<"!"<<endl;
        markWin();
        return;
    }


    for(int r=0;r<n;++r){
        if(canPlace(r,col+1)){
            board[r][col+1]=true;
            rowTaken[r]=true;
            findQueens(col+1);
            rowTaken[r]=false;
            board[r][col+1]=false;
        }
    }


}

int main(){

    ifstream fin("checker.in");
    ofstream fout("checker.out");
    fin>>n;

    findQueens(0);

    for(int i=0;i<3;++i)
        fout<<winners[i]<<endl;
    fout<<winners.size()<<endl;

    fout.close();
    return 0;
}




