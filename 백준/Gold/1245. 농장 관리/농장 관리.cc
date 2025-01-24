#include<iostream>
using namespace std;
bool dfs(int,int);
int dx[8]={-1,1,0,0,-1,1,-1,1};
int dy[8]={0,0,-1,1,1,1,-1,-1};
int N,M,num=0;
int D[100][70];
bool visited[100][70];
int main(void){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>D[i][j];
            visited[i][j]=false;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(dfs(i,j)){
                num++;
            }
        }
    }
    cout<<num;
    return 0;
}

bool dfs(int a,int b){
    if (visited[a][b]) return false;
    int x,y;
    bool s=false;
    visited[a][b]=true;
    for(int i=0;i<8;i++){
        y=a+dy[i];
        x=b+dx[i];
        if(y<0 or y>=N or x<0 or x>=M) continue;
        if(D[a][b]<D[y][x]) s=true;
        if(D[a][b]==D[y][x] and !(visited[y][x])){
            if(!dfs(y,x)) s=true;
        }
    }
    if(s) return false;
    return true;
}


