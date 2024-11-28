#include<iostream>
using namespace std;

int N;
int arr[501];
int dp[501][501];
int tmp[501][501];
int main(void){
    int T,mindp,mintmp;
    cin>>T;
    for(int K=0;K<T;K++){
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>arr[i];
            tmp[i][i]=arr[i];
        }
        for(int t=1;t<N;t++){
            for(int i=0;i<=N-t;i++){
                int j=i+t;
                mindp=100000000;
                for(int k=i;k<j;k++){
                    if(mindp>dp[i][k]+dp[k+1][j]+tmp[i][k]+tmp[k+1][j]){
                        mindp=dp[i][k]+dp[k+1][j]+tmp[i][k]+tmp[k+1][j];
                        mintmp=tmp[i][k]+tmp[k+1][j];
                    }
                    dp[i][j]=mindp;
                    tmp[i][j]=mintmp;
                }
            }
        }
   
    cout<<dp[0][N-1]<<"\n";
    
    }
    return 0;
}


