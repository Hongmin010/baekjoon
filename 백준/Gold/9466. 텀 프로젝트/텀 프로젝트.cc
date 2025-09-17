#include<iostream>
using namespace std;
bool dfs(int n);
int cyc=-1,tmp=0;
int T,n,ans=0;
int arr[100001];
bool visited[100001];
bool ok[100001];
int main(void){
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        for(int k=1;k<=n;k++){
            cin>>arr[k];
        }
        for(int k=1;k<=n;k++){
            dfs(k);
            tmp=0;
        }
        cout<<n-ans<<endl;
        ans=0;
        for(int k=1;k<=n;k++){
            ok[k]=false;
            visited[k]=false;
        }
    }
    return 0;
}

bool dfs(int n){
    if(ok[n]) return false;
    if(visited[n]){
        ok[n]=true;
        cyc=n;
        tmp++;
        return true;
    }
    visited[n]=true;
    if(dfs(arr[n])) {
        if(n==cyc) {
            ans+=tmp;
            return false;
        }
        else {
            tmp++;
            return true;
        }
    }
    return false;
}
