/*
ID: tristan3
PROG: dualpal
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

string toBase(long n, int base){
    string out="";
    long at=n;
    string temp;

    while(at>0){
        //cout<<at<<endl;
        stringstream ss;
        ss << at%base;
        temp=ss.str();
        if(temp.compare("10")==0)
            temp="A";
        else if(temp.compare("11")==0)
            temp="B";
        else if(temp.compare("12")==0)
            temp="C";
        else if(temp.compare("13")==0)
            temp="D";
        else if(temp.compare("14")==0)
            temp="E";
        else if(temp.compare("15")==0)
            temp="F";
        else if(temp.compare("16")==0)
            temp="G";
        else if(temp.compare("17")==0)
            temp="H";
        else if(temp.compare("18")==0)
            temp="I";
        else if(temp.compare("19")==0)
            temp="B";

        out.insert(0,temp);
        at/=base;

    }

    return out;
}

bool isPalo(string in){

    int i=0,j=in.length()-1;

    while(i<j){
        if(in[i]!=in[j])
            return false;
        i++;
        j--;
    }
    return true;

}



int main(){

    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");

    long n,s;
    string now;
    fin>>now;
    stringstream(now)>>n;
    fin>>now;
    stringstream(now)>>s;


    int goodcount=0;
    int ndone=0;
    long trying=s+1;

    for(int i=0;i<n;++i){

        while(true){
            //test all the bases

            for(int b=2;b<=10;++b){
                if(isPalo(toBase(trying,b)))
                    goodcount++;
            }
            if(goodcount>=2){
                ndone++;
                fout<< trying<<endl;
                cout<<trying<<endl;
                trying++;
                goodcount=0;
                break;

            }
            goodcount=0;
            trying++;
        }

    }




    return 0;
}
