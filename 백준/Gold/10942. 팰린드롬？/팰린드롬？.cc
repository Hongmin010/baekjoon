#include<iostream>
using namespace std;
int pal(int S,int E);
int arr[2001];
int dp[2001][2001];
int N,M,S,E;
int main(void){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    cin>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<M;i++){
        cin>>S>>E;
        cout<<pal(S,E)<<"\n";
    }

    return 0;
}

int pal(int S,int E){
    if(dp[S][E]>-1) return dp[S][E];
    if(S==E){
        dp[S][E]=1;
        return dp[S][E];
    }
    if(E==S+1){
        if(arr[S]==arr[E]){
            dp[S][E]=1;
            return dp[S][E];
        }
        else{
            dp[S][E]=0;
            return dp[S][E];
        }
    } 
    dp[S][E]=pal(S+1,E-1)*(arr[S]!=arr[E]?0:1);
    return dp[S][E];
}
