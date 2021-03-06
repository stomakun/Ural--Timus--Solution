﻿#include <stdio.h>
int h1[65536],l1=30000,h2[65536],l2=0,m[65536]={0},p2[65536];
int ms(){
    int s;
    char c;
    do{
      c=getchar();
    }while(c!=-1&&(c<48||c>57));
	if(c==-1)return -1;
    s=c-48;
    while(1){
      c=getchar();
      if(c<48||c>57)break;
      s=s*10+c-48;
    }
    return s;
}
void mp(int s){
     char b[12];
     int l=0,i;
     if(s==0){
       putchar(48);
       return;
     }
     while(s){
       b[l]=s%10;
       l++;
       s/=10;
     }
     for(i=l-1;i>=0;i--)putchar(b[i]+'0');
}
void add1(int a){
	int now=l1;
	while(now>0&&a<h1[(now-1)>>1]){
		h1[now]=h1[(now-1)>>1];
		now=(now-1)>>1;
	}
	h1[now]=a;
	l1++;
}
int get1(){
	int now=0,dest,r=h1[0];
	l1--;
	while(l1>(now<<1)+1){
		if(l1==(now<<1)+2)dest=(now<<1)+1;
		else if(h1[(now<<1)+1]<h1[(now<<1)+2])dest=(now<<1)+1;
		else dest=(now<<1)+2;
		if(h1[l1]<=h1[dest])break;
		h1[now]=h1[dest];
		now=dest;
	}
	h1[now]=h1[l1];
	return r;
}
void add2(int a){
	int now=l2;
	while(now>0&&m[a]<m[h2[(now-1)>>1]]){
		h2[now]=h2[(now-1)>>1];
		p2[h2[now]]=now;
		now=(now-1)>>1;
	}
	h2[now]=a;
	p2[a]=now;
	l2++;
}
void adj2(int a){
	int now=p2[a],dest,t;
	while(l2>(now<<1)+1){
		if(l2==(now<<1)+2)dest=(now<<1)+1;
		else if(m[h2[(now<<1)+1]]<m[h2[(now<<1)+2]])dest=(now<<1)+1;
		else dest=(now<<1)+2;
		if(m[h2[now]]<=m[h2[dest]])break;
		t=h2[now];
		h2[now]=h2[dest];
		h2[dest]=t;
		p2[h2[dest]]=dest;
		p2[h2[now]]=now;
		now=dest;
	}
}
int get2(){
	int r=h2[0];
	l2--;
	if(l2==0)return r;
	h2[0]=h2[l2];
	p2[h2[0]]=0;
	adj2(h2[0]);
	return r;
}
int main(){
	int i,a,b,t;
	char s;
	for(i=0;i<30000;i++)h1[i]=i+1;
	while((a=ms())!=-1){
		do{
			s=getchar();
		}while(s!='+'&&s!='.');
		while(l2>0&&m[h2[0]]<a){
			t=get2();
			m[t]=0;
			add1(t);
		}
		if(s=='+'){
			t=get1();
			mp(t);
			putchar('\n');
			m[t]=a+599;
			add2(t);
		}else{
			b=ms();
			if(m[b]==0){putchar('-');putchar('\n');}
			else{
				putchar('+');putchar('\n');
				m[b]=a+599;
				adj2(b);
			}
		}
	}
	return 0;
}
