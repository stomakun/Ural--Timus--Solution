﻿#include <stdio.h>
int main(){
int m,n,i,j,in,y[1010],p[1010],mv,mi,m[1010]={1};
scanf("%d%d",&n,&m);
if(m>n){puts("NO");return 0;}
m[n+1]=1;
for(i=0;i<m;i++){
scanf("%d",&in);
if(in>n){put("NO");return 0;}
y[i]=in;
}
for(i=0;i<m;i++){
mv=20000;
for(j=0;j<m;j++){
if(y[i]<mv){
mv=y[j];
mi=j;
}
}
p[i]=mv;
p[mi]=20000;
}
for(i=0;i<m;i++){
if(m[p[i]]==0)m[p[i]]=0;
if(m[p[i]+1]==0)m[p[i]+1]=0;
else{puts("NO");return 0;}
}
puts("YES");
}
