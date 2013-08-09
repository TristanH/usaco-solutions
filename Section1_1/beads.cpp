/*
ID: tristan3
PROG: beads
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int usedUp=0;

int numLeft(string in, int index){
	int added=0;
	char compareTo='!';

	for(int i=index-1;added<in.length()-usedUp;--i){
		if(i==-1)
			i=in.length()-1;//loop around the necklace

		if(compareTo=='!' && in[i]!='w') {     //take the first bead from the cut to compare to
			compareTo=in[i];
			added++;
		}
		else{
			if(compareTo==in[i] || in[i]=='w'){
				added++;
			}
			else
				break;

		}
	}
	usedUp+=added;
	return added;
}

int numRight(string in, int index){
	int added=0;
	char compareTo='!';

	for(int i=index;added<in.length()-usedUp;++i){
		if(i==in.length())
			i=0;//loop around the necklace

		if(compareTo=='!' && in[i]!='w') {     //take the first bead from the cut to compare to
			compareTo=in[i];
			added++;
		}
		else{
			if(compareTo==in[i] || in[i]=='w'){
				added++;
			}
			else
				break;

		}
	}
	usedUp+=added;
	return added;
}



int main5(){

	ifstream fin("beads.in");
	ofstream fout("beads.out");

	string in;
	string nothing;
	fin>>nothing;
	fin>>in;
	int now;
	int best=-1;

	for(int i=0;i<in.length();++i){
		now=numLeft(in,i)+numRight(in,i);

		if(now>best)
			best=now;
		usedUp=0;

		now=numRight(in,i)+numLeft(in,i);

		if(now>best)
			best=now;

		usedUp=0;
	}

	fout<<best<<"\n";


}


