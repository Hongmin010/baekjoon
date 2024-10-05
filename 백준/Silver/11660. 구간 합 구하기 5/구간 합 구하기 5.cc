#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int arr[1025][1025];
int dp[1025][1025];


int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int N,M;
   int a,b,c,d;
   cin>>N>>M;
   for(int i=1;i<N+1;i++){
    for(int j=1;j<N+1;j++){
        cin>>arr[i][j];
        dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+arr[i][j];
    }
   }
   for(int i=0;i<M;i++){
        cin>>a>>b>>c>>d;
        cout<<dp[c][d]-dp[c][b-1]-dp[a-1][d]+dp[a-1][b-1]<<"\n";
   }





    return 0;
}




