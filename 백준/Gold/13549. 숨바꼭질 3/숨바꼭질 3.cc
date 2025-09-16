#include<iostream>
#include<vector>
#include<queue>
using namespace std;
queue <pair<int,int>> que;
void bfs(int,int);
bool visited[100001];
int dx[2]={-1,1};
int N,K;
int main(void){
    cin>>N>>K;
    bfs(N,K);
    return 0;
}



void bfs(int N,int K){
    pair<int,int> p=make_pair(N,0);
    que.push(p);
    visited[N]=true;
    while(!que.empty()){
        p=que.front();
        que.pop();
        if(p.first==K){
            cout<<p.second;
            return;
        }
        if(p.first*2<=100000 and p.first*2>=0){
        if(!visited[p.first*2]){
                visited[p.first*2]=true;
                que.push(make_pair(p.first*2,p.second));
            } }
        for(int i=0;i<2;i++){
            if(p.first+dx[i]>100000 or p.first+dx[i]<0) continue;
            if(!visited[p.first+dx[i]]){
                visited[p.first+dx[i]]=true;
                que.push(make_pair(p.first+dx[i],p.second+1));
            }
        }
    }
    return;
}