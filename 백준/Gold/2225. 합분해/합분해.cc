#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long dp(int,int);
int N,K;
long long arr[201][201];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    cout<<dp(N,K);
    return 0;
}

long long dp(int N,int K){
    if(K==1) return 1;
    if(N==0) return 1;
    if(arr[N][K]) return arr[N][K];
    for(int i=0;i<N+1;i++){
        arr[N][K]+=dp(N-i,K-1);
        arr[N][K]%=1000000000;
    }
    return arr[N][K];
}