/*
ID: tristan3
PROG: milk2
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

int main(){

	ifstream fin("milk2.in");
	ofstream fout("milk2.out");

	string at;
	int n;
	fin>>at;

	n=atoi(at.c_str());

	int times[n][2];
	int inarray[n][2];

	int now1,now2,last=0;
	int maxyes=0,maxno=0;

	for(int i=0;i<n;++i){//get input
		fin>>at;
		inarray[i][0]=atoi(at.c_str());
		fin>>at;
		inarray[i][1]=atoi(at.c_str());
	}

	//now sort dat input shit
	bool swapped=true;

	while(swapped && n!=1){
		swapped=false;
		for(int i=0;i<n-1;++i){
			if(inarray[i][0]>inarray[i+1][0]){
				swapped=true;
				now1=inarray[i][0];
				now2=inarray[i][1];
				inarray[i][0]=inarray[i+1][0];
				inarray[i][1]=inarray[i+1][1];
				inarray[i+1][0]=now1;
				inarray[i+1][1]=now2;
			}
		}
	}

	times[0][0]=inarray[0][0];
	times[0][1]=inarray[0][1];


	for(int i=1;i<n;++i){//consolidate overlapping times
		now1=inarray[i][0];
		now2=inarray[i][1];
		cout<<now1<<endl;
		if(now1<=times[last][1] && times[last][1]<=now2)
			times[last][1]=now2;
		else if(now1<=times[last][1] && times[last][1]>=now2)
			;
		else{
			last++;
			times[last][0]=now1;
			times[last][1]=now2;
		}
	}


	for(int i=0;i<=last;++i){
		if(times[i][1]-times[i][0]>maxyes)
			maxyes=times[i][1]-times[i][0];
		if(i>0 && times[i][0]-times[i-1][1]>maxno)
			maxno=times[i][0]-times[i-1][1];
	}

	fout<<maxyes<<" "<<maxno<<endl;

	return 0;
}
