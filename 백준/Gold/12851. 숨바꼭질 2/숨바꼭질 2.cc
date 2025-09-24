#include<iostream>
#include<vector>
#include<queue>
using namespace std;
queue <pair<int,int>> que;
void bfs(int,int);
int visited[100001];
int visitnum[100001];
int dx[2]={-1,1};
int N,K,t=10000000,n=0;
int main(void){
    cin>>N>>K;
    bfs(N,K);
    cout<<t<<"\n"<<visited[K];
    return 0;
}



void bfs(int N,int K){
    pair<int,int> p=make_pair(N,0);
    que.push(p);
    visited[N]++;
    while(!que.empty()){
        p=que.front();
        que.pop();
        if(p.first==K){
            t=min(t,p.second);
        }
        if(p.first*2<=100000 and p.first*2>=0){
        if(visited[p.first*2])if(visitnum[p.first*2]==p.second+1)visited[p.first*2]+=visited[p.first];
        if(!visited[p.first*2]){
                visited[p.first*2]=visited[p.first];
                visitnum[p.first*2]=p.second+1;
                que.push(make_pair(p.first*2,p.second+1));
            } }
        for(int i=0;i<2;i++){ 
            if(p.first+dx[i]>100000 or p.first+dx[i]<0) continue;
            if(visited[p.first+dx[i]])if(visitnum[p.first+dx[i]]==p.second+1)visited[p.first+dx[i]]+=visited[p.first];
            if(!visited[p.first+dx[i]]){
                visited[p.first+dx[i]]=visited[p.first];
                visitnum[p.first+dx[i]]=p.second+1;
                que.push(make_pair(p.first+dx[i],p.second+1));
            }
        }
    }
    return;
}