#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M,num=0;
int islandNum=1;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int map[101][101];
bool visited[101][101];
int islandNumMap[101][101];
int islandDistance[7][7];
int parent[7];
int result;
vector<pair<int,pair<int,int>>>v;

int getParent(int x) {
    if(parent[x]!=x) parent[x]=getParent(parent[x]);
    return parent[x];
}
void unionParent(int a, int b) {
    a=getParent(a);
    b=getParent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

bool dfs(int x,int y){
    if(visited[x][y]) return false;
    visited[x][y]=true;
    islandNumMap[x][y]=islandNum;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 or nx>=N or ny<0 or ny>=M) continue;
        if(!map[nx][ny]) continue;
        dfs(nx,ny);
    }  
    return true;  
}

void findDistance(int x, int y){
    if(!map[x][y]) return;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        int distance=0;
        while(1){
            if(nx<0 or nx>=N or ny<0 or ny>=M) break;
            if(islandNumMap[nx][ny]>0) break;
            nx+=dx[i];
            ny+=dy[i];
            distance++;
        }
        if(distance<2) continue;
        if(nx<0 or nx>=N or ny<0 or ny>=M) continue;
        if (islandNumMap[nx][ny] == 0) continue;
        int startNumber=islandNumMap[x][y];
        int endNumber=islandNumMap[nx][ny];
        islandDistance[startNumber][endNumber]=min(islandDistance[startNumber][endNumber],distance);
        islandDistance[endNumber][startNumber]=islandDistance[startNumber][endNumber];
    }    
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b,c;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]){
                if(dfs(i,j)) islandNum++;
        }}
    }
    for(int i=1; i<7; i++){
        for(int j=1; j<7; j++){
            islandDistance[i][j] = 10000000;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            findDistance(i,j);
        }
    }
    for(int i=1;i<islandNum;i++){
        for(int j=i+1;j<islandNum;j++){
            if (islandDistance[i][j] != 10000000) {
            v.push_back({islandDistance[i][j],{i,j}});
            }
        }
    }
    sort(v.begin(),v.end());
    for(int i=1;i<islandNum;i++){
        parent[i]=i;
    }
    for(int i=0;i<v.size();i++){
            int cost=v[i].first;
            int a=v[i].second.first;
            int b=v[i].second.second;
            if(getParent(a)!=getParent(b)){
                unionParent(a,b);
                result+=cost;
                num++;
            }
        }
    if(num!=islandNum-2){
        cout<<-1;
        return 0;
    }
    cout<<result;
    return 0;
}

