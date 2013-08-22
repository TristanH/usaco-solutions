/*
ID: tristan3
PROG: rect1
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
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp,*fo;
struct rect{
    int c; int x1,y1,x2,y2;}

    ;
    int c[2501];
    rect r[10001];
    int intersect(rect a,const rect &b,rect out[4]){
         /* do they at all intersect? */
         if(b.x2<a.x1||b.x1>=a.x2) return 0;
          if(b.y2<a.y1||b.y1>=a.y2) return 0;
           /* they do */
            rect t; if(b.x1<=a.x1&&b.x2>=a.x2&&b.y1<=a.y1&&b.y2>=a.y2) return -1;
            /* cutting `a' down to match b */
            int nout=0; if(b.x1>=a.x1)
            { t=a,t.x2=b.x1;
            if(t.x1!=t.x2) out[nout++]=t; a.x1=b.x1;
             }
             if(b.x2<a.x2) {
                 t=a,t.x1=b.x2;
                 if(t.x1!=t.x2)
                 out[nout++]=t;
                 a.x2=b.x2;
            }
            if(b.y1>=a.y1) {
                t=a,t.y2=b.y1;
                 if(t.y1!=t.y2)
                    out[nout++]=t; a.y1=b.y1;
            } if(b.y2<a.y2) {
                t=a,t.y1=b.y2;
                 if(t.y1!=t.y2) out[nout++]=t; a.y2=b.y2;
                 }
                 return nout;}

                 int main() {
                      fp=fopen("rect1.in","rt");
                       fo=fopen("rect1.out","wt");
                        int a,b,n; fscanf(fp,"%d %d %d",&a,&b,&n);
                         r[0].c=1; r[0].x1=r[0].y1=0;
                         r[0].x2=a; r[0].y2=b;
                         rect t[4]; int i,j,rr=1;
                         for(i=0;i<n;i++) {
                             int tmp;
                         fscanf(fp,"%d %d %d %d %d",&r[rr].x1,&r[rr].y1,&r[rr].x2,&r[rr].y2,&r[rr].c); if(r[rr].x1>r[rr].x2) { tmp=r[rr].x1; r[rr].x1=r[rr].x2; r[rr].x2=tmp; }
                         if(r[rr].y1>r[rr].y2) {
                             tmp=r[rr].y1; r[rr].y1=r[rr].y2;
                              r[rr].y2=tmp;
                        }
                         int nr=rr;
                         rect curr=r[rr++];
                         for(j=0;j<nr;j++) {
                             int n=intersect(r[j],curr,t);
                              if(!n) continue; if(n==-1) {
                                   memmove(r+j,r+j+1,sizeof(rect)*(rr-j-1));
                                    j--; rr--; nr--;
                                    continue;
                            }
                            r[j]=t[--n];
                             for(;n-->0;) r[rr++]=t[n]; } }
                              for(i=0;i<rr;i++)
                              c[r[i].c]+=(r[i].x2-r[i].x1)*(r[i].y2-r[i].y1);
                               for(i=1;i<=2500;i++)
                                if(c[i]) fprintf(fo,"%d %d\n",i,c[i]);

                            return 0;}
