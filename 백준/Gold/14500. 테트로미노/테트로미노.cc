#include<iostream>
using namespace std;
int N,M;
int mx=0;
int arr[512][512];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin>>N>>M;
    for(int i=4;i<N+4;i++){
        for(int j=4;j<M+4;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=4;i<N+4;i++){
        for(int j=4;j<M+4;j++){
            mx=max(mx,arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i][j+3]); // ㅡ
            mx=max(mx,arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+3][j]); // ㅣ
            mx=max(mx,arr[i][j]+arr[i+1][j]+arr[i][j+1]+arr[i+1][j+1]); // ㅁ
            mx=max(mx,arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+2][j+1]); // ㄴ
            mx=max(mx,arr[i][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+2][j+1]); // ㄱ
            mx=max(mx,arr[i][j]+arr[i][j+1]+arr[i+1][j]+arr[i+2][j]); // r
            mx=max(mx,arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+2][j-1]); // j
            mx=max(mx,arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i+2][j+1]); // 
            mx=max(mx,arr[i][j]+arr[i+1][j]+arr[i+1][j-1]+arr[i+2][j-1]);
            mx=max(mx,arr[i][j]+arr[i-1][j]+arr[i][j-1]+arr[i+1][j]); // ㅓ
            mx=max(mx,arr[i][j]+arr[i-1][j]+arr[i][j+1]+arr[i+1][j]); //ㅏ
            mx=max(mx,arr[i][j]+arr[i-1][j]+arr[i][j-1]+arr[i][j+1]); // ㅗ
            mx=max(mx,arr[i][j]+arr[i+1][j]+arr[i][j-1]+arr[i][j+1]); // ㅜ
            mx=max(mx,arr[i][j]+arr[i+1][j]+arr[i][j+1]+arr[i][j+2]); // 
            mx=max(mx,arr[i][j]+arr[i+1][j]+arr[i+1][j-1]+arr[i+1][j-2]); // 
            mx=max(mx,arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+2]); // 
            mx=max(mx,arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2]); // 
            mx=max(mx,arr[i][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+1][j+2]); 
            mx=max(mx,arr[i][j+1]+arr[i][j+2]+arr[i+1][j]+arr[i+1][j+1]);
        }
    }
    cout<<mx;
    return 0;
}

