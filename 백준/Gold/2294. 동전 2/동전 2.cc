#include<iostream>
#include<algorithm>
using namespace std;
int arr[101];
int dp[10001];
int rec(int K);
int N,K;
int main(void){
    cin>>N>>K;
    for(int i=0;i<=K;i++){
        dp[i]=-1;
    }
    for(int i=0;i<N;i++){
        cin>>arr[i];
        if(arr[i]<10001) dp[arr[i]]=1;
    }
    if(rec(K)<100000) cout<<dp[K];
    else cout<<"-1";
    



    return 0;
}

int rec(int K){
    if(dp[K]>=100000) return 100000;
    if(dp[K]!=-1) return dp[K];
    int n=100000;
    for(int i=0;i<N;i++){
        if(K-arr[i]<0) continue;
        if(n>rec(K-arr[i])) n=dp[K-arr[i]];
    }
    dp[K]=n+1;
    return dp[K];
}

