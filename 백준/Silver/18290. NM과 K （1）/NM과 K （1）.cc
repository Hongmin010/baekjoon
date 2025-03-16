#include<iostream>
using namespace std;
void nmk(int n);
int N,M,K;
int ans=-1000000,tmp=0;
int arr[12][12];
bool visited[12][12];
int main(void){
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>arr[i][j];
        }
    }
    nmk(0);
    cout<<ans;
    return 0;
}

void nmk(int n){
    if(n==K){ 
        if(ans<tmp) ans=tmp;
        return;
    }
    
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(visited[i][j] or visited[i-1][j] or visited[i+1][j] or visited[i][j-1] or visited[i][j+1])continue;
            visited[i][j]=true;
            tmp+=arr[i][j];
            nmk(n+1);
            tmp-=arr[i][j];
            visited[i][j]=false;
        }
    }

}



