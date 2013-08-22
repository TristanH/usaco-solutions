/*
ID: tristan3
PROG: clocks
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

using namespace std;


vector<short>winmoves(0);
int bestsize=9999;
ifstream fin("clocks.in");
ofstream fout("clocks.out");
vector<short>currentSteps(0);
vector<short>currentTry(10,0);
vector<short>movesDone(10,0);

void move(){

        currentTry[1]+=3*movesDone[1];
        currentTry[2]+=3*movesDone[1];
        currentTry[4]+=3*movesDone[1];
        currentTry[5]+=3*movesDone[1];

        for(int i=1;i<4;++i)
            currentTry[i]+=3*movesDone[2];

        currentTry[2]+=3*movesDone[3];
        currentTry[3]+=3*movesDone[3];
        currentTry[5]+=3*movesDone[3];
        currentTry[6]+=3*movesDone[3];

        currentTry[1]+=3*movesDone[4];
        currentTry[4]+=3*movesDone[4];
        currentTry[7]+=3*movesDone[4];

        currentTry[2]+=3*movesDone[5];
        currentTry[4]+=3*movesDone[5];
        currentTry[5]+=3*movesDone[5];
        currentTry[6]+=3*movesDone[5];
        currentTry[8]+=3*movesDone[5];

        currentTry[3]+=3*movesDone[6];
        currentTry[6]+=3*movesDone[6];
        currentTry[9]+=3*movesDone[6];

        currentTry[4]+=3*movesDone[7];
        currentTry[5]+=3*movesDone[7];
        currentTry[7]+=3*movesDone[7];
        currentTry[8]+=3*movesDone[7];

        currentTry[7]+=3*movesDone[8];
        currentTry[8]+=3*movesDone[8];
        currentTry[9]+=3*movesDone[8];

        currentTry[5]+=3*movesDone[9];
        currentTry[6]+=3*movesDone[9];
        currentTry[8]+=3*movesDone[9];
        currentTry[9]+=3*movesDone[9];

}

bool allAreGood(){
    for(int i=1;i<10;++i)
        if(currentTry[i]>24)
            return false;
    return true;

}

void seeIfWon(){

       move();

      for(int i=1;i<10;++i){
        if(currentTry[i]%12!=0)
            break;
        else if(i==9){//youve won

            int numOfMoves=0;
            vector<short> movesStack(0);
            for(int j=1;j<10;++j){
                numOfMoves+=movesDone[j];
                for(int k=0;k<movesDone[j];++k)
                    movesStack.push_back(j);
            }

            if(numOfMoves<bestsize){
                cout<<"wooh";
                bestsize=numOfMoves;
                winmoves.clear();
                winmoves=movesStack;
            }
        }
    }

}
int main(){

   //simplify input to 1d 1-9 with values 3,6,9,12
    for(int i=1;i<10;++i){
        fin>>currentTry[i];
    }
    vector<short> begin=currentTry;

    for(int i=0;i<262144 ;++i){
        seeIfWon();
        for(int j=1;j<10;++j){
            if(movesDone[j]<3){
                movesDone[j]++;
                break;
            }
            else
                movesDone[j]=0;
        }
        currentTry=begin;
    }

    for(int i=0;i<winmoves.size();++i){
        fout<<winmoves[i];
        if(i!=winmoves.size()-1)
            fout<<" ";
    }
    fout<<endl;

    return 0;
}
