#include<iostream>
#include<vector>
#include<queue>
using namespace std;
queue <pair<pair<int,int>,int>> que;
void bfs(void);
int arr[1000][1000];
int visited[1000][1000][2];
int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};
int N,M,ans=-1;
int main(void){
    cin>>N>>M;
    char t;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>t;
            arr[i][j]=t-'0';
        }
    }
    bfs();
    cout<<ans;
    return 0;
}



void bfs(void){
    pair<pair<int,int>,int> p={{0,0},0};
    visited[0][0][0]=1;
    que.push(p);
    while(!que.empty()){
        p=que.front();
        que.pop();
        if(p.first.first==N-1 and p.first.second==M-1){
            ans=visited[N-1][M-1][p.second];
            return;
        }
        for(int i=0;i<4;i++){
            int ny=p.first.first+dy[i];
            int nx=p.first.second+dx[i];
            int broke=p.second;
            if(ny>=N or ny<0 or nx>=M or nx<0) continue;
            if(visited[ny][nx][broke]) continue;
            if(!broke and arr[ny][nx] and !visited[ny][nx][1]){
                visited[ny][nx][1]=visited[ny-dy[i]][nx-dx[i]][0]+1;
                que.push({{ny,nx},1});
            }
            if(arr[ny][nx]) continue;
            visited[ny][nx][broke]=visited[ny-dy[i]][nx-dx[i]][broke]+1;
            que.push({{ny,nx},broke});
        }
            
        
    }
    return;
}