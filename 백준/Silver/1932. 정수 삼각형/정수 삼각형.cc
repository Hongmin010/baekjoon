#include<iostream>
using namespace std;
void rec(int n);
int N;
int arr[501][501];
int dp[501][501];
int mx=0;
int main(void){
    cin>> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            cin>> arr[i][j];
        }
    }
    rec(1);
    cout<<mx;
    return 0;
}

void rec(int n){
    for(int i=1;i<=n;i++){
        dp[n][i]=max(dp[n-1][i-1],dp[n-1][i])+arr[n][i];
    }
    if(n==N){
        for(int i=1;i<=N;i++){
            if(mx<dp[N][i])mx=dp[N][i];
        }
        return;
    }
    rec(n+1);
}



