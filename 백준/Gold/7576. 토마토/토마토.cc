#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int M,N,num,nx,ny;
int arr[1000][1000];
bool visited[1000][1000];
vector<pair<int,int>>a;
queue<pair<pair<int,int>,int>>que;
pair<pair<int,int>,int>tmp;
int main(void){
    cin>>M>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1) a.push_back(make_pair(i,j));
            if(arr[i][j]==-1) visited[i][j]=true;
        }
    }
    for(int i=0;i<a.size();i++){
        que.push(make_pair(make_pair(a[i].first,a[i].second),0));
        visited[a[i].first][a[i].second]=true;
    }
    while(!que.empty()){
        tmp.first.first=que.front().first.first;
        tmp.first.second=que.front().first.second;
        num=que.front().second;
        que.pop();
        for(int i=0;i<4;i++){
            nx=tmp.first.second+dx[i];
            ny=tmp.first.first+dy[i];
            if(nx<0 or nx>=M or ny<0 or ny>=N) continue;
            else if(visited[ny][nx]) continue;
            visited[ny][nx]=true;
            que.push(make_pair(make_pair(ny,nx),num+1));
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j]==false) {
            cout<<"-1";
            return 0;
            }
        }
    }
    cout<<num;
    return 0;
    }
    
    



