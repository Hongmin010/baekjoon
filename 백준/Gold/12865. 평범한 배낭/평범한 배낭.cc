#include<iostream>
#include<vector>
using namespace std;
int dp[100001][101];
pair<int,int> a[101];
int N,K;
int main(void){
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        cin>>a[i].first>>a[i].second;
    }
    for(int i=1;i<=K;i++){
        for(int j=1;j<=N;j++){
            if(a[j].first<=i){
                dp[i][j]=max(dp[i][j-1],dp[i-a[j].first][j-1]+a[j].second);
            }
            else dp[i][j]=dp[i][j-1];
        }
    }
    cout<<dp[K][N];
    return 0;
        }
    
    



