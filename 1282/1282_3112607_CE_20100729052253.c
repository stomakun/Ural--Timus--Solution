﻿#include <stdio.h>
#include <stdlib.h>
struct Edge{
int to;
struct Edge *next;
}*edg[1100]={0};
int l[1100],f[1100];
int go(int p,int w){
int yy=0,yp=0,t;
struct Edge *e=edg[p];
if(f[p]!=2)return f[p];
if(w==0)return l[p];
while(p){
t=go(p->to,-w);
if(t==w)yy=0;
if(t==0)yp=0;
p=p->next;
}
if(yy)return f[p]=w;
if(yp)return f[p]=0;
return f[p]=-w;
}
int main(){
int n,a,i;
char s[5];
struct Edge *w;
for(i=0;i<1100;i++)f[i]=2;
scanf("%d",&n);
for(i=2;i<=n;i++){
scanf("%s %d",s,&a);
if(s[0]=='L')scanf("%d",&l[i]);
w=malloc(8);
w->to=i;
w->next=edg[a];
edg[a]=w;
}
go(1,1);
if(f[1]==1)printf("+");
printf(f[1]);
}



