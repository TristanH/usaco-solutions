/*
ID: tristan3
PROG: transform
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

using namespace std;
int n;

vector<vector<char> > rotate90(vector<vector<char> >  in){

    vector<vector<char> > out (n, vector<char> (n));

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            out[j][n-1-i]=in[i][j];
        }
    }

    return out;
}


vector<vector<char> > reflect(vector<vector<char> >  in){

    vector<vector<char> > out (n, vector<char> (n));

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            out[i][n-1-j]=in[i][j];
        }
    }

    return out;
}


bool equals(vector<vector<char> >  in1, vector<vector<char> >  in2){

    bool returning=true;

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            if(in1[i][j]!=in2[i][j])
                returning=false;
    }
    return returning;
}

int main(){

    ifstream fin("transform.in");
    ofstream fout("transform.out");

    string at;
    fin>>at;
    n=atoi(at.c_str());

    vector<vector<char> > grid (n, vector<char> (n));
    vector<vector<char> > grid2 (n, vector<char> (n));
    vector<vector<char> > gridchange (n, vector<char> (n));


    for(int i=0;i<n;++i){
        fin>>at;
        for(int j=0;j<n;++j){
            grid[i][j]=at[j];
        }
    }
    for(int i=0;i<n;++i){
        fin>>at;
        for(int j=0;j<n;++j){
            grid2[i][j]=at[j];
        }
    }

    bool works=true;
    int win=0;

    do{
        //try first

        if(equals(rotate90(grid),grid2)){
            fout<<1<<endl;
            break;
        }

        if(equals(rotate90(rotate90(grid)),grid2)){
            fout<<2<<endl;
            break;
        }

        if(equals(rotate90(rotate90(rotate90(grid))),grid2)){
            fout<<3<<endl;
            break;
        }

        if(equals(reflect(grid),grid2)){
            fout<<4<<endl;
            break;
        }
        if(equals(rotate90(reflect(grid)),grid2) || equals(rotate90(rotate90(reflect(grid))),grid2) || equals(rotate90(rotate90(rotate90(reflect(grid)))),grid2)){
            fout<<5<<endl;
            break;
        }
        if(equals(grid, grid2)){
            fout<<6<<endl;
            break;
        }

        fout<<7<<endl;

    }while(false);

    return 0;
}
