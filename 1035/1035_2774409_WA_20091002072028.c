﻿#include <stdio.h>
int n,m,tot=0,ql[2],q[2][40000][2],on;
char z[210][210],f[210][210],mark[210][210]={0};
int main(){
    int i,j,k,tx,ty,cz,cf,tc,c,yl;
    scanf("%d%d\n",&n,&m);
    for(i=0;i<n;i++)gets(z[i]);
    for(i=0;i<n;i++)gets(f[i]);
    for(i=0;i<=n;i++)for(j=0;j<=m;j++){
      if(mark[i][j])continue;
      ql[1]=on=c=yl=0;
      ql[0]=1;
      q[0][0][0]=i;
      q[0][0][1]=j;
      mark[i][j]=1;
      while(ql[on]>0){
        ql[!on]=0;
        yl++;
        for(k=0;k<ql[on];k++){
          tx=q[on][k][0];
          ty=q[on][k][1];
          cz=cf=0;
          if(tx>0&&ty>0&&(z[tx-1][ty-1]=='\\'||z[tx-1][ty-1]=='X')){
            cz++;
            if(mark[tx-1][ty-1]==0){
              mark[tx-1][ty-1]=1;
              q[!on][ql[!on]][0]=tx-1;
              q[!on][ql[!on]][1]=ty-1;
              ql[!on]++;
            }
          }
          if(tx>0&&ty>0&&(f[tx-1][ty-1]=='\\'||f[tx-1][ty-1]=='X')){
            cf++;
            if(mark[tx-1][ty-1]==0){
              mark[tx-1][ty-1]=1;
              q[!on][ql[!on]][0]=tx-1;
              q[!on][ql[!on]][1]=ty-1;
              ql[!on]++;
            }
          }
          if(tx<n&&ty>0&&(z[tx][ty-1]=='/'||z[tx][ty-1]=='X')){
            cz++;
            if(mark[tx+1][ty-1]==0){
              mark[tx+1][ty-1]=1;
              q[!on][ql[!on]][0]=tx+1;
              q[!on][ql[!on]][1]=ty-1;
              ql[!on]++;
            }
          }
          if(tx<n&&ty>0&&(f[tx][ty-1]=='/'||f[tx][ty-1]=='X')){
            cf++;
            if(mark[tx+1][ty-1]==0){
              mark[tx+1][ty-1]=1;
              q[!on][ql[!on]][0]=tx+1;
              q[!on][ql[!on]][1]=ty-1;
              ql[!on]++;
            }
          }
          if(tx>0&&ty<m&&(z[tx-1][ty]=='/'||z[tx-1][ty]=='X')){
            cz++;
            if(mark[tx-1][ty+1]==0){
              mark[tx-1][ty+1]=1;
              q[!on][ql[!on]][0]=tx-1;
              q[!on][ql[!on]][1]=ty+1;
              ql[!on]++;
            }
          }
          if(tx>0&&ty<m&&(f[tx-1][ty]=='/'||f[tx-1][ty]=='X')){
            cf++;
            if(mark[tx-1][ty+1]==0){
              mark[tx-1][ty+1]=1;
              q[!on][ql[!on]][0]=tx-1;
              q[!on][ql[!on]][1]=ty+1;
              ql[!on]++;
            }
          }
          if(tx<n&&ty<m&&(z[tx][ty]=='\\'||z[tx][ty]=='X')){
            cz++;
            if(mark[tx+1][ty+1]==0){
              mark[tx+1][ty+1]=1;
              q[!on][ql[!on]][0]=tx+1;
              q[!on][ql[!on]][1]=ty+1;
              ql[!on]++;
            }
          }
          if(tx<n&&ty<m&&(f[tx][ty]=='\\'||f[tx][ty]=='X')){
            cf++;
            if(mark[tx+1][ty+1]==0){
              mark[tx+1][ty+1]=1;
              q[!on][ql[!on]][0]=tx+1;
              q[!on][ql[!on]][1]=ty+1;
              ql[!on]++;
            }
          }
          tc=cz-cf;
          c+=tc;
        }
        on=!on;
      }
      if(c<0)c=-c;
      if(c==0)c=2;
      if(yl>1)tot+=c/2;
    }
    printf("%d",tot);
}
