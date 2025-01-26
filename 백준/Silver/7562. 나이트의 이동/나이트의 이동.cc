#include<iostream>
#include<queue>
#include<vector>
void knight(void);
using namespace std;
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int N,l,nx,ny,num=0;
pair<pair<int,int>,int>a;
pair<int,int>b;
pair<pair<int,int>,int>tmp;
queue<pair<pair<int,int>,int>>que;
bool visited[300][300];
int main(void){
   cin>>N;
   for(int i=0;i<N;i++){
    knight();
   }
    return 0;
}

void knight(void){
    queue<pair<pair<int,int>,int>>que;
    cin>>l;
    cin>>a.first.first>>a.first.second;
    cin>>b.first>>b.second;
    if(a.first.first==b.first and a.first.second==b.second) {cout<<"0"<<endl;
    return;}
    que.push(a);
    visited[a.first.second][a.first.first]=true;
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            visited[i][j]=false;
        }
    }
    while(!que.empty()){
        tmp.first.first=que.front().first.first;
        tmp.first.second=que.front().first.second;
        num=que.front().second;
        que.pop();
        for(int i=0;i<8;i++){
            nx=tmp.first.first+dx[i];
            ny=tmp.first.second+dy[i];
            if(nx<0 or nx>=l or ny<0 or ny>=l) continue;
            else if(visited[ny][nx]) continue;
            if(nx==b.first and ny==b.second){ 
                cout<<num+1<<endl;
                return;
            }
            visited[ny][nx]=true;
            que.push(make_pair(make_pair(nx,ny),num+1));
        }
    }
    return;
}
    



