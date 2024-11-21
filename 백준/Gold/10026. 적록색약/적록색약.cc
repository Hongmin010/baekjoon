#include<iostream>
using namespace std;
int dfs(int x,int y);
int rdfs(int x,int y);
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
char arr[101][101];
int visited[101][101];
int rvisited[101][101];
int N;
int main(void){
    int n=0,t=0; 
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(dfs(i,j)) n++;
            if(rdfs(i,j)) t++;
        }
    }
    cout<<n<<" "<<t;
    return 0;
}

int dfs(int x,int y){
    int nx,ny;
    if(x<0 or y<0 or x>N or y>N) return 0;
    if(visited[x][y]) return 0;
    visited[x][y]=1;
    for(int i=0;i<4;i++){
        nx=x+dx[i];
        ny=y+dy[i];
        if(arr[nx][ny]==arr[x][y]) dfs(nx,ny);
    }
return 1;
}

int rdfs(int x,int y){
    int nx,ny;
    if(x<0 or y<0 or x>N or y>N) return 0;
    if(rvisited[x][y]) return 0;
    rvisited[x][y]=1;
    for(int i=0;i<4;i++){
        nx=x+dx[i];
        ny=y+dy[i];
        if(arr[x][y]=='R' or arr[x][y]=='G') {
            if(arr[nx][ny]=='R' or arr[nx][ny]=='G') rdfs(nx,ny);
        }
        else if(arr[nx][ny]=='B') rdfs(nx,ny);
    }
return 1;
}

