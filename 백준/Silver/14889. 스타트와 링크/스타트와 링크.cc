#include<iostream>
#include<vector>
using namespace std;
void NM(int ,int);
int N,ans=1000000,as=0,bs=0;
bool visited[21];
vector<int> a;
vector<int> b;
int map[21][21];
int main(void){
    cin>>N;
    for(int i=1;i<N+1;i++){
        for(int j=1;j<N+1;j++){
            cin>>map[i][j];
        }
    }
    NM(0,0);
    cout<<ans;
    
    return 0;
}

void NM(int cnt,int t){
    if(cnt==N/2){
        for(int i=1;i<N+1;i++){
            if(visited[i])a.push_back(i);
            else b.push_back(i);
        }
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                as=as+map[a[i]][a[j]]+map[a[j]][a[i]];
            }
        }
        for(int i=0;i<b.size();i++){
            for(int j=i+1;j<b.size();j++){
                bs=bs+map[b[i]][b[j]]+map[b[j]][b[i]];
            }
        }
        if(abs(as-bs)<ans)ans=abs(as-bs);
        as=0;
        bs=0;
        a.clear();
        b.clear();
        return;
    }
    for(int i=t+1;i<=N;i++){
        if(!visited[i]){
            visited[i]=true;
            NM(cnt+1,i);
            visited[i]=false;
        }
    }
    
    
}