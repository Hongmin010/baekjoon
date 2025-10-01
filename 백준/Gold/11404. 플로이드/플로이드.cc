#include <iostream>
using namespace std;

int n,m;
int arr[101][101];
int sol[101][101];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>m;
    int a,b,t;
    
    for(int i=0;i<m;i++){
        cin>>a>>b>>t;
        if(arr[a][b]==0) arr[a][b]=t;
        else if(arr[a][b]>t) arr[a][b]=t;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (i==j) sol[i][j]=0;
            else if(arr[i][j]>0) sol[i][j]=arr[i][j];
            else sol[i][j]=1000000000;
        }
    }
    for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
             if(sol[i][j]>sol[i][k]+sol[k][j]) sol[i][j]=sol[i][k]+sol[k][j];
        }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(sol[i][j]==1000000000) cout<<0<<" ";
            else cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }


    return 0;
}
