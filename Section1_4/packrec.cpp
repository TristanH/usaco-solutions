/*
ID: tristan3
PROG: packrec
LANG: C++
 */

//honestly, i have no recollection of how I did this
//I just remember it being my most hated question

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

int rec[4][2];
vector<int> pos(4);
vector<int> gooddims(0);
int minarea=10000;
int done=0;
ifstream fin("packrec.in");
ofstream fout("packrec.out");


bool goodContains(int in){

    for(int i=0;i<gooddims.size();++i)
        if(in==gooddims[i])
            return true;

    return false;
}



void doCheck(int h, int w,int n){

   //fout<<h<<" "<<w<<" "<<h*w<<" "<<n<<endl;
    if(w*h<minarea){
        minarea=h*w;
        gooddims.clear();
        if(h<w)
            gooddims.push_back(h);
        else
            gooddims.push_back(w);
    }
    else if(w*h==minarea && !goodContains(w) && !goodContains(h)){
        if(h<w)
            gooddims.push_back(h);
        else
            gooddims.push_back(w);
    }

}


int max1(int in1, int in2){
    if(in1>in2)
        return in1;
    else
        return in2;
}
int max1(int in1, int in2, int in3){
    return max1(max1(in1,in2),in3);
}

void tryRects(){

    int h, w;
    //try all the six rects, see if the best area can be beat, if it can push its areas onto the vector for later retrieval

    h=max1(max1(max1(rec[pos[0]][0],rec[pos[1]][0]),rec[pos[2]][0]),rec[pos[3]][0]);
    w=rec[0][1]+rec[1][1]+rec[2][1]+rec[3][1];

    doCheck(h,w,1);

    ////////2
    h=max1(rec[pos[0]][0], rec[pos[1]][0], rec[pos[2]][0]) +rec[pos[3]][1];
    w=max1(rec[pos[3]][0], rec[pos[0]][1]+rec[pos[1]][1]+rec[pos[2]][1]);

    doCheck(h,w,2);

    //////3
    h=max1(rec[pos[2]][0], rec[pos[1]][0]+ rec[pos[3]][1], rec[pos[0]][0]+rec[pos[3]][1]);
    w=max1(rec[pos[0]][1]+rec[pos[1]][1]+rec[pos[2]][1], rec[pos[3]][0]+ rec[pos[2]][1]);

    doCheck(h,w,3);

    //////////4
    h=max1(rec[pos[0]][0],rec[pos[1]][0]+ rec[pos[2]][0], rec[pos[3]][0]);
    w=rec[pos[0]][1]+ max1(rec[pos[1]][1],rec[pos[2]][1]) + rec[pos[3]][1];

    doCheck(h,w,4);

    ////////////5
    h=max1(rec[pos[0]][0]+rec[pos[1]][0],rec[pos[2]][0],rec[pos[3]][0]);
    w=max1(rec[pos[0]][1],rec[pos[1]][1]) + rec[pos[2]][1] + rec[pos[3]][1];

    doCheck(h,w,5);
    ///////////6

    h=max1(rec[pos[0]][0]+rec[pos[2]][0],rec[pos[1]][0]+rec[pos[3]][0]);
    w=rec[pos[0]][1]+rec[pos[1]][1];

    if(rec[pos[0]][0]<rec[pos[1]][0])
        w=max1(w,rec[pos[2]][1]+rec[pos[1]][1]);

    if(rec[pos[0]][0]+rec[pos[2]][0]>rec[pos[1]][0])
        w=max1(w,rec[pos[2]][1]+rec[pos[3]][1]);

    if(rec[pos[1]][0]<rec[pos[0]][0])
        w=max1(w,rec[pos[0]][1]+rec[pos[3]][1]);

    w=max(w,rec[pos[2]][1]);
    w=max(w,rec[pos[3]][1]);

    doCheck(h,w,6);

}


void doPerms(){
  pos[0]=0;
    pos[1]=1;
    pos[2]=2;
    pos[3]=3;

    for(int a=0;a<4;++a){
        for(int b=0;b<4;++b){
            while(true)
                if(b==a)
                    b++;
                else
                    break;

            if(b>3)
                break;
            for(int c=0;c<4;++c){
                while(true)
                if(c==a || c==b)
                    c++;
                else
                    break;
                if(c>3)
                    break;
                for(int d=0;d<4;++d){
                    while(true)
                        if(d==a || d==b || d==c)
                            d++;
                        else
                            break;
                    if(d>3)
                        break;
                    //////////////////////////try the rectangles here
                    pos[0]=a;
                    pos[1]=b;
                    pos[2]=c;
                    pos[3]=d;
                    tryRects();
                    /////////////////
                }
            }
        }
    }

}

void swap(int i){
    int temp;
    temp=rec[i][0];
    rec[i][0]=rec[i][1];
    rec[i][1]=temp;

}



int findLowestGood(){

    int lowest=9999;
    int lowestind;
    for(int i=0;i<gooddims.size();++i){
        if(gooddims[i]<lowest){
            lowest=gooddims[i];
            lowestind=i;
        }

    }
    return lowestind;

}



int main(){

    for(int i=0;i<4;++i){
        fin>>rec[i][0];
        fin>>rec[i][1];
    }
    //0000
    doPerms();
    //0001
    swap(0);
    doPerms();
    swap(0);
    //0010
    swap(1);
    doPerms();
    //0011
    swap(0);
    doPerms();
    swap(0);
    swap(1);
    //0100
    swap(2);
    doPerms();
    //0101
    swap(0);
    doPerms();
    swap(0);
    //0110
    swap(1);
    doPerms();
    //0111
    swap(0);
    doPerms();
    swap(0);
    swap(1);
    swap(2);
    //1000
    swap(3);
    doPerms();
    //1001
    swap(0);
    doPerms();
    swap(0);
    //1010
    swap(1);
    doPerms();
    //1011
    swap(0);
    doPerms();
    swap(0);
    swap(1);
    //1100
    swap(2);
    doPerms();
    //1101
    swap(0);
    doPerms();
    swap(0);
    //1110
    swap(1);
    doPerms();
    //1111
    swap(0);
    doPerms();

    int use;

    fout<<minarea<<endl;
    while(gooddims.size()!=0){
        use =  findLowestGood();
        fout<<gooddims[use]<<" "<<minarea/gooddims[use]<<endl;
        gooddims.erase(gooddims.begin()+use);
    }


    return 0;
}
