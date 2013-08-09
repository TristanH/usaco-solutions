/*
ID: tristan3
PROG: friday
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int daysIn(int month, int year){

	switch(month){
	case 9:
	case 4:
	case 6:
	case 11:
		return 30;
	case 2:
		if(year%4==0 && year%100!=0 || year%400==0)
			return 29;
		else
			return 28;
	default:
		return 31;
	}
}


int main2() {

	ifstream fin("friday.in");
	ofstream fout("friday.out");

	int n;
	fin>>n;

	int day=1; //1 is mon, 0 is sun, 2 is tues
	int thirDay[] = {0,0,0,0,0,0,0};


	for(int year=1900;year<1900+n;++year){
		for(int month=1;month<=12;++month){
			thirDay[(day+12)%7]++;
			day+=daysIn(month,year);
		}

	}

	fout<<thirDay[6];
	for(int i=0;i<6;++i)
		fout<<" "<<thirDay[i];
	fout<<"\n";

	fout.close();

	return 0;
}
