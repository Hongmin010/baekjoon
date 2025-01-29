#include<iostream>
#include<algorithm>
using namespace std;
int dp(int);
int* a;
int main(void){
    int N,n;
    cin >> N;
    a= new int[N+1];
    a[0]=0;
    a[1]=0;
    a[2]=1;
    a[3]=1;
    n=dp(N);
    cout<<n;
    delete a;
   return 0;
}

int dp(int N){
    if(N==0 or N==1 or N==2 or N==3) return a[N];
    if(a[N]!=0) return a[N];
    if(N%6==0){
        a[N]=min(dp(N-1),min(dp(N/2),dp(N/3)))+1;
        return a[N];}
    else if(N%3==0){
        a[N]=min(dp(N-1),dp(N/3))+1;
        return a[N];}
    else if(N%2==0){
        a[N]=min(dp(N-1),dp(N/2))+1;
        return a[N];}
    else { a[N]=dp(N-1)+1;
        return a[N];}
}

