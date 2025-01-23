#include<iostream>
using namespace std;
int dfs(int,int);
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int N,M;
int D[501][501];
int dp[501][501];
int main(void){
    cin>>M>>N;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>D[i][j];
            dp[i][j]=-1;
        }
    }
    dp[M-1][N-1]=1;
    cout<<dfs(0,0);

    return 0;
}

int dfs(int a,int b){
    int x,y,num=0;
    if(dp[a][b]!=-1) return dp[a][b];
    for(int i=0;i<4;i++){
        y=a+dy[i];
        x=b+dx[i];
        if(y<0 or y>=M or x<0 or x>=N) continue;
        if(D[a][b]<=D[y][x]) continue;
        else num+=dfs(y,x);
    }
    dp[a][b]=num;
    return dp[a][b];
}


