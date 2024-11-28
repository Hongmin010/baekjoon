#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int N,M;
char ch;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int arr[101][101];
bool visited[101][101];
int main(void){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>ch;
            arr[i][j]=ch-'0';
        }
    }
    queue<pair<pair<int,int>,int>> a;
    pair<int,int>n;
    a.push(make_pair(make_pair(1,1),1));
    visited[1][1]=true;
    int k;
    while(!a.empty()){
        n.first=a.front().first.first;
        n.second=a.front().first.second;
        k=a.front().second;
        if(n.first==N and n.second==M){
            cout<<k;
            break;
        }
        a.pop();
        for(int i=0;i<4;i++){
            int nx=n.first+dx[i];
            int ny=n.second+dy[i];
            if(nx<1 or ny<1 or nx>N or ny>M) continue;
            if(visited[nx][ny]==false and arr[nx][ny]==1){
                a.push(make_pair(make_pair(nx,ny),k+1));
                visited[nx][ny]=true;
                }
        }



    }


    return 0;
}


