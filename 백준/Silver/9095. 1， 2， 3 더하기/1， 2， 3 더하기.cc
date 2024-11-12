#include<iostream>
using namespace std;

int a[12];
int dp(int n);
int main(void){
   int T,n;
   cin>>T;
   a[1]=1;
   a[2]=2;
   a[3]=4;
   for(int i=0;i<T;i++){
    cin>>n;
    cout<<dp(n)<<endl;
   }
    return 0;
}

int dp(int n){
    if(n==1 or n==2 or n==3) return a[n];
    else if(a[n]!=0) return a[n];
    a[n]= dp(n-3)+ dp(n-2)+ dp(n-1);
    return a[n];
    
}


