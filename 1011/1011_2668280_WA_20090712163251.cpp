﻿#include<iostream>
using namespace std;
int main(){
int i=1;
double p,q,s,x;
cin>>p>>q;
while(1){
i++;
x=i*p/100;
s=i*q/100;
if( (int)(x) < (int) (s) &&((int(s)!=s)||s-x>1)){
cout<<i;
return 0;
}
}
return 0;
}
