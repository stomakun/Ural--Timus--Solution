﻿#include <stdio.h>
int main(){
    int s,a,b,c,d,e,f,g,h,n=0,y;
    scanf("%d",&s);
    for(a=0;a<10;a++){
      y=a;
      for(b=0;b<10;b++){
        y+=b;
        for(c=0;c<10;c++){
          y+=c;
          for(d=0;d<10;d++){
            y+=d;
            for(e=0;e<10;e++){
              y+=e;
              for(f=0;f<10;f++){
                y+=f;
                for(g=0;g<10;g++){
                  y+=g;
                  for(h=0;h<10;h++){
                    y+=h;
                    if(s-y>=0&&s-y<=9)n++;
                    y-=h;
                  }
                  y-=g;
                }
                y-=f;
              }
              y-=e;
            }
            y-=d;
          }
          y-=c;
        }
        y-=b;
      }
      y-=a;
    }
    if(s==1)n++;
    printf("%d",n);
}
